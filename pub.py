from message import zmq_json_pub as pub
import random
import string
import time
value = 9

while True:
    init = pub.publish("OP")
    init.new_message(size=1)
    key = ''.join(random.choices(string.ascii_letters + string.digits, k=16))
    j_op = '{"%s": %s}'%(key,value)
    init.send([key], [value])
    time.sleep(1)
    value+=1
    print("msg sent")
    print(j_op)
