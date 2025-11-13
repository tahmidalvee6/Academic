// Declaration and Initilization of Linear Array

#include<iostream>
using namespace std;
int main() {
    int arr[5] = {10,20,30,40,50};      // array declaration and initialization

    for(int i = 0; i < 5; i++) {         // print the array
        cout<<arr[i]<<" ";
    }
}

// Memory allocation for 1D array :
// Formula : Address of arr[i] = Base Address + (i * Size of Data Type)
// Example : arr[3] = 1000 + (3 * 4) = 1012
