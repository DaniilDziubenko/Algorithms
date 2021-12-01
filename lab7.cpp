#include <iostream>
using namespace std;

void createArr12(char arr1[10],char arr2[10], int n);
void createArr3(char arr1[10],char arr2[10], char arr3[10], int n);
int count(char arr3[10], int n);

int main(){
    int n = 10;
    char arr1[10], arr2[10], arr3[10];

    createArr12(arr1, arr2, n);
    cout<<endl;
    createArr3(arr1, arr2, arr3, n);
    cout<<endl;
    count(arr3, n);
    system("pause");
}

void createArr12(char arr1[10],char arr2[10], int n){
    for (int i = 0; i < n; i++)
    {
        arr1[i] = i*i + 76;
        arr2[i] = 85 - i;
    }
    cout<<"Array 1: ";
    for (int i = 0; i < n; i++)
    {
        cout<<int(arr1[i])<<' ';
    }
    cout<<endl;
    cout<<"Array 2: ";
    for (int i = 0; i < n; i++)
    {
        cout<<int(arr2[i])<<' ';
    }
}

void createArr3(char arr1[10],char arr2[10], char arr3[10], int n) {
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        for (int j = 0; j < n; j++)
        {
            if(arr1[i] == arr2[j]){
                a++;
            }
        }
        if(a>0){
            arr3[i] = arr1[i];
        } else{
            arr3[i] = 0;
        }
    }
    cout<<"Array 3: ";
    for (int i = 0; i < n; i++)
    {
        if(arr3[i] != 0){
            cout<<int(arr3[i])<<' ';
        }
    }
}

int count(char arr3[10], int n){
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr3[i] % 5 == 0 && arr3[i] != 0){
            b++;
        }
    }
    cout<<b<<endl;
}