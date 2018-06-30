#ifndef _LEDCONTROLLER_H
#define _LEDCONTROLLER_H

#include "Led.h"
#include "Button.h"


typedef struct LedButtonInfo LedButtonInfo;
struct LedButtonInfo{
  LedState currentLedState;
  ButtonState previousButtonState;  
};

void turnOnLedIfButtonIsPressed(void);
void doTapTurnOnTapTurnOffLed(LedButtonInfo *info);

#endif // _LEDCONTROLLER_H
