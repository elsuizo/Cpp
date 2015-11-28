/* -------------------------------------------------------------------------
@file word_count.cpp

@date 11/27/15 23:14:14
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
count words for a data input for the user
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

int main()
{
    cout << "Program for count the words enter for user" << endl;

    // variables
    vector<string> statements;
    string word;
    // while loop for read the words enter for the user and store in a vector
    // in a UNIX enviroment is terminate with Ctrl-d
    while(cin >> word)
        statements.push_back(word);

    // use a typedef for alias a type size
    typedef vector<string> :: size_type vec_sz;
    vec_sz size = statements.size();
    cout << "Words counts: " << size << endl;
    if(size == 0)
    {
        cout << "Error you must enter a word!!!" << endl;
        return 1;
    }


    return 0 ;
}


