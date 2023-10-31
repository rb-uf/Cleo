FROM ubuntu:latest

SHELL ["/bin/bash", "-c"]
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y build-essential git coreutils gawk autoconf wget curl device-tree-compiler texinfo flex bison zlib1g-dev

RUN git clone https://github.com/rb-uf/riscv-crypto.git
WORKDIR ./riscv-crypto

RUN export RISCV_ARCH=riscv64-unknown-elf; . ./bin/conf.sh; ./tools/start-from-scratch.sh
