/* -------------------------------------------------------------------------
@file class_template_specialized.cpp

@date 11/27/15 17:48:28
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

using namespace std;

template <typename T>
class Stack
{
    private:
        T datastore[100];

        int top;

    public:
        Stack(){top = -1;}

    void push(int num)
    {
        ++top;
        datastore[top] = num;
    }

    T pop()
    {
        int val = datastore[top];
        datastore[top] = 0;
        --top;
        return val;
    }

    T peek()
    {
        return datastore[top];
    }
};

// specialized templeta class for strings
template<>
class Stack<string>
{
    private:
        string datastore[100];

        int top;

    public:
        Stack(){top = -1;}

    void push(string val)
    {
        ++top;
        datastore[top] = val;
    }

    string pop()
    {
        string val = datastore[top];
        datastore[top] = "";
        --top;
        return val;
    }

    string peek()
    {
        return datastore[top];
    }
};
// main
int main()
{
    Stack<string> names;
    names.push("Martin");
    names.push("Alejandro");
    cout << names.peek() << endl;
    string name = names.pop();
    cout << names.peek() << endl;
    return 0;
}



