import json
import zmq

context = zmq.Context()

sock_typ = zmq.SUB
client = context.socket(sock_typ)
client.connect("tcp://127.0.0.1:5556")

class subscriber():
    def __init__(self, request:str):
        self.request = request

    def get_data(self):
        client.subscribe("")
        msg= client.recv_json()
        msg_rtn = msg[self.request]
        return msg_rtn
