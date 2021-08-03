sudo apt-get update && sudo apt-get install -y \
    capnproto \
    libcapnp-dev \
    libzmqpp-dev 

cd message && g++ -Wall -I. -O2 -std=c++17 capnp_impl.cpp zmq_msg.h -lcapnp -lkj -lzmqpp -lzmq -o capnp_impl