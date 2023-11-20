FROM archfx/ubuntu:latest as builder
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
        git wget libmpc-dev verilator pip

RUN pip install matplotlib numpy scipy tabulate scikit-learn