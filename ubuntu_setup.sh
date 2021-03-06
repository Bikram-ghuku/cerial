#!/bin/bash -e

sudo apt-get update && sudo apt-get install -y \
    capnproto \
    libcapnp-dev \
    libzmqpp-dev \
    libzmq3-dev \
    libjsoncpp-dev\
    python-dev \
    python3-pip \
    python-pytest

pip install pyzmq
