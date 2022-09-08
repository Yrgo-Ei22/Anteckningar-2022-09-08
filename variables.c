/******************************************************************************
* variables.c: F�r att lagra data anv�nds variabler och konstanter. V�rdet
*              p� variabler kan �ndras, medan v�rdet p� konstanter inte g�r
*              att �ndra. Konstanter f�reg�es av nyckelordet const, annars 
*              deklareras de samma:
* 
*              datatyp namn = startv�rde.
* 
*              F�r att l�sa in och lagra inneh�ll fr�n tangentbordet i en 
*              given variabel passeras adressen till denna, s� att inl�st
*              inneh�ll direkt kan lagras d�r. Vi anv�nder adressoperatorn &, 
*              d�r exempelvis &x = "adressen till x".            
********************************************************************************/
#include <stdio.h>

/******************************************************************************
* main: L�ser in tv� heltal fr�n terminalen och skriver ut summan, 
*       differensen, produkten samt kvoten av dessa. F�r att undvika
*       heltalsdivision, s� typomvandlas n�mnaren till ett flyttal innan
*       kvoten ber�knas. Annars genomf�rs heltalsdivision, vilket �r l�ttare
*       f�r processorn att genomf�ra, men medf�r att eventuell decimaldel
*       f�r kvoten f�rloras (exempelvis trunkeras talet 0.75 till 0).
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