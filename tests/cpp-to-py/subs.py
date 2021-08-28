import message.zmq_clang_subs as subs

subs = subs.subscriber("Logs_cxx_to_py")
print(subs.get_data())
