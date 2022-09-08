/********************************************************************************
* vector.hpp: Inneh�ller funktionalitet f�r implementering av generiska vektorer
*             f�r lagring av element av valfri datatyp.
********************************************************************************/
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <cstdlib>

/********************************************************************************
* vector: Strukt-template f�r implementering av dynamiska vektorer f�r lagring
*         av element av valfri datatyp. Vektorerna �r dynamiska p� s� s�tt
*         att storleken kan �ndras (�kas/minskas) utefter behov.
********************************************************************************/
template<class T>
struct vector
{
   T* data = nullptr;    /* Pekare till dynamiskt f�lt f�r lagring av element. */
   std::size_t size = 0; /* Vektorns storlek, dvs. antalet element den rymmer. */

   /*****************************************************************************
   * vector: Konstruktor, initierar ny tom vektor.
   *****************************************************************************/
   vector(void) { }

   /*****************************************************************************
   * ~vector: Destruktor, frig�r allokerat minne ifall given vektor g�r ur
   *          scope och d�rmed raderas fr�n stacken.
   *****************************************************************************/
   ~vector(void) { this->clear(); }

   /*****************************************************************************
   * begin: Returnerar adressen till f�rsta elementet i angiven vektor.
   *****************************************************************************/
   T* begin(void) const { return this->data; }

   /*****************************************************************************
   * end: Returnerar adressen direkt efter sista elementet i angiven vektor.
   *****************************************************************************/
   T* end(void) const { return this->data + this->size; }

   /*****************************************************************************
   * clear: T�mmer inneh�llet i angiven vektor.
   *****************************************************************************/
   void clear(void)
   {
      std::free(this->data);
      this->data = nullptr;
      this->size = 0;
      return;
   }

   /*****************************************************************************
   * push: L�gger till ett nytt element l�ngst bak i angiven vektor.
   * 
   *       - val: Det nya element som skall l�ggas till i vektorn.
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
   * print: Skriver ut inneh�llet lagrat i angiven vektor via angiven utstr�m,
   *        d�r standardutenhet std::cout anv�nds som default f�r utskrift 
   *        i terminalen.
   *  
   *        - ostream: Angiven utstr�m (default = std::cout).
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