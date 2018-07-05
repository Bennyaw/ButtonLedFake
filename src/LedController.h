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
void fake_turnLedON(LedState state, int NumCalls);
void fake_turnLedOFF(LedState state, int NumCalls);
ButtonState fake_getButtonStaterReleasedPressedReleased; 
void verify_TurnLedCalls;

#endif // _LEDCONTROLLER_H
