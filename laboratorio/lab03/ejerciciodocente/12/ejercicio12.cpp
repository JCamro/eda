#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {1,2,3,4};
    int suma = 0;
    for(int i = 0; i < arr.size(); i++)
        suma += arr[i];
    cout << "Suma: " << suma;
    return 0;
}
