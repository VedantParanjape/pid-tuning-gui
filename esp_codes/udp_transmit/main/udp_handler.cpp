#include "udp_handler.h"

network_manager::network_manager()
{
    dest_addr.sin_addr.s_addr = inet_addr(HOST_IP_ADDR);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    addr_family = AF_INET;
    ip_protocol = IPPROTO_IP;
    inet_ntoa_r(dest_addr.sin_addr, addr_str, sizeof(addr_str) - 1);

    sock = socket(addr_family, SOCK_DGRAM, ip_protocol);
    if (sock < 0)
    {
        ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
    }
    ESP_LOGI(TAG, "Socket created, connected to %s:%d", HOST_IP_ADDR, PORT);
}

int network_manager::send_data(char* payload)
{
    int err = sendto(sock, payload, strlen(payload), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err < 0) 
    {
        ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
    }
    ESP_LOGI(TAG, "Message sent");

    return err;
}

char* network_manager::recieve_data()
{
    struct sockaddr_in source_addr;
    socklen_t socklen = sizeof(source_addr);
    int len = recvfrom(sock, rx_buffer, sizeof(rx_buffer) - 1, 0, (struct sockaddr *)&source_addr, &socklen);

    if (len < 0) 
    {
        ESP_LOGE(TAG, "recvfrom failed: errno %d", errno);
        return NULL;
    }
    else
    {
        rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string
        ESP_LOGI(TAG, "Received %d bytes from %s:", len, addr_str);
        ESP_LOGI(TAG, "%s", rx_buffer);
        return rx_buffer;
    }
}

network_manager::~network_manager()
{
    ESP_LOGE(TAG, "Shutting down socket");
    shutdown(sock, 0);
    close(sock);
}