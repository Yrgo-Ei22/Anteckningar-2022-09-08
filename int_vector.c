/********************************************************************************
* int_vector.c: Deklarationer av externa funktioner f�r implementering av
*               vektorer f�r lagring av heltal via strukten int_vector.
********************************************************************************/
#include "int_vector.h"

/********************************************************************************
* int_vector_init: Initierar angiven vektor till tom vid start.
* 
*                  - self: Pekare till vektorn som ska initieras.
********************************************************************************/
void int_vector_init(struct int_vector* self)
{
   self->data = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* int_vector_clear: T�mmer inneh�llet i angiven vektor.
*
*                   - self: Pekare till vektorn vars inneh�ll ska t�mmas.
********************************************************************************/
void int_vector_clear(struct int_vector* self)
{
   free(self->data);
   self->data = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* int_vector_push: L�gger till ett nytt element l�ngst bak i angiven vektor.
*
*                   - self: Pekare till vektorn som ska lagra det nya talet.
*                   - num : Talet som ska l�ggas till l�ngst bak i vektorn.
********************************************************************************/
int int_vector_push(struct int_vector* self,
                     const int num)
{
   int* copy = (int*)realloc(self->data, sizeof(int) * (self->size + 1));
   if (!copy) return 1;
   copy[self->size++] = num;
   self->data = copy;
   return 0;
}

/********************************************************************************
* int_vector_print: Skriver ut inneh�llet lagrat i angiven vektor via angiven
*                   utstr�m, d�r standardutenhet stdout anv�nds som default f�r
*                   utskrift i terminalen.
*
*                   - self   : Pekare till vektorn vars inneh�ll ska skrivas ut.
*                   - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void int_vector_print(const struct int_vector* self,
                      FILE* ostream)
{
   if (!self->size) return;
   if (!ostream) ostream = stdout;

   fprintf(ostream, "--------------------------------------------------------------------------------\n");

   for (const int* i = self->data; i < self->data + self->size; ++i)
   {
      fprintf(ostream, "%d\n", *i);
   }

   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}