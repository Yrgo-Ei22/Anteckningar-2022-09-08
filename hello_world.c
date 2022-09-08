/********************************************************************************
* hello_world.c: Implementering av Hello world i C.
* 
*                C-program delas upp i ett eller flera sammansätta kodblock 
*                som kallas funktioner. I C används funktionen main som 
*                startpunkt, vilket innebär att den första instruktionen i 
*                main exekverar först vid programexekvering.
* 
*                Datatyp handlar om vilken typ av information som lagras, 
*                exempelvis int för heltal, double för flyttal (decimaltal), 
*                char* för text, bool för sant eller falskt med mera.
*         
*                En funktion har följande syntax:
*                returtyp namn(funktionsparametrar)
*  
*                Returtyp indikerar datatypen på det värde som returneras 
*                (skickas tillbaka) när en funktion avslutas, om ett sådant 
*                finns. Det kan handla om heltal, flyttal, text, sant eller 
*                falskt med mera. Ofta returneras inte heller någonting. 
*                main har returtypen int (integer = heltal), då denna funktion 
*                returnerar ifall programexekveringen (körning) gick bra eller 
*                inte, där 0 = bra, 1 = fel.
*    
*                Efter funktionsnamnet placerar vi funktionsparametrar, vilket 
*                är de eventuella parametrar vi skickar med via anrop av 
*                funktionen. Det kan handla om heltal, flyttal, ett textstycke 
*                med mera eller inget alls. För funktionen main skrivs normalt 
*                void (= tomhet) eller ett tomrum, vilket innebär att inga 
*                parametrar passeras när main anropas. Vid behov kan vi skicka 
*                med argument från en terminal i form av text.
* 
*                Måsvingar används för att indikera var funktioner börjar 
*                och slutar, där { = början och } = slut.
* 
*                Vi anropar funktionen printf för att genomföra utskriften. 
*                Denna funktionen är deklarerad i biblioteket stdio 
*                (C Standard Input and Output Library). För att inkludera 
*                innehåll från en headerfil används inkluderingsdirektivet 
*                #include, med syntax #include <bibliotek.h>, exempelvis 
*                <stdio.h>. För att inkludera egna headerfiler används "" 
*                i stället för <>, exempelvis #include "headerfil.h>.
* 
*                Semikolon används för att indikera för kompilatorn var en 
*                funktion tar slut, likt punkt när vi skriver på svenska.
* 
*                Vi returnerar heltalet 0 från funktionen main för att 
*                indikera att programexekveringen gick bra. Annars kan 
*                felkoden 1 returneras om något gick fel. Ni kan skippa denna 
*                instruktion sedan C99, den körs som default (automatiskt).
********************************************************************************/

/* Inkluderingsdirektiv: */
#include <stdio.h> /* Inkluderar bibliotek för in- och utmatning. */

/******************************************************************************
* main: Programmets startpunkt, vilket gäller alla C-program och program i
*       många andra språk. Skriver ut "Hello world!" i terminalen.
********************************************************************************/
int main(void)
{ 
   printf("Hello world!\n");
   return 0;
} 

