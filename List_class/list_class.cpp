/* -------------------------------------------------------------------------
@file list_class.cpp

@date 11/28/15 23:22:02
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
 Program for manipulate class templates 
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

using namespace std;

template <typename T>
class List
{
    private:
        vector<T> datastore;
    public:
        List()
        {

        }
        void add(T item)   
        {
            datastore.push_back(item);
        }

        void display()
        {
            for(int i=0; i < datastore.size(); ++i)
                cout << datastore[i] << endl;
        }

};

int main()
{
    List<string> grocery;
    grocery.add("Mermelada");
    grocery.add("Agua");
    grocery.add("Manzanas");
    grocery.display();
    // list of ints
    List<int> num;
    num.add(37);
    num.add(373);
    num.add(73);
    num.display();
    return 0;
}

