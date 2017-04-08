#include "Component.h"
#include "Pin.h"
#include "Potentiometer.h"
#include "RgbLed.h"

PowerPin potpower(A0);
InputPin potinput(A1);
GroundPin potground(A2);

Potentiometer pot(potpower, potinput, potground, 23, 1000, 0, 19);

OutputPin red(4);
PowerPin power(5);
OutputPin green(6);
OutputPin blue(7);

RgbLed<PowerPin> led(red, power, green, blue);

void setup()
{
    led.setup();
    pot.setup();
    Component::CheckSetup();
    Pin::ValidateSingleUsage();
}

void loop()
{
    if (pot.scaledMin())
    {
        led.yellow();
    }
    else if (pot.scaledMax())
    {
        led.blue();
    }
    else
    {
        led.green();
    }
}
