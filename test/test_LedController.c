#include "unity.h"
#include "LedController.h"
#include "mock_Button.h"
#include "mock_Led.h"

int turnLedCallNumbers = 0;
int expectedGetButtonStateMaxCalls = 0;
int expectedTurnLedMaxCalls = 0;
ButtonState *expectedButtonStates = NULL;
LedState *expectedLedStates = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}

void fake_turnLedON(LedState state, int NumCalls) {
  turnLedCallNumbers++;

  if(Numcalls < expectedTurnLedMaxCalls)
  {
    if(state != expeectedLedState[NumCalls])
    {
      TEST_FAIL_MESSAGE("turnLed() was called with ???, but expect ???")
    }
  }
  else
  {
      TEST_FAIL_MESSAGE("Received extra getButtonState() calls.");
  }

}


ButtonState fake_getButtonState(int Numcalls)
{
  if(NumCalls < expectedGetButtonStateMaxCalls)
  {
    return expectedButtonStates[Numcalls];
  }
  else
    TEST_FAIL_MESSAGE("Received extra getButtonState() calls");
}

void setupFake(Ledstate expLedStates[], int ledMaxCalls, ButtonState buttStates[],int buttonMaxCalls)
{
  turnLedCallNumbers =0;
  turnLed_StubWithCallback(fake_turnLed);
  expectedLedStates = expLedStates;
  expectedTurnLedMaxCalls = ledMaxCalls;
  getButtonState_StubWithCallback(fake_getButtonState);
  expectedButtonStates = buttStates;
  expectedGetButtonStateMaxCalls = buttonMaxCalls;
}

ButtonState fake_getButtonStaterReleasedPressedReleased (int NumCalls) {
  switch (NumCalls) {
    case 0:
      return BUTTON_RELEASED;
    case 1:
      return BUTTON_PRESSED;
    case 2:
      return BUTTON_RELEASED;
    default:
      TEST_FAIL_MESSAGE("Received extra getButtonState() calls");
  }
}

void verify_TurnLedCalls(int NumCalls) {
  if(turnLEDCallNumbers != NumCalls)
    TEST_FAIL_MESSAGE("turnLED() was not called at all. But 1 call is expected.");
}

void test_dotapTurnOnTapTurnOffLED_given_LED_is_off_and_button_is_pressed_and_released_expect_LED_is_turned_on (void) {
  LedButtonInfo info = {LED_OFF, BUTTON_RELEASED};
  ButtonStates buttonStates[] = {BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_RELEASED}
  
  setupFake(buttonState,3); 
  turnLed_StubWithCallback(fake_turnLedON);

  doTapTurnOnTapTurnOffLed(&info);
  turnLed_Expect(LED_ON);
  doTapTurnOnTapTurnOffLed(&info);
  doTapTurnOnTapTurnOffLed(&info);

  verify_TurnLedCalls(1);

  TEST_ASSERT_EQUAL (LED_ON, info.currentLedState);
}



void test_dotapTurnOnTapTurnOffLed_given_led_is_on_button_is_pressed_and_released_expect_led_is_turn_off(void)
{
  LedButtonInfo info = {LED_ON, BUTTON_RELEASED};
  
  turnLed_StubWithCallback(fake_turnLedOFF);
  getButtonState_StubWithCallback(fake_getButtonStaterReleasedPressedReleased);
  
  doTapTurnOnTapTurnOffLed(&info);
  doTapTurnOnTapTurnOffLed(&info);
  turnLed_Expect(LED_OFF);
  doTapTurnOnTapTurnOffLed(&info);
  
 
  
  TEST_ASSERT_EQUAL(LED_OFF, info.currentLedState);
}
/*
void test_dotapTurnOnTapTurnOffLed_given_led_is_off_button_is_pressed_and_released_expect_led_is_turn_off(void)
{
  LedButtonInfo info = {LED_OFF, BUTTON_RELEASED};
  
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);  
  doTapTurnOnTapTurnOffLed(&info);
  
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  
 
  
  TEST_ASSERT_EQUAL(LED_OFF, info.currentLedState);
}

void test_dotapTurnOnTapTurnOffLed_given_led_is_on_button_is_pressed_and_released_expect_led_is_turn_on(void)
{
  LedButtonInfo info = {LED_ON, BUTTON_RELEASED};
  
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  doTapTurnOnTapTurnOffLed(&info);
  
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);    
  doTapTurnOnTapTurnOffLed(&info);
  
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
	turnLed_Expect(LED_ON);
  doTapTurnOnTapTurnOffLed(&info);
  
 
  
  TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}


void xtest_LedController_give_button_is_pressed_expect_led_is_turn_on(void)
{ 
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  
  turnOnLedIfButtonIsPressed();
}

void xtest_LedController_give_button_is_not_pressed_expect_led_is_turn_off(void)
{
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);
  
  turnOnLedIfButtonIsPressed();
}
*/

