# AI/ML accelerator for AJIT Processor
AJIT is an indigenous processor designed and developed at IIT Bombay. It is an implementation of the SPARC-v8 ISA, with 64-bit extensions for SIMD operations (integer and floating point). This project aims to accelerate the operation of 2D convolution using these SIMD instructions.

### Software setup
All programs were built and simulated using the `ajit_build_dev` docker image from the [ajit toolchain](https://github.com/adhuliya/ajit-toolchain/tree/marshal). Refer to the README for instructions on how to install the toolchain.

### File naming conventions
Each program folder has a prefix of the form "cores_threads_isa". 
For example "1x2x64" indicates that the program uses a single core, dual threaded AJIT processor with 64-bit ISA (SIMD).

###### Each folder has a README explaining how to build and simulate the C program.
