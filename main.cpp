#include "mbed.h"
#include "DigitDisplay.h"

DigitalOut myled(LED1);

DigitDisplay display(D2, D3);

Ticker tick;

uint8_t hour   = 20;
uint8_t minute = 14;
uint8_t second = 0;

void beat()
{
    static uint8_t colon = 0;
    display.setColon(colon);
    if (colon) {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
                display.write(0, hour / 10);
                display.write(1, hour % 10);
            }
            display.write(2, minute / 10);
            display.write(3, minute % 10);
        }
    }
    colon = 1 - colon;
}

int main() {
    display.write(0, hour / 10);
    display.write(1, hour % 10);
    display.write(2, minute / 10);
    display.write(3, minute % 10);
    display.setColon(true);
    tick.attach(&beat, 0.5);
    while(1) {
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);
    }
}