/* -------------------------------------------------------------------------
@file templates_with_multiple.cpp

@date 11/27/15 18:04:39
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include<iostream>
//-------------------------------------------------------------------------
// NOTE parece que no se pueden poner types con numeros como T1, T2...
// cuando pongo T1, T2 no compila 
using namespace std;

template<typename T, typename U>
T max(T arg1, U arg2)
{
    return (arg1 > arg2) ? arg1 : arg2;
}

int main()
{
   double num = 37.73;
   int num2 = 31;
   cout << "Num is:" << max(num, num2) << endl;
   return 0;
}

