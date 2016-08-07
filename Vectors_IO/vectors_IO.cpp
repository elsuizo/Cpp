/* -------------------------------------------------------------------------
@file vectors_IO.cpp

@date 08/03/16 10:08:48
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
#include<vector>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;

int main(void)
{
  int length; 
  cout << "Ingresa la cantidad de elementos del vector" << endl;
  cin >> length;
  cout << "Ingesa los elementos del vector" << endl;

  // reserva la cantidad de espacio para el vector
  vector<int> sequence; sequence.reserve(length);
  // pasa los elementos ingresados al vector
  copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));
  // suma los elementos del vector
  cout << "La suma de los elementos es: "<< accumulate(begin(sequence), end(sequence), 0)<<endl;
  copy(begin(sequence), end(sequence), ostream_iterator<int>(cout));
}

