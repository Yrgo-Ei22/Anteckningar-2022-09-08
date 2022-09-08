/********************************************************************************
* hello_world.c: Implementering av Hello world i C.
* 
*                C-program delas upp i ett eller flera sammans�tta kodblock 
*                som kallas funktioner. I C anv�nds funktionen main som 
*                startpunkt, vilket inneb�r att den f�rsta instruktionen i 
*                main exekverar f�rst vid programexekvering.
* 
*                Datatyp handlar om vilken typ av information som lagras, 
*                exempelvis int f�r heltal, double f�r flyttal (decimaltal), 
*                char* f�r text, bool f�r sant eller falskt med mera.
*         
*                En funktion har f�ljande syntax:
*                returtyp namn(funktionsparametrar)
*  
*                Returtyp indikerar datatypen p� det v�rde som returneras 
*                (skickas tillbaka) n�r en funktion avslutas, om ett s�dant 
*                finns. Det kan handla om heltal, flyttal, text, sant eller 
*                falskt med mera. Ofta returneras inte heller n�gonting. 
*                main har returtypen int (integer = heltal), d� denna funktion 
*                returnerar ifall programexekveringen (k�rning) gick bra eller 
*                inte, d�r 0 = bra, 1 = fel.
*    
*                Efter funktionsnamnet placerar vi funktionsparametrar, vilket 
*                �r de eventuella parametrar vi skickar med via anrop av 
*                funktionen. Det kan handla om heltal, flyttal, ett textstycke 
*                med mera eller inget alls. F�r funktionen main skrivs normalt 
*                void (= tomhet) eller ett tomrum, vilket inneb�r att inga 
*                parametrar passeras n�r main anropas. Vid behov kan vi skicka 
*                med argument fr�n en terminal i form av text.
* 
*                M�svingar anv�nds f�r att indikera var funktioner b�rjar 
*                och slutar, d�r { = b�rjan och } = slut.
* 
*                Vi anropar funktionen printf f�r att genomf�ra utskriften. 
*                Denna funktionen �r deklarerad i biblioteket stdio 
*                (C Standard Input and Output Library). F�r att inkludera 
*                inneh�ll fr�n en headerfil anv�nds inkluderingsdirektivet 
*                #include, med syntax #include <bibliotek.h>, exempelvis 
*                <stdio.h>. F�r att inkludera egna headerfiler anv�nds "" 
*                i st�llet f�r <>, exempelvis #include "headerfil.h>.
* 
*                Semikolon anv�nds f�r att indikera f�r kompilatorn var en 
*                funktion tar slut, likt punkt n�r vi skriver p� svenska.
* 
*                Vi returnerar heltalet 0 fr�n funktionen main f�r att 
*                indikera att programexekveringen gick bra. Annars kan 
*                felkoden 1 returneras om n�got gick fel. Ni kan skippa denna 
*                instruktion sedan C99, den k�rs som default (automatiskt).
********************************************************************************/

/* Inkluderingsdirektiv: */
#include <stdio.h> /* Inkluderar bibliotek f�r in- och utmatning. */

/******************************************************************************
* main: Programmets startpunkt, vilket g�ller alla C-program och program i
*       m�nga andra spr�k. Skriver ut "Hello world!" i terminalen.
********************************************************************************/
int main(void)
{ 
   printf("Hello world!\n");
   return 0;
} 

