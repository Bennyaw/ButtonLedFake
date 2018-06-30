#include "LedController.h"
#include "Led.h"
#include "Button.h"

void turnOnLedIfButtonIsPressed(void)
{
  if (getButtonState() != 0)
  {
    turnLed(LED_ON); //
  }
  else
  {
    turnLed(LED_OFF);
  }
}


void doTapTurnOnTapTurnOffLed(LedButtonInfo *info)
{ 
  int currentButtonState = getButtonState();
  
  if((info->currentLedState) == LED_OFF) 
  {
    if(currentButtonState == info->previousButtonState)
    { 
//      info = {LED_OFF,BUTTON_RELEASED};
      info->currentLedState = LED_OFF;
      info->previousButtonState == BUTTON_RELEASED;
    }
    else if(currentButtonState != info->previousButtonState) //Button is pressed
    {
//      info = {LED_ON,BUTTON_PRESSED};
      info->currentLedState = LED_ON;
      turnLed(LED_ON);
      info->previousButtonState = BUTTON_PRESSED;      
    }
    
  }
  else    //led is on
  {
    if(currentButtonState == info->previousButtonState)
    {
//      info = {LED_ON,BUTTON_RELEASED};
      info->currentLedState = LED_ON;
      info->previousButtonState = BUTTON_PRESSED;
    }
    else if(currentButtonState != info->previousButtonState)//button is pressed
    {
//     info = {LED_ON,BUTTON_PRESSED};
      info->currentLedState = LED_ON;
      info->previousButtonState = BUTTON_PRESSED;
    }
    
   //static info = infoChange;
  }
  
  
}


/*
void doTurnOnLedOnButtonPressdAndHoldController()
{
  while(1)
  {
    doturnOnLedIfButtonIsPressed();
  }
}
*/
/*
void doTapTapLedCOntroller()
{ 

  while(1)
  {
    doturnOnLedIfButtonIsPressed();
  }
}
*/