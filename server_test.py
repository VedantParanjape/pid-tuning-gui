from server.udp import udp_server
from server.tcp import tcp_server
import time, json

pid_data = {
    "kp":12.0,
    "ki":13.0,
    "kd":14.0,
    "setpoint":15.0
}

udp_instance = udp_server(port=1212)
udp_instance.run(True)

tcp_instance = tcp_server(port=2121)
tcp_instance.run(True)

while True:

    print('wait', udp_instance.message_pipe.get(timeout=10))
    
    tcp_instance.message_pipe.put(json.dumps(pid_data))


