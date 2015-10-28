/* -------------------------------------------------------------------------
@file test1.cpp

@date 10/28/15 13:36:13
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
#include<iterator>
using namespace std;

ostream_iterator<string> oo {cout}; // write string to cout

int main()
{
    *oo = "Hello"; // meaning cout << "Hello";
    ++oo;
    *oo = "World!!!\n"; // meaning cout << "World!!!\n";

    return 0;
}

