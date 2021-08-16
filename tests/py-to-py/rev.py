from message import zmq_json_recv as recv

inp = input("Enter number: ")
revcr = recv.subscriber(f"logs_test{inp}")

print("OP \n")
while True:
    try:
        print(revcr.get_data())
    except KeyError:
        pass
