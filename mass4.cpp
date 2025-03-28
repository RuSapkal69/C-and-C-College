#include <iostream>

using namespace std;


class Rushikesh{
    public:
    //Constructor
    Rushikesh(){
        cout<<"Constructor called"<<endl;
    }
    //Destructor
    ~Rushikesh(){
        cout<<"Destructor called"<<endl;
    }

};
int main() {
    //Objects created
    Rushikesh obj1;
    Rushikesh obj2;
    Rushikesh obj3;

    cout<<"Objects created"<<endl;
    cout<<endl;

    //Address of objects
    cout<<"Address of objects"<<endl;
    cout<< &obj1 <<endl;
    cout<< &obj2 <<endl;
    cout<< &obj3 <<endl;
    cout<<endl;

    delete &obj1;
    delete &obj2;
    delete &obj3;
    cout<<endl;
    cout<<"Objects destroyed"<<endl;
    cout<<endl;
    cout<<"After deleting objects garbage values are printed"<<endl;
    cout<<endl;
    cout<< &obj1 <<endl;
    cout<< &obj2 <<endl;
    cout<< &obj3 <<endl;

    return 0;
}