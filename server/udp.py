import socket 
import sys
import json
from multiprocessing import Process
from multiprocessing import Queue

class udp_server():
    def __init__(self, port=1212):
        self.message_pipe = Queue()
        self.proc = None

        self.port = port
        self.family_addr = socket.AF_INET
        
        try: 
            self.sock = socket.socket(self.family_addr, socket.SOCK_DGRAM)
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        
        except socket.error as msg:
            print(f'failed to create socket. error code: {str(msg[0])} Message {msg[1]}')
                
        try:
            self.sock.bind(('', self.port))

        except socket.error as msg:
            print('Bind failed. Error: ' + str(msg[0]) + ': ' + msg[1])
            sys.exit()

    def recv_data(self, size):
        return_dict = {
            "data" : None,
            "addr" : None,
            "error" : None
        }

        try: 
            data, addr = self.sock.recvfrom(int(size))
            if not data:
                return_dict["addr"] = addr
            else:
                return_dict["data"] = data.decode()
                return_dict["addr"] = addr
        
        except socket.error as msg:
            return_dict["error"] = msg

        return return_dict
    
    def send_data(self, data, addr):
        try:
            self.sock.sendall(data, addr)
        
        except socket.error as msg:
            return msg
        
        return None

    def print_message_pipe(self): 
        """ 
        function to print queue elements 
        """
        while not self.message_pipe.empty(): 
            print(self.message_pipe.get())    

    def shutdown(self):
        self.sock.close()

    def handler(self, control_var=True):
        while control_var:
            data = self.recv_data(150)

            if data["error"] is None and data["data"] is not None:
                self.message_pipe.put(json.loads(data["data"]))
                
        self.proc.join()


    def run(self, control_var):
        self.proc = Process(target=self.handler, kwargs={'control_var':control_var})
        self.proc.start()
