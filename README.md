First steps on Aarch64
======================

This repositories shows the first basic steps that are needed to run bare-metal
code on Aarch64 (inside Qemu).


## Requirements

You will need:
 * `aarch64-linux-gnu-gcc` et al.
 * `qemu-system-aarch64`
 * `make`


## Run it

To run the code, just type:

~~~bash
$ make qemu
aarch64-linux-gnu-gcc -ggdb3 -std=gnu99 -Wall -c -o main.o main.c
aarch64-linux-gnu-as -o startup.o startup.asm
aarch64-linux-gnu-ld -Bstatic --gc-sections -nostartfiles -nostdlib -o first-steps.elf -T link.ld main.o
qemu-system-aarch64 -machine virt -m 1024M -cpu cortex-a53 -nographic -s -kernel first-steps.elf
Hello world!
~~~


## Acknowledgements

This is the code for a [blog post](https://www.daniel-krebs.net/first-steps-on-aach64.html)
and I didn't make up everything myself, so thanks to
[freedomtan](https://github.com/freedomtan/aarch64-bare-metal-qemu) and ultimately also
[Balau](https://balau82.wordpress.com/2010/02/28/hello-world-for-bare-metal-arm-using-qemu/).

