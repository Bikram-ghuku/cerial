import zmq
import json

context = zmq.Context()

sock_typ = zmq.PULL
client = context.socket(sock_typ)
client.connect("tcp://127.0.0.1:5554")

class subscriber():
    def __init__(self, request:str):
        self.request = request

    def get_data(self):
        msg_str = client.recv_string()
        msg = json.loads(msg_str)
        msg_rtn = msg[self.request]
        return msg_rtn