/******************************************************************************
* variables.c: För att lagra data används variabler och konstanter. Värdet
*              på variabler kan ändras, medan värdet på konstanter inte går
*              att ändra. Konstanter föregåes av nyckelordet const, annars 
*              deklareras de samma:
* 
*              datatyp namn = startvärde.
* 
*              För att läsa in och lagra innehåll från tangentbordet i en 
*              given variabel passeras adressen till denna, så att inläst
*              innehåll direkt kan lagras där. Vi använder adressoperatorn &, 
*              där exempelvis &x = "adressen till x".            
********************************************************************************/
#include <stdio.h>

/******************************************************************************
* main: Läser in två heltal från terminalen och skriver ut summan, 
*       differensen, produkten samt kvoten av dessa. För att undvika
*       heltalsdivision, så typomvandlas nämnaren till ett flyttal innan
*       kvoten beräknas. Annars genomförs heltalsdivision, vilket är lättare
*       för processorn att genomföra, men medför att eventuell decimaldel
*       för kvoten förloras (exempelvis trunkeras talet 0.75 till 0).
******************************************************************************/
int main(void)
{
   int x = 0;
   int y = 0;

   printf("Enter a number:\n");
   scanf_s("%d", &x);

   printf("\nEnter another number:\n");
   scanf_s("%d", &y);

   printf("\n%d + %d = %d\n", x, y, x + y);
   printf("%d - %d = %d\n", x, y, x - y);
   printf("%d * %d = %d\n", x, y, x * y);
   printf("%d / %d = %lg\n", x, y, (double)x / y);

   return 0;
}