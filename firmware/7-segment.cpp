/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define segment_a (1<<0)
#define segment_b (1<<1)
#define segment_c (1<<2)
#define segment_d (1<<3)
#define segment_e (1<<4)
#define segment_f (1<<5)
#define segment_g (1<<6)

Serial pc(USBTX, USBRX);
BusOut segments(D0, D1, D2, D3, D4, D5, D6);

unsigned char digit_segment[10];

void digit_init(void){
    segments = 0x00;

    digit_segment[0] = segment_a | segment_b | segment_c | segment_d | segment_e | segment_f;
    digit_segment[1] = segment_b | segment_c;
    digit_segment[2] = segment_a | segment_b | segment_d | segment_e | segment_g;
    digit_segment[3] = segment_a | segment_b | segment_c | segment_d | segment_g;
    digit_segment[4] = segment_b | segment_c | segment_g | segment_f;
    digit_segment[5] = segment_a | segment_c | segment_d | segment_f | segment_g;
    digit_segment[6] = segment_a | segment_c | segment_d | segment_e | segment_f | segment_g;
    digit_segment[7] = segment_a | segment_b | segment_c | segment_f;
    digit_segment[8] = segment_a | segment_b | segment_c | segment_d | segment_e | segment_f | segment_g;
    digit_segment[9] = segment_a | segment_b | segment_c | segment_d | segment_f | segment_g;
}

int main(){
    digit_init();
    pc.baud(115200);
    while(1){
        for(int i = 0; i < 10; i++){
            //segments = 0xff & (~digit_segment[i]);
            segments = digit_segment[i];
            //segments = 0xff & temp_seg[i];
            wait(0.55);
        }
    }
}