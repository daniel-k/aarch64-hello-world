// Data register of first UART (PL011)
volatile unsigned int * const UART0_DR = (unsigned int *) 0x09000000;

// Stop guest so Qemu terminates
void system_off(void);

void print(const char *s) {
	while(*s != '\0') {
		*UART0_DR = (unsigned int)(*s++);
    }
}

int main() {
	print("Hello world!\n");
	system_off();

	return 0;
}
