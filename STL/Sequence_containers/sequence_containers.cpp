/* -------------------------------------------------------------------------
@file sequence_containers.cpp

@date 06/28/15 18:49:24
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
Sequence container(vector and linked list):
vector, deque, list, forward list, array.
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
/*
STL Headers
#include <vector>
#include <deque>
#include <list>
#include <set>   // set and multiset
#include <map>   // map and multimap
#include <unordered_set>  // unordered set/multiset
#include <unordered_map>  // unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric>    // some numeric algorithm
#include <functional>
*/

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void)
{
    vector<int> vec; // vec.size() = 0
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(3); // vec.size() = 3

    // vector elements acces
    cout << vec[2]<< endl; // (no range check)
    cout << vec.at(2)<< endl; // throw a range-error exeption of out of range
    // for loop
    for(vector<int>::iterator itr = vec.begin(); itr!=vec.end(); ++itr)
        cout << *itr << endl;
        
    // all the containers have similar member functions
    if(vec.empty()){cout << "The vector is empty"<< endl;}
    // copy constructor
    vector<int> vec2(vec);
    // swap 
    vec2.swap(vec);
    /* Properties of Vector:
     * 1. fast insert/remove at the end: O(1)
     * 2. slow insert/remove at the begining or in the middle: O(n)
     * 3. slow search: O(n)
     */

    return 0;

        
}
