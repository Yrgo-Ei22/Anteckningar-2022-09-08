; led_blink.asm: Demonstration av assemblerkod för mikrodator ATmega328P, i detta fall
;                implementerad på mikrokontrollerkortet Arduino Uno. En lysdiod ansluts
;                till PIN 9 / PORTB1 samt en tryckknapp ansluts till PIN 13 / PORTB5.
;                Vid nedtryckning av tryckknappen tänds lysdioden, annars hålls den släckt.

; Makrodefinitioner:
.EQU LED = 1    ; Lysdiod ansluten till PIN 8 / PORTB1.
.EQU BUTTON = 5 ; Tryckknapp ansluten till PIN 13 / PORTB5.

; DSEG: Datasegmentet, vilket består av RAM-minnet, där statiska datamedlemmar deklareras.
;       I detta fall behövs ej allokering av datamedlemmar i RAM-minnet, så 
;       datasegmentet står i detta fall tomt.
.DSEG

; CSEG: Kodsegmentet, vilket består av programminnet, där programkoden lagras.
.CSEG

; 0x00: Startadress. Vid programstart anropas subrutinen main för att starta programmet.
.ORG 0x00
   RJMP main

; main: Tänder lysdioden ansluten till PIN 9 / PORTB1 vid nedtryckning
;       av tryckknappen ansluten till PIN 13 / PORTB5.
main:
   CALL setup
   main_loop:
      CALL button_is_pressed
      CPI R24, 1
      BREQ led_on
      RJMP led_off

; setup: Initierar I/O-portar för en lysdiod ansluten till PIN 9 / PORTB1
;        samt en tryckknapp ansluten till PIN 13 / PORTB5.
setup:
   LDI R16, (1 << LED)
   OUT DDRB, R16
   LDI R16, (1 << BUTTON)
   OUT PORTB, R16
   RET

; led_on: Tänder lysdioden ansluten till PIN 9 / PORTB1.
led_on:
   IN R16, PORTB
   ORI R16, (1 << LED)
   OUT PORTB, R16
   RJMP main_loop

; led_off: Släcker lysdioden ansluten till PIN 9 / PORTB1.
led_off:
   IN R16, PORTB
   ANDI R16, ~(1 << LED)
   OUT PORTB, R16
   RJMP main_loop

; button_is_pressed: Indikerar nedtryckning av tryckknappen ansluten till PIN 13 / PORTB5
;                    via ett returvärde i CPU-register R24, där 1 = true, 0 = false.
button_is_pressed:
   IN R16, PINB
   ANDI R16, (1 << BUTTON)
   CPI R16, 0x00
   BRNE return_true
   RJMP return_false
   return_true:
      LDI R24, 0x01
      RET
   return_false:
      LDI R24, 0x00
      RET


