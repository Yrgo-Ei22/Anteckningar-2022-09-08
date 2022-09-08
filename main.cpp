/********************************************************************************
* main.cpp: Demonstration av dynamiska vektorer för lagring av element av
*           olika datatyper i C++.
********************************************************************************/
#include "vector.hpp"

/********************************************************************************
* main: Fyller två dynamiska vektorer med tal och skriver ut i terminalen.
*       Den första vektorn tilldelas tio heltal 0 - 9, medan den andra vektorn
*       tilldelas flyttal mellan 40 - 50 i steg om 0.5.
********************************************************************************/
int main(void)
{
   vector<int> v1;
   vector<double> v2;

   for (int i = 0; i < 10; ++i)
   {
      v1.push(i);
   }

   for (double i = 40; i <= 50; i += 0.5)
   {
      v2.push(i);
   }

   v1.print();
   v2.print();

   return 0;
}