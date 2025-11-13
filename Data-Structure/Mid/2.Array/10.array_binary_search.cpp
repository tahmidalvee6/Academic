// Binary search 

#include <iostream>
using namespace std;
int main() {
    int arr[] = {5, 7, 9, 12, 15, 20, 24, 27, 33, 40, 50, 65, 72}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target, iterations = 0;

    cout << "Enter target value: ";
    cin >> target;

    int l = 0, r = n - 1, foundIndex = 0; 

    while (l <= r) {
        iterations++;
        
        int mid = (l + r) / 2; 

        if (arr[mid] == target) {
            foundIndex = mid; 
            break;
        }
        else if (arr[mid] < target)
            l = mid + 1; 
        else
            r = mid - 1; 
    }

    if (foundIndex != 0) {
        cout<<"Element found at index "<<foundIndex<<endl;
    }
    else { 
        cout<< "Element not found" << endl;
    }
    
    cout << "Number of iterations: " << iterations << endl;

}


// Time Complexity :
// Best Case : O(1)
// Worst Case : O(logn)
