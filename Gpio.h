#pragma once
#include <Arduino.h>

class Gpio {
protected:
	int pin;
	int direction;
	int mode;

public:
	Gpio();
    Gpio(int aPin, int aMode);
	Gpio(int aPin, void (*aHandler)(), int aDirection, int aMode);
    void SetDirection();
	void SetInterrupt(void (*aHandler)());
    void DWrite(int aValue);
    int DRead();
	void AWrite(int aValue);
};
