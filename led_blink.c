/********************************************************************************
* led_blink.c: Demonstration av C-kod för mikrodator ATmega328P, i detta fall
*              implementerad på mikrokontrollerkortet Arduino Uno. En lysdiod 
*              ansluts till PIN 9 / PORTB1 och en tryckknapp ansluts till 
*              PIN 13 / PORTB5. Vid nedtryckning av tryckknappen tänds 
*              lysdioden, annars hålls den släckt.
********************************************************************************/
#include <avr/io.h>

/* Makrodefinitioner: */
#define LED 1    /* Lysdiod ansluten till PIN 9 / PORTB1. */
#define BUTTON 5 /* Tryckknapp ansluten till PIN 13 / PORTB5. */

#define LED_ON PORTB |= (1 << LED)               /* Tänder lysdiod. */
#define LED_OFF PORTB &= ~(1 << LED)             /* Släcker lysdiod. */
#define BUTTON_IS_PRESSED (PINB & (1 << BUTTON)) /* Indikerar nedtryckning. */

/********************************************************************************
* setup: Initierar I/O-portar för en lysdiod samt en tryckknapp.
********************************************************************************/
static inline void setup(void)
{
   DDRB = (1 << LED);
   PORTB = (1 << BUTTON);
   return;
}

/********************************************************************************
* main: Tänder en lysdiod vid nedtryckning av en tryckknapp.
********************************************************************************/
int main(void)
{
    setup();

    while (1) 
    {
       if (BUTTON_IS_PRESSED)
       {
          LED_ON;
       }
       else
       {
          LED_OFF;
       }
    }

    return 0;
}

