CPP			    = g++
RM			    = rm -f
CPPFLAGS		= -Wall -I. -O2 -std=c++11 -g
LDFLAGS			= -lpthread -lzmqpp -lzmq -lsodium -Wl,--no-as-needed
SOURCES			= $(wildcard *.cpp)
TARGETS			= $(SOURCES:%.cpp=%)

all:	${TARGETS}

clean:
	${RM} *.obj *~* ${TARGETS}

${TARGETS}:
	${CPP} ${CPPFLAGS} -o $@ ${@:%=%.cpp} ${LDFLAGS}
	
g++ -Wall -I. -O2 -std=c++17 capnp_impl.cpp read_zmq_msg.h send_zmq_msg.h -lcapnp -lkj -lzmqpp -lzmq
g++ -Wall -I. -O2 -std=c++17 capnp_impl.cpp read_zmq_msg.h send_zmq_msg.h schemas/message.capnp.h -lcapnp -lkj -lzmqpp -lzmq

g++ tests/py-to-cpp/rev.cpp -I. -Wall -O2 -std=c++17 message/zmq_clang_pub.h -o tests/py-to-cpp/out.o -lzmqpp -lzmq -ljsoncpp