#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int* arr = new int[n];
    
    int i = 0;

    while (i < n){
        arr[i] = (i + 1);
        i++;
    }

    int e = 0;

    while (e < n){
        cout << arr[e] << endl;
        e++;
    }
    
    delete[] arr;
    return 0;
}
