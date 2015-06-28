/* -------------------------------------------------------------------------
@file list.cpp

@date 06/28/15 19:44:48
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
list has a fast insert and remove


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
#include<iterator>
#include<algorithm>
#include<deque>
#include<list>
using namespace std;

int main(void)
{
    list<int> mylist{3,7,3};
    mylist.push_back(37); // {3,7,3,37}
    mylist.push_front(73); // {73, 3, 7, 3, 37}

    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 7); // itr -> 3
    mylist.insert(itr, 0); // {73, 3, 0, 3, 37}
    itr++;
    mylist.erase(itr);
    /* Properties:
     * 1. fast insert/remove at any place: O(1)
     * 2. slow search: O(n)
     * 3. no random access, no [] operator.
     */
    // c++ 11 for loop
    for(auto i: mylist)
        cout << i << endl;
    
    // list has a fast member function splice
    // mylist.splice(itr, mylist2, itr_a, itr_b); O(1)

    return 0;
    
}
