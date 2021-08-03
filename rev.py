import zmq
import json

context = zmq.Context()
recv = context.socket(zmq.PULL)
recv.connect("tcp://127.0.0.1:5555")
msg = recv.recv_string()
# msg = str(msg)
# msg = msg.replace("\n","")
# msg = msg.replace("\t","")
ms_json = json.loads(msg)
print(ms_json['lol'])