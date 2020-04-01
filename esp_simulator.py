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
TCP_PORT = 2121
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
    tcp_sock = socket.socket()
    tcp_sock.connect(('', TCP_PORT))

    udp_handle = udp_server(UDP_PORT)

    error = 0

    while True:
        err = udp_handle.send_data(json.dumps(terms).encode(), ('', UDP_PORT))
        if err:
            print("Error in UDP sending: " + str(err))
        else:
            print("Sent")

    tcp_sock.close()
    udp_handle.shutdown()


if __name__ == '__main__':
	main()