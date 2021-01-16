#include "mbed.h"

AnalogIn pot(A0);
DigitalOut led(A1);

int main (void) {
    float value = 0.0f;
    while(1) {
        value = pot;
        printf("Slide location %3.2f\n", value);
        wait(0.5f);
        led = !led;
    }
}