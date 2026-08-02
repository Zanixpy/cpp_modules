# Dockerfile

FROM ubuntu:22.04

# Basic tools and C/C++ toolchain + valgrind
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential \
        gdb \
        valgrind \
        git \
        cmake \
        && rm -rf /var/lib/apt/lists/*
