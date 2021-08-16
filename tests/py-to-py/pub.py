from message import zmq_json_pub as pub
import random
import string
import time


value = 0
value2 = 0
while True:
    init = pub.publish("logs_test1")
    init.new_message(size=1)
    key = ''.join(random.choices(string.ascii_letters + string.digits, k=16))
    j_op = '{"%s": %s}'%(key,value)
    init.send([key], [value])
    time.sleep(1)
    value+=1
    print("msg sent")
    print(j_op)

    init2 = pub.publish("logs_test2")
    init2.new_message(size=1)
    j_op_2 = '{"1": %s}'%value2
    init2.send(["1"], [value2])
    time.sleep(1)
    value2+=1
    print("msg sent 2")
    print(j_op_2)
