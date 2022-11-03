#include<bits/stdc++.h>
using namespace std;

class Base {};
class Derived : public Base {};

int main(){

    Derived d;
    // try{
    //     throw d;
    // }
    // catch(Base &e){
    //     cout<<"Base catch"<<endl;
    // }
    // catch(Derived &e){
    //     cout<<"Derived catch"<<endl;
    // }
    // this gives error as exception of Derived will be catched by base

    try{
        throw d;
    }
    catch(Derived &e){
        cout<<"Derived catch"<<endl;
    }
    catch(Base &e){
        cout<<"Base catch"<<endl;
    }
    //this works fine
}