/* -------------------------------------------------------------------------
@file template_basics.cpp

@date 06/28/15 16:33:27
@author Martin Noblia
@email martin@openmailbox.org

@brief
Templates allow us to use a function or method for a family of types, is 
similar to a mathematical expression: "for all T".
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
using namespace std;

// template for a square function
template <typename T> // T is the parameter
T square(T x)
{
    return x*x;
}

int main(void)
{
    cout << square<int>(3) << endl;
    cout << square<float>(3.7) << endl;
    return 0;
}
