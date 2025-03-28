#include<iostream>
using namespace std;

int main() {
    int i, dani[5] = {4,8,9,0,1};
    for (i=0; i<5; i++) {
        cout<<"\t"<<dani[i];
    }

    int *p = dani;
    cout<<"\nThe value of dani array at position 0 is "<<*p;
    cout<<"\nThe value of dani array at position 1 is "<<*(p+1);
    cout<<"\nThe value of dani array at position 2 is "<<*(p+2);
    cout<<"\nThe value of dani array at position 3 is "<<*(p+3);
    cout<<"\nThe value of dani array at position 4 is "<<*(p+4);


    return 0;

}