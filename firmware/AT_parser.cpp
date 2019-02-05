/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

UARTSerial *_serial;
ATCmdParser *_parser;

#define DEAFAULT_BAND_RATE 115200

char buffer[1024];
int rssi_int;

int main(){
    _serial = new UARTSerial(PA_0, PA_1, DEAFAULT_BAND_RATE);
    _parser = new ATCmdParser(_serial);
    _parser->set_timeout(50);
    _parser->debug_on(0);
    _parser->set_delimiter("\r\n");

    while(1){
        memset(buffer, 0x0, sizeof(buffer));
        _parser->send("AT?");
        _parser->read(buffer, sizeof(buffer));
        printf("%s\r\n", buffer);
        wait(1.0);

        memset(buffer, 0x0, sizeof(buffer));
        _parser->send("AT+APPKEY=?");
        _parser->read(buffer, sizeof(buffer));
        printf("%s\r\n", buffer);
        wait(1.0);

        _parser->send("AT+RSSI=?");
        _parser->recv("%d\r\n", &rssi_int);

        printf("RSSI : %d\r\n", rssi_int);
        printf("\nDone\n");
        wait(1.0);
    }
}