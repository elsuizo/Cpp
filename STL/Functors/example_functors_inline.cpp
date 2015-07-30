/* -------------------------------------------------------------------------
@file example_functors_inline.cpp

@date 07/29/15 21:16:08
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
#include<list>
using namespace std;


template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for(const auto& x : c)
        if(pred(x))
            ++cnt;
    return cnt;
}

void f(const vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "Number of values less than " << x
        << ": " << count(vec, [&](int a){return a<x ;})
        << '\n';
    cout << "Number of values less than " << s
        << ": " << count(lst, [&](const string& a){return a<s ;})
        << '\n';


}
int main(void)
{

    vector<int> vec; // created a vector object of ints
    vec.push_back(7); // use a object method for push a element in vec
    vec.push_back(3); 
    vec.push_back(7); // vec: {7,3,7}
    
    list<string> l {"a","b","F"} ;

    f(vec, l, 9, "d");

    return 0;

}
    




