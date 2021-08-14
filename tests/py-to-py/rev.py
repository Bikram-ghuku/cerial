from message import zmq_json_recv as recv


revcr = recv.subscriber("OP")
print("OP \n")
while True:
    print(revcr.get_data())

