/* -------------------------------------------------------------------------
@file concatenated.cpp

@date 08/14/15 20:45:24
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

#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string compose(const string& name, const string& domain)
{
    return name + '@' + domain;
}

int main(void)
{
    string name;
    string domain, count;
    cout << "user: " << endl;
    cin >> name;
    cout << "Domain : " << endl;
    cin >> domain;
    count = compose(name, domain);
    cout << "Your email is :" << endl;
    cout << count << endl;

    return 0;
}
