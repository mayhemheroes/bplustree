# Build Stage:
FROM --platform=linux/amd64 ubuntu:20.04 as builder

## Install build dependencies.
RUN apt-get update && apt-get install -y cmake clang

ADD lib/ /lib
ADD tests/ /tests
ADD CMakeLists.txt /
RUN mkdir build

## Build Step
WORKDIR build
RUN CC=clang CXX=clang cmake .. && make
WORKDIR /

# Package Stage
FROM --platform=linux/amd64 ubuntu:20.04
COPY --from=builder /build/bin/bplustree_fuzzable /
COPY --from=builder /build/lib/libbplustree.so.1 /
