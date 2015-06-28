/* -------------------------------------------------------------------------
@file vector_stl_basics.cpp

@date 06/28/15 17:33:18
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Overview of a stl Vector implementation and use, this is important for dont
reinvent the wheel¡¡¡
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
using namespace std;

int main(void)
{
    vector<int> vec; // created a vector object of ints
    vec.push_back(7); // use a object method for push a element in vec
    vec.push_back(3); 
    vec.push_back(7); // vec: {7,3,7}
    // Each container have a iterator protocol for walk on its elements
    vector<int>::iterator itr1 = vec.begin(); // pointer to the begin of elements
    vector<int>::iterator itr2 = vec.end(); // pointer to the end of elements
    //NOTE(elsuizo) the begin-end is half-open [begin,end)
    for(vector<int>::iterator itr = itr1; itr!=itr2; ++itr)
        cout << *itr << endl; // print 3 7 3 
    // Comments
    // the iterator behaviour is like a pointer, the for loop may be replace
    // for a short syntax(using auto)
    // as we know the algorithms apply on iterators not on containers(data types)
    // example
    sort(itr1, itr2);
     for(vector<int>::iterator itr = itr1; itr!=itr2; ++itr)
        cout << *itr << endl; 
    return 0;
}
