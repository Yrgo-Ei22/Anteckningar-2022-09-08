/********************************************************************************
* vector.hpp: Innehåller funktionalitet för implementering av generiska vektorer
*             för lagring av element av valfri datatyp.
********************************************************************************/
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* vector: Strukt-template för implementering av dynamiska vektorer för lagring
*         av element av valfri datatyp. Vektorerna är dynamiska på så sätt
*         att storleken kan ändras (ökas/minskas) utefter behov.
********************************************************************************/
template<class T>
struct vector
{
   T* data = nullptr;    /* Pekare till dynamiskt fält för lagring av element. */
   std::size_t size = 0; /* Vektorns storlek, dvs. antalet element den rymmer. */

   /*****************************************************************************
   * vector: Konstruktor, initierar ny tom vektor.
   *****************************************************************************/
   vector(void) { }

   /*****************************************************************************
   * ~vector: Destruktor, frigör allokerat minne ifall given vektor går ur
   *          scope och därmed raderas från stacken.
   *****************************************************************************/
   ~vector(void) { this->clear(); }

   /*****************************************************************************
   * begin: Returnerar adressen till första elementet i angiven vektor.
   *****************************************************************************/
   T* begin(void) const { return this->data; }

   /*****************************************************************************
   * end: Returnerar adressen direkt efter sista elementet i angiven vektor.
   *****************************************************************************/
   T* end(void) const { return this->data + this->size; }

   /*****************************************************************************
   * clear: Tömmer innehållet i angiven vektor.
   *****************************************************************************/
   void clear(void)
   {
      std::free(this->data);
      this->data = nullptr;
      this->size = 0;
      return;
   }

   /*****************************************************************************
   * push: Lägger till ett nytt element längst bak i angiven vektor.
   * 
   *       - val: Det nya element som skall läggas till i vektorn.
   *****************************************************************************/
   int push(const T& val)
   {
      auto* copy = (T*)std::realloc(this->data, sizeof(T) * (this->size + 1));
      if (!copy) return 1;
      copy[this->size++] = val;
      this->data = copy;
      return 0;
   }

   /*****************************************************************************
   * print: Skriver ut innehållet lagrat i angiven vektor via angiven utström,
   *        där standardutenhet std::cout används som default för utskrift 
   *        i terminalen.
   *  
   *        - ostream: Angiven utström (default = std::cout).
   *****************************************************************************/
   void print(std::ostream& ostream = std::cout) const
   {
      if (!this->size) return;

      ostream << "--------------------------------------------------------------------------------\n";

      for (auto& i : *this)
      {
         ostream << i << "\n";
      }

      ostream << "--------------------------------------------------------------------------------\n\n";
      return;
   }

};

#endif /* VECTOR_HPP_ */