from message import zmq_json_pub as zmq_publisher
from message import zmq_json_recv as zmq_recv

init = zmq_publisher.publish('sensorEvent')
init.new_message(size=2)
init.send(['lol', 'noob'],['op','ami'])

msg_2 = zmq_publisher.publish('log')
msg_2.new_message(size=1)
msg_2.send(['ami'], ['sera'])

recvr = zmq_recv.subscriber('sensorEvent')
print('sensorEvent\n')
print(recvr.get_data())

revc = zmq_recv.subscriber('log')
print('\nlog\n')
print(revc.get_data())