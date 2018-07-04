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
	int nowButtonState = getButtonState(); // function to generate a random button state
	static int count;
	// case LED state is OFF
  if((info->currentLedState) == LED_OFF) 
  {
		if(nowButtonState == BUTTON_RELEASED && info->previousButtonState != BUTTON_RELEASED) // case if CURRENT button state is OFF
		{
			info->currentLedState = LED_OFF; // then set the CURRENT LED state is OFF
			turnLed(LED_OFF);
			info->previousButtonState = BUTTON_RELEASED; // set PREVIOUS BUTTON be RELEASE
		}
		else if(nowButtonState == BUTTON_PRESSED ) // case if CURRENT BUTTON state is ON
		{
			info->currentLedState = LED_ON; // then set the CURRENT LED state is ON
			turnLed(LED_ON);
			info->previousButtonState = BUTTON_PRESSED; // set PREVIOUS BUTTON be PRESS
		}
		else if(nowButtonState == BUTTON_RELEASED && info->previousButtonState == BUTTON_RELEASED)
		{
			info->currentLedState = LED_OFF;
			info->previousButtonState = BUTTON_RELEASED;
      count++;
		}
    else if(nowButtonState == BUTTON_RELEASED && info->previousButtonState == BUTTON_RELEASED && (count ==1))
    {
      info->currentLedState = LED_OFF;
      turnLed(LED_OFF);
			info->previousButtonState = BUTTON_RELEASED;
    }

  }
  else    // case LED is ON
  {
		if(nowButtonState == BUTTON_RELEASED) // case if CURRENT button state is OFF
		{
			info->currentLedState = LED_ON; // then set the CURRENT LED state is ON
			info->previousButtonState = BUTTON_RELEASED; // 
		}
		else if(nowButtonState = BUTTON_PRESSED)
		{
			info->currentLedState = LED_OFF;
			//turnLed(LED_OFF);
			info->previousButtonState = BUTTON_PRESSED;
		}

    
  }
  
  if(count == 3)//reset 
  {
    count = 0;
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