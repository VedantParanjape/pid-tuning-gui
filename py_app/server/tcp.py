import socket 
import sys
import json
from multiprocessing import Process
from multiprocessing import Queue

class tcp_server():
    def __init__(self, port=1212):
        self.message_pipe = Queue()
        self.proc = None

        self.port = port
        self.family_addr = socket.AF_INET
        self.conn = None
        self.addr = None
        
        self.control_var = True

        try: 
            self.sock = socket.socket(self.family_addr, socket.SOCK_STREAM)
            self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        
        except socket.error as msg:
            print(f'failed to create socket. error code: {str(msg[0])} Message {msg[1]}')
    
    def recv_data(self, size):
        return_dict = {
            "data" : None,
            "error" : None
        }
        
        try:
            data = self.conn.recv(size)
            
            if data:
                return_dict["data"] = data

        except socket.error as msg:
            return_dict["error"] = msg

        return return_dict

    def send_data(self, data):
        try:
            self.conn.sendall(data.encode())
        
        except socket.error as msg:
            return msg
        
        return None

#     def print_message_pipe(self): 
#         """ 
#         function to print queue elements 
#         """ 
#         while not self.message_pipe.empty(): 
#             print(self.message_pipe.get()) 

    def shutdown(self):
        print("tcp socket server shutdown")
        self.sock.close()

    def handler(self):
        try:
            self.sock.bind(('', self.port))
            print('socket binded')
            self.sock.listen(1)
            print('socket listening')
            self.conn, self.addr = self.sock.accept()
            print('connected by', self.addr)

        except socket.error as msg:
            print('Error: ' + str(msg[0]) + ': ' + msg[1])
            self.sock.close()
            sys.exit(1)
        
        while self.control_var:
            data = self.message_pipe.get()
            data_len = len(data)
            recv_len = -10
            
            while recv_len != data_len:
                self.send_data(data)
                recv_dict = self.recv_data(15)

                if recv_dict["error"] is None:
                    recv_len = int(recv_dict["data"].decode())

            print('message sent successfully')
        
        self.shutdown()
        self.proc.join()

    def run(self):
        self.proc = Process(target=self.handler)
        self.proc.start()


#################################################################################
class tcp_client():
    def __init__(self, port=2121):
        self.message_pipe = Queue()
        self.proc = None
        self.port = port

        self.sock = socket.socket()
        # For overcoming Address already in use error
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sock.connect(('', self.port))

    def send_data(self, data):
        try:
            self.sock.sendall(data.encode())
        
        except socket.error as msg:
            return msg
        
        return None

    def recv_data(self, size):
        return_dict = {
            "data" : None,
            "error" : None
        }
        
        try:
            data = self.sock.recv(size)
            
            if data:
                return_dict["data"] = data

        except socket.error as msg:
            return_dict["error"] = msg

        return return_dict

    def print_message_pipe(self): 
        """ 
        function to print queue elements 
        """ 
        while not self.message_pipe.empty(): 
            print(self.message_pipe.get()) 

    def shutdown(self):
        self.sock.close()

    def handler(self, control_var=None):
        if control_var:
            data = self.message_pipe.get()
            print("Preparing to send")
            err = self.send_data(data)
            if err:
                print("Error in send_data")
            else:
                print('message sent successfully')
            
            self.proc.join()    # can only join child process error

        # self.proc.join()

    def run(self, control_var):
        self.proc = Process(target=self.handler, kwargs={'control_var':control_var})
        self.proc.start()
