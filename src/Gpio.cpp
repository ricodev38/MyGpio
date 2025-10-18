#include "Gpio.h"

Gpio::Gpio() {
	pin = 0;
	direction = 0;
}

Gpio::Gpio(int aPin, int aMode) {
    pin = aPin;
    direction = 0;
    SetDirection();
}

Gpio::Gpio(int aPin, void (*aHandler)(), int aDirection, int aMode) {
	pin = aPin;
	direction = aDirection;
	mode = aMode;
	SetDirection();
	attachInterrupt(digitalPinToInterrupt(pin), aHandler, mode);
}

void Gpio::SetDirection() {
    pinMode(pin, direction);
}

void Gpio::SetInterrupt(void (*aHandler)()) {
	attachInterrupt(digitalPinToInterrupt(pin), aHandler, mode);	
}

void Gpio::DWrite(int aValue) {
    digitalWrite(pin, aValue);
}

int Gpio::DRead() {
    return digitalRead(pin);
}

void Gpio::AWrite(int aValue) {
	analogWrite(pin, aValue);
}
