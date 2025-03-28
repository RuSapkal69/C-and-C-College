#include<iostream>
using namespace std;

int main() {

    int a = 5;
    int *c = &a;
    cout<<"The address of a is "<<&a;
    cout<<"\nThe address of a is "<<c;
    cout<<"\nThe value stored at c is "<<*c;
    int **b = &c;
    cout<<"\nThe address of c is "<<b;
    cout<<"\nThe address of c is "<<&c;
    cout<<"\nThe value at c is "<<*b;
    cout<<"\nThe value at value of c is "<<**b;
    return 0; 
}