/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalOut myled(D2);

int main()
{

	if (myled.is_connected()) {
		printf("my led is initialized and connected!\n\r");
	}
	while (1) {
		myled = 1;
		printf("\n\r myled = %d", (uint8_t)myled);
		wait(0.5);

		myled.write(0);
		printf("\n\r myled = %d", myled.read());
		wait(0.5);
	}
}