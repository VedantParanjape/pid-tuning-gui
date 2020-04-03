# This example code is in the Public Domain (or CC0 licensed, at your option.)

# Unless required by applicable law or agreed to in writing, this
# software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
# CONDITIONS OF ANY KIND, either express or implied.

# -*- coding: utf-8 -*-

import socket
import sys
import time, datetime
import json
from server.tcp import tcp_server
from server.udp import udp_server
import random

# -----------  Config  ----------
family_addr = socket.AF_INET
TCP_PORT = 5000
UDP_PORT = 1212
# -------------------------------

# -----------  Data  ------------
buffer_size = 150

pid_data = {
    "Kp":0.0,
    "Ki":0.0,
    "Kd":0.0,
    "SetPoint":0.0
}

terms = {
    "P":0.0,
    "I":0.0,
    "D":0.0,
    "Current":0.0,
    "Error":0.0
}
# -------------------------------

def main():
    # tcp_sock = socket.socket()
    # tcp_sock.connect(('', TCP_PORT))
    tcp_handle = tcp_server(TCP_PORT)
    tcp_handle.run(True)

    udp_handle = udp_server(UDP_PORT)
    # udp_handle.run(True)

    error = 0

    while True:
        err = udp_handle.send_data(json.dumps(terms).encode(), ('', UDP_PORT))
        if err:
            print("Error in UDP sending: " + str(err))
        # else:
        #     print("Sent")

        # print(tcp_handle.print_message_pipe())
        # print("*******************")
        # try:
        #     tcp_data = tcp_handle.recv_data(buffer_size)

        #     print(tcp_data)
        #     if tcp_data:
        #         # Send to appropriate function
        #         tcp_data = json.loads(tcp_data)
        #         pid_data['Kp'] = tcp_data['Kp']
        #         pid_data['Ki'] = tcp_data['Ki']
        #         pid_data['Kd'] = tcp_data['Kd']

        #         # Send P, I, D terms back to GUI
        #         error += random.randint(0, 30)
        #         terms['P'] = pid_data['Kp'] * error
        #         terms['I'] = pid_data['Ki'] * error * 0.01
        #         terms['D'] = pid_data['Kd'] * error * 0.1
        #         terms['Current'] = error
        #         terms['Error'] = 0.05 * error

        # except socket.error as msg:
        #     print("TCP Receive Error: " + str(msg[0]) + ': ' + msg[1])

    tcp_handle.shutdown()
    udp_handle.shutdown()

if __name__ == '__main__':
	main()