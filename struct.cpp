#include<iostream>
using namespace std;

struct student
{
    int iD;
    char firstName;
    float phoneNo;
};

int main() {

    struct student Rushikesh;
    Rushikesh.iD = 22167;
    Rushikesh.firstName = 'R';
    Rushikesh.phoneNo = 9475.047;
    cout<<"\n"<<Rushikesh.iD;
    cout<<"\n"<<Rushikesh.firstName;
    cout<<"\n"<<Rushikesh.phoneNo;
}

