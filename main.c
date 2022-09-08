/********************************************************************************
* main.c: Demonstration av dynamiska vektorer för lagring av heltal i C.
********************************************************************************/
#include "int_vector.h"

/********************************************************************************
* main: Fyller två dynamiska vektorer med heltal och skriver ut i terminalen.
*       Den första vektorn tilldelas tio heltal 0 - 9, medan den andra vektorn
*       tilldelas alla jämna heltal mellan 0 - 20 samt alla heltal 100 - 104.
********************************************************************************/
int main(void)
{
   struct int_vector v1, v2;
   
   int_vector_init(&v1);
   int_vector_init(&v2);

   for (int i = 0; i < 10; ++i)
   {
      int_vector_push(&v1, i);
      int_vector_push(&v2, i * 2);
   }

   for (int i = 0; i < 5; ++i)
   {
      int_vector_push(&v2, i + 100);
   }

   int_vector_print(&v1, stdout);
   int_vector_print(&v2, stdout);

   return 0;
}