/********************************************************************************
* led_blink.c: Demonstration av C-kod f�r mikrodator ATmega328P, i detta fall
*              implementerad p� mikrokontrollerkortet Arduino Uno. En lysdiod 
*              ansluts till PIN 9 / PORTB1 och en tryckknapp ansluts till 
*              PIN 13 / PORTB5. Vid nedtryckning av tryckknappen t�nds 
*              lysdioden, annars h�lls den sl�ckt.
********************************************************************************/
#include <avr/io.h>

/* Makrodefinitioner: */
#define LED 1    /* Lysdiod ansluten till PIN 9 / PORTB1. */
#define BUTTON 5 /* Tryckknapp ansluten till PIN 13 / PORTB5. */

#define LED_ON PORTB |= (1 << LED)               /* T�nder lysdiod. */
#define LED_OFF PORTB &= ~(1 << LED)             /* Sl�cker lysdiod. */
#define BUTTON_IS_PRESSED (PINB & (1 << BUTTON)) /* Indikerar nedtryckning. */

/********************************************************************************
* setup: Initierar I/O-portar f�r en lysdiod samt en tryckknapp.
********************************************************************************/
static inline void setup(void)
{
   DDRB = (1 << LED);
   PORTB = (1 << BUTTON);
   return;
}

/********************************************************************************
* main: T�nder en lysdiod vid nedtryckning av en tryckknapp.
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

