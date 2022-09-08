/********************************************************************************
* int_vector.h: Innehåller funktionalitet för implementering av vektorer för
*               lagring av heltal via strukten int_vector samt tillhörande
*               externa funktioner.
********************************************************************************/
#ifndef INT_VECTOR_H_
#define INT_VECTOR_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
* int_vector: Strukt för implementering av dynamiska vektorer för lagring av
*             signerade heltal av datatypen int. Vektorerna är dynamiska på
*             så sätt att storleken kan ändras (ökas/minskas) utefter behov.
********************************************************************************/
struct int_vector
{
   int* data;   /* Pekare till dynamiskt fält för lagring av heltal. */
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