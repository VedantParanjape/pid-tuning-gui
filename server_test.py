from server.udp import udp_server
import time

udp_instance = udp_server(port=1212)
udp_instance.run(True)

while True:
    time.sleep(0.1)
    print(udp_instance.message_pipe.get(timeout=10))