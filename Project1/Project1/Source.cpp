#include "mbed.h"

#define BLINKING_RATE     500ms

int main()
{
    int scantimes = 0;
    DigitalIn button1(D4);
    DigitalIn button2(D2);
    DigitalOut ledred(D7);
    DigitalOut ledgreen(D0);

    if (button1 || button2 == 1) {
        scantimes = 10
            if (button1 == 1) {
                ledred == 1
            }
        if (button2 == 1) {
            ledgreen == 1
        }
    };
#ifdef LED6
    DigitalOut led(LED2);
#else
    bool led;
#endif

    while (scantimes >= 0) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}