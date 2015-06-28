/* -------------------------------------------------------------------------
@file deque.cpp

@date 06/28/15 19:29:42
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
#include<iterator>
#include<algorithm>
#include<deque>
using namespace std;

int main(void)
{
    deque<int> deq{3, 7, 3};
    deq.push_front(37); // {37, 3, 7, 3}
    deq.push_back(73); // {37, 3, 7, 3, 73}
    // deque has similar interface with vector
    cout << deq.at(1) << endl;
    /* Properties:
    * 1. fast insert/remove at the begining and the end;
    * 2. slow insert/remove in the middle: O(n)
    * 3. slow search: O(n)
    */
    return 0;

}
