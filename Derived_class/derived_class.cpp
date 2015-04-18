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

// Derived class
class Manager : public Employee
{
private:
  bool salaried;

public:
  Manager(string empName, double payRate, bool isSalaried)
    : Employee(empName, payRate)
  {
    salaried = isSalaried;
  }
  //Geter for salary
  bool getSalaried(){return salaried;}
  
};

int main()
{
  // Created a employes
  Employee emp1("Martin Noblia", 3700);
  Manager emp2("elsuizo", 7300, true);
  // Show 
  cout << emp1.toString() << endl;
  cout << emp2.toString() << endl;
  cout << "Employed 2 is salaried?: "<< emp2.getSalaried() << endl;
  return 0;
  
}

