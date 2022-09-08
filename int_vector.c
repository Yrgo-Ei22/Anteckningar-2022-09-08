/********************************************************************************
* int_vector.c: Deklarationer av externa funktioner för implementering av
*               vektorer för lagring av heltal via strukten int_vector.
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
* int_vector_clear: Tömmer innehållet i angiven vektor.
*
*                   - self: Pekare till vektorn vars innehåll ska tömmas.
********************************************************************************/
void int_vector_clear(struct int_vector* self)
{
   free(self->data);
   self->data = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* int_vector_push: Lägger till ett nytt element längst bak i angiven vektor.
*
*                   - self: Pekare till vektorn som ska lagra det nya talet.
*                   - num : Talet som ska läggas till längst bak i vektorn.
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
* int_vector_print: Skriver ut innehållet lagrat i angiven vektor via angiven
*                   utström, där standardutenhet stdout används som default för
*                   utskrift i terminalen.
*
*                   - self   : Pekare till vektorn vars innehåll ska skrivas ut.
*                   - ostream: Pekare till angiven utström (default = stdout).
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