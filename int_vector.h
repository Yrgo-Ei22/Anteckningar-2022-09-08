/********************************************************************************
* int_vector.h: Inneh�ller funktionalitet f�r implementering av vektorer f�r
*               lagring av heltal via strukten int_vector samt tillh�rande
*               externa funktioner.
********************************************************************************/
#ifndef INT_VECTOR_H_
#define INT_VECTOR_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
* int_vector: Strukt f�r implementering av dynamiska vektorer f�r lagring av
*             signerade heltal av datatypen int. Vektorerna �r dynamiska p�
*             s� s�tt att storleken kan �ndras (�kas/minskas) utefter behov.
********************************************************************************/
struct int_vector
{
   int* data;   /* Pekare till dynamiskt f�lt f�r lagring av heltal. */
   size_t size; /* Vektorns storlek, dvs. antalet element den rymmer. */
};

/* Externa funktioner: */
void int_vector_init(struct int_vector* self);
void int_vector_clear(struct int_vector* self);
int int_vector_push(struct int_vector* self,
                     const int num);
void int_vector_print(const struct int_vector* self,
                      FILE* ostream);

#endif /* INT_VECTOR_H_ */