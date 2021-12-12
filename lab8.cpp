#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void createArray12(int * arr[], int * arr1, int n);
void printArray1(int * arr[], int n);
void printArray2(int * arr1, int n);
void printSortedArray(int * arr1, int n);
void sortShell(int * arr, int n);

int main(){
    srand(time(NULL));
    int n = 6, arr[n][n], arr1[n];
    int *p[n];
    for (int i = 0; i < n; i++) {
        p[i] = arr[i];
    }

    createArray12(p, arr1, n);
    cout<<"Array 1:"<<endl;
    printArray1(p,n);
    cout<<endl;
    cout<<"Array 2:"<<endl;
    printArray2(arr1, n);
    sortShell(arr1, n);
    cout<<endl;
    cout<<"\nSorted array: "<<endl;
    printSortedArray(arr1, n);

    system("pause");
}

void createArray12(int ** arr, int * arr1, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand()%(200)-100;
        }
        if (arr[i][i]>0) {
            arr1[i] = arr[i][i];
        } else {
            arr1[i] = 0;
        }
    }
}

void printArray1(int * arr[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<setw(5)<<arr[i][j];
        }
        cout<<endl;
    }
}

void printArray2(int * arr1, int n){
    for (int i = 0; i < n; i++) {
        cout<<setw(5)<<arr1[i];
    }
}

void printSortedArray(int * arr1, int n){
    for (int i = 0; i < n; i++) {
        if(arr1[i] != 0) {
            cout<<setw(5)<<arr1[i];
        }
    }
    cout<<endl;
}

void sortShell(int * arr, int n){
    int swap = 0, comp = 0, incr = n/2, temp, k;
    while (incr>0) {
        for (int i = 0; i < incr; i++) {
            for (int j = 0; j < n; j+=incr) {
                temp = arr[j];
                for (k = j-incr; k >= 0 && temp<arr[k]; k-=incr) {
                    comp++;
                    swap++;
                    arr[k+incr] = arr[k];
                }
                arr[k+incr] = temp;
                swap++;
            }
        }
        comp++;
        if (incr/2 != 0) {
            incr = incr/2;
        } else if (incr == 1) {
            incr = 0;
        } else{
            incr = 1;
        }
    }
}