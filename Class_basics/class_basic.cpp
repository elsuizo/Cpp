/*
Basics on classes
*/

#include<iostream>
#include<sstream>

using namespace std;

class Employee
{
private:
  string name;
  double pay;
public:
  Employee()
  {
    name = " ";
    pay = 0;
  }
  Employee(string empName, double payRate)
  {
    name = empName;
    pay = payRate;

  }
  // Geters
  string getName(){return name;}

  double getPay(){return pay;}

  //Seters
  void setName(string empName){name = empName;}

  void setPay(double payRate){pay = payRate;}

  // Show object method
  string toString()
  {
    stringstream stm;

    stm << name << ": " << pay;
    return stm.str();
  }
};

int main()
{
  // Created a employes
  Employee emp1("Martin Noblia", 3700);
  Employee emp2("elsuizo", 7300);
  // Show
  cout << emp1.toString() << endl;
  cout << emp2.toString() << endl;

  return 0;

}

