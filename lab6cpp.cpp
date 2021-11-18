#include <iostream>
using namespace std;

int dob(int a,int b, int n);

int main(){
    int a=1,b=3,n=7,d;
    d = dob(a,b,n);
    cout<<"Product of arithmetic progression numbers = "<<d<<endl;
    system("pause");
}

int dob(int a,int b, int n){
    if(n<=0){
        return 1;
    }
    return a*dob(a+b,b,n-1);
}