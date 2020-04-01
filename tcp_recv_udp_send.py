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
IP_VERSION = 'IPv4'
TCP_PORT = 2121
UDP_PORT = 1212
# -------------------------------

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

if IP_VERSION == 'IPv4':
	family_addr = socket.AF_INET
elif IP_VERSION == 'IPv6':
	family_addr = socket.AF_INET6
else:
	print('IP_VERSION must be IPv4 or IPv6')
	sys.exit(1)

# -------------- UDP -------------
try:
    udp_server_sock = socket.socket(family_addr, socket.SOCK_DGRAM)
    udp_server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
except socket.error as msg:
    print('Failed to create socket. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
    sys.exit()

print("UDP Socket Created")

try:
    udp_server_sock.bind(('', UDP_PORT))
except socket.error as msg:
    print('UDP Bind failed. Error: ' + str(msg[0]) + ': ' + msg[1])
    sys.exit()
# --------------------------------

# -------------- TCP -------------
# try:
#     tcp_server_sock = socket.socket(family_addr, socket.SOCK_STREAM)
# except socket.error as msg:
#     print('Error: ' + str(msg[0]) + ': ' + msg[1])
#     sys.exit(1)

# print("TCP Socket Created")

# try:
#     tcp_server_sock.bind(('', TCP_PORT))
#     print('Socket binded')
#     tcp_server_sock.listen(1)
#     print('Socket listening')
#     conn, addr = tcp_server_sock.accept()
#     print('Connected by', addr)
# except socket.error as msg:
#     print('TCP Bind failed. Error: ' + str(msg[0]) + ': ' + msg[1])
#     sock.close()
#     sys.exit(1)

tcp_sock = socket.socket()
tcp_sock.connect(('', TCP_PORT))
# --------------------------------


def main():

    error = 0
    
    while(True):
        
        try:
            tcp_data = tcp_sock.recv(buffer_size)
            print(tcp_data)
            if tcp_data:
                # Send to appropriate function
                tcp_data = json.loads(tcp_data)
                pid_data['Kp'] = tcp_data['Kp']
                pid_data['Ki'] = tcp_data['Ki']
                pid_data['Kd'] = tcp_data['Kd']

                # Send P, I, D terms back to GUI
                error += random.randint(0, 30)
                terms['P'] = pid_data['Kp'] * error
                terms['I'] = pid_data['Ki'] * error * 0.01
                terms['D'] = pid_data['Kd'] * error * 0.1
                terms['Current'] = error
                terms['Error'] = 0.05 * error

                # udp_server_sock.sendall(json.dumps(terms).encode(), UDP_PORT)

        except socket.error as msg:
            print("TCP Receive Error: " + str(msg[0]) + ': ' + msg[1])

        try:
            udp_server_sock.sendto(json.dumps(terms).encode(), ('', UDP_PORT))
        except socket.error as msg:
            print('Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
        
    udp_server_sock.close()
    tcp_sock.close()

if __name__ == '__main__':
	main()