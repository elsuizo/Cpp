/*
Ternary operator of C++

*/

#include<iostream>

using namespace std;

int main()
{
  int a, b;
  cout << "Ingresa el valor de a:" << endl;
  cin >> a;
  cout << "Ingresa el valor de b:" << endl;
  cin >> b;
  cout << (a > b ? a : b) << " es mayor" << endl;

  return 0;
  
}
