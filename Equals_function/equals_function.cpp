/* -------------------------------------------------------------------------
@file equals_function.cpp

@date 11/27/15 21:44:53
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

using namespace std;

template<typename T>

bool isEqual(T value, T value2)
{return value == value2 ? true: false;}

int main()
{
    int a{2}, b{4}, c{3}, d{3};
    string word1{"Hello"}, word2{"Hello"};
    cout << "Is equals a and b?: " << isEqual(a, b)<<endl;
    cout << "Is equals c and d?: " << isEqual(c, d)<<endl;
    cout << "Is equals word1 and word2?: " << isEqual(word1, word2)<<endl;
    return 0 ;
}
