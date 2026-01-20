#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> target;

    int left = 0, right = n - 1;
    int index = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            index = mid;
            break;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if(index != -1)
        cout << "Found at index " << index;
    else
        cout << "Not Found";

    return 0;
}




/*
🔗 Practice Problems

Codeforces

https://codeforces.com/problemset/problem/474/B

https://codeforces.com/problemset/problem/706/B



LeetCode

https://leetcode.com/problems/binary-search/
*/
