// Naive vector implementation
#include<iostream>
using namespace std;

struct Vector
{
    int sz; // number of elements
    double* elem; // pointer to elements
};

// Initialization of Vector

void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; // allocate a array of doubles
    v.sz = s;
}

double read_sum(int s)
{
    Vector v;
    vector_init(v, s);
    for(int i=0; i!=s; ++i)
        cin >> v.elem[i]; //read the elements

    double sum = 0;
    for(int i=0; i!=s; ++i)
        sum += v.elem[i];
    
    return sum;
}



int main()
{   int a = 7;
    double sum;
    sum = read_sum(a);
    cout << "The sum of elements is: " << sum << endl;
    return 0;
}
