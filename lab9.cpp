#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void createMatr(float *matr[], int m, int n);
void printMatr(float *matr[], int m, int n);
void zeroElement(float *matr[], int m, int n);

int main(){
    srand(time(NULL));
    int m, n;
    cout<<"Enter variables M and N: ";
    cin>>m>>n;
    float matr[m][n];
    float *p[m];
    for (int i = 0; i < n; i++) {
        p[i] = matr[i];
    }
    createMatr(p, m, n);
    cout<<"First array: "<<endl;
    printMatr(p, m, n);
    zeroElement(p, m, n);
}

void createMatr(float *matr[], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = (float)(rand()%(20)-10);
        }
    }
}

void printMatr(float *matr[], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<setw(5)<<matr[i][j];
        }
        cout<<endl;
    }
}

void zeroElement(float *matr[], int m, int n){
    int indexCol = -1, indexRow = -1;
    for (int i = 0; i < m; i++)
    {
        if ((i+1)%2==0)
        {
            for (int j = n-1; j >= 0; j--)
            {
                if (matr[i][j] == 0)
                {
                    indexRow = i;
                    indexCol = j;
                }
            }
        } else {
            for (int j = 0; j < n; j++)
            {
                if (matr[i][j] == 0)
                {
                    indexRow = i;
                    indexCol = j;
                }
            }
        }  
    } 
    if (indexRow == -1 || indexCol == -1)
    {
        cout<<"There isn`t element '0' in the array!";
    } else {
        int b = matr[indexRow][0];
        matr[indexRow][0] = matr[indexRow][indexCol];
        matr[indexRow][indexCol] = b;
        cout<<"Result: "<<endl;
        printMatr(matr, m, n);
    }
}