from message import zmq_json_pub
from message import zmq_json_recv

msg = zmq_json_pub.publish("login")
msg.new_message(size=2)
msg.send(['first_name', 'last_name'], ['bikram', 'ghuku'])

msg_recv = zmq_json_recv.subscriber("login")
print(msg_recv.get_data())

assert msg_recv.get_data()=={'first_name': 'bikram', 'last_name': 'ghuku'}, "test_failed"