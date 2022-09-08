/********************************************************************************
* vector.cpp: Demonstration av dynamiska vektorer för lagring av element av
*             olika datatyper i C++ via klassen std::vector.
********************************************************************************/
#include <iostream>
#include <vector>

/********************************************************************************
* vector_print: Skriver ut innehållet lagrat i angiven vektor via angiven
*               utström, där standardutenhet std::cout används som default
*               för utskrift i terminalen.  
* 
*               - self   : Vektorn vars innehåll skall skrivas ut.
*               - ostream: Angiven utström (default = std::cout).
********************************************************************************/
template<class T>
static void vector_print(const std::vector<T>& self,
                         std::ostream& ostream = std::cout)
{
   if (!self.size()) return;
   ostream << "--------------------------------------------------------------------------------\n";

   for (auto& i : self)
   {
      ostream << i << "\n";
   }

   ostream << "--------------------------------------------------------------------------------\n\n";
   return;
}

/********************************************************************************
* main: Fyller två dynamiska vektorer med tal och skriver ut i terminalen.
*       Den första vektorn tilldelas tio heltal 0 - 9, medan den andra vektorn
*       tilldelas flyttal mellan 40 - 50 i steg om 0.5.
********************************************************************************/
int main(void)
{
   std::vector<int> v1;
   std::vector<double> v2;

   for (int i = 0; i < 10; ++i)
   {
      v1.push_back(i);
   }

   for (double i = 40; i <= 50; i += 0.5)
   {
      v2.push_back(i);
   }

   vector_print(v1);
   vector_print(v2);

   return 0;
}