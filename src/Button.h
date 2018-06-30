#ifndef _BUTTON_H
#define _BUTTON_H

typedef enum{
  BUTTON_RELEASED,
  BUTTON_PRESSED,
}ButtonState;


//return non-zero if button is pressed, zero otherwise
int getButtonState(void);

#endif // _BUTTON_H
