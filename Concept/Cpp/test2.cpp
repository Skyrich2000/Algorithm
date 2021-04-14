#include <iostream>
using namespace std;

int main() {
    int size = 10;
    int tos = 0;

    int* p = new int[size];
    
    int* p;
    p = new int[size];

    //push
    p[tos++] = 10;  //새로운 값

    // pop
    int n = p[--tos];

    cout << n << endl;
    delete[] p;    
    return 0;
}