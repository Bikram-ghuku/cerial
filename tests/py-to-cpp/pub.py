from message import zmq_clang_pub as zmq_pub
import time

while True:
    init = zmq_pub.publish("logs_test_py_to_py")
    init.new_message(size=1)
    init.send(["Temp"], ["67°F"])
    print("Sent")
    time.sleep(1)