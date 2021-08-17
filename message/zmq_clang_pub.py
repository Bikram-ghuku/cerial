import zmq
import json

context = zmq.Context()

sock_typ = zmq.PUB
server = context.socket(sock_typ)
try:
    server.bind("tcp://127.0.0.1:5553")
    print("Binded to tcp addr")
except:
    server.connect("tcp://127.0.0.1:5553")
    print("connected to tcp addr")

class publish():
    def __init__(self, request:str):
        self.request = request

    def new_message(self, request=None, size:int=1):
        self.size = size

    def send_json(self, msg:json):
        request = self.request
        send_msg = {request : msg}
        server.send_json(end_msg)

    def send(self, label:list, data:list):
        # msg = []
        data_d = {}
        size = self.size
        request = self.request
        try:
            for x in range(0, size):
                data_d[label[x]] = data[x]
        except IndexError as e:
            raise IndexError(f"size is set to {size}, but receive length {len(label)}")
        
        send_msg = {request : data_d}
        server.send_json(send_msg)