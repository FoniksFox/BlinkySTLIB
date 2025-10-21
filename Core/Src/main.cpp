#include "ST-LIB.hpp"

int main(void) {
    DigitalOutput led(PB0);
    Time::register_low_precision_alarm(1000, [&led]() {
        led.toggle();
    });

    STLIB::start();
    led.turn_on();
    
    while (1) {
        STLIB::update();
    }
}

void Error_Handler(void) {
    ErrorHandler("HAL error handler triggered");
    while (1) {
    }
}
