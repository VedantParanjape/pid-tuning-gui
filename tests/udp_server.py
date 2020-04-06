# This example code is in the Public Domain (or CC0 licensed, at your option.)

# Unless required by applicable law or agreed to in writing, this
# software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
# CONDITIONS OF ANY KIND, either express or implied.

# -*- coding: utf-8 -*-

import socket
import sys
import json
import datetime, time

# -----------  Config  ----------
IP_VERSION = 'IPv4'
PORT = 1212
# -------------------------------


if IP_VERSION == 'IPv4':
    family_addr = socket.AF_INET
elif IP_VERSION == 'IPv6':
    family_addr = socket.AF_INET6
else:
    print('IP_VERSION must be IPv4 or IPv6')
    sys.exit(1)


try:
    server_sock = socket.socket(family_addr, socket.SOCK_DGRAM)
    server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
except socket.error as msg:
    print('Failed to create socket. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
    sys.exit()

try:
    server_sock.bind(('', PORT))
except socket.error as msg:
    print('Bind failed. Error: ' + str(msg[0]) + ': ' + msg[1])
    sys.exit()

st_time = 0

i = 0
while True:
    try:
        i = i + 1
        print(i)
        data, addr = server_sock.recvfrom(150)
        if i == 1:
            st_time = datetime.datetime.now()
        if i==100:
            end_time = datetime.datetime.now()
            diff = end_time - st_time
            print(diff.seconds, ".", diff.microseconds)
            time.sleep(3) 
        if not data:
            break
        data = data.decode()
        print('Reply[' + addr[0] + ':' + str(addr[1]) + '] - ' + data)
    except socket.error as msg:
        print('Error Code : ' + str(msg[0]) + ' Message ' + msg[1])

server_sock.close()
