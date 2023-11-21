## Cleo : Cryptographic leakage evaluation of Hardware


The RISC-V instruction set architecture is known for its open-source and customizable design. One of the notable features of RISC-V is its modular and extensible nature, allowing developers to add custom instructions and extensions tailored to specific applications. One such security extension is the RISC-V Cryptography Extension (RISC-V Crypto). This extension enhances RISC-V processors with hardware acceleration for cryptographic operations, making it well-suited for secure computing tasks. In order to comply with standard architecture guidelines, RISC-V Crypto has developed proto-type hardware implementations in hardware description languages (e.g. Verilog).

 The device's power consumption fluctuates as it executes computations, responding to changing logic states and data processing. These current variations generate distinct patterns that enable the analysis of the ongoing operations. By observing these power consumption fluctuations and correlating them with specific computations, an adversary can deduce sensitive data, such as cryptographic keys or plaintext, without needing direct access to the internal memory or processes of the target device.


This project is a TVLA framework for RISC-V cryptography extension standardization work. This is a complete power side-channel evaluation framework parallel to the existing test-based [functional validation suite](https://github.com/riscv/riscv-crypto/) and functional [formal verification suite](https://github.com/riscv/riscv-crypto/). 

### Project Structure

Here is the folder structure. both [riscv-crypto](https://github.com/riscv/riscv-crypto/) and [xcrypto](https://github.com/scarv/xcrypto) are initialized as submodules.


```bash
├── dockerfile
│   └── Dockerfile
├── eut # extenstions under test
│   ├── riscv-crypto
│   ├── scarv-soc
│   └── xcrypto
├── evaluator # evaluator code
│   ├── power_libs #common utility files
│   ├── riscv_crypto_fu_ssha256
│   └── riscv_crypto_fu_ssha512
└── readme.md # You are looking at it
```

Use the following commands to initiate submodules

```shell
git submodule update --init
```

### Environement

```shell

docker pull archfx/cleo
git clone https://github.com/Archfx/Cleo Cleo
cd Cleo
docker run -t -p 6080:6080 -v "${PWD}/:/Cleo" -w /Cleo --name cleo archfx/cleo
docker exec -it cleo /bin/bash

```

### Pre-Silicon Side Channel Evaluation

Objective: Side-channel sensitive computations should not reveal the information about the information about the inputs to the corresponding functional units. As the evaluation procedure, we feed controlled constraint random inputs to each of the functional units and compute the correlation between the power signature and the input given to the unit.

As an example following is the power side channel signature of the [ssha512](https://github.com/riscv/riscv-crypto/blob/e2dd7d98b7f34d477e38cb5fd7a3af4379525189/rtl/crypto-fu/riscv_crypto_fu_ssha512.v) functional unit and the visual relationship between the input values.


<p align="center">
  <img  src="/evaluator/riscv_crypto_fu_ssha512/riscv_crypto_fu_ssha512.svg">
  <p align="center">
   <em>ssha512 power signature</em>
   </p>
</p>


### Evaluating the SoC

First, initialize the SoC with the below command

```shell
cd eut/scarv-soc
git submodule update --init --recursive
```

This will pull and clone all the submodules related to the SoC components.

