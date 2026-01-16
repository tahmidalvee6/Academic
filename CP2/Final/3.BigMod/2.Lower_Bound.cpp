#include <bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int n, int target) {
    int left = 0, right = n; // right = n
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // index of first >= target
}

int main() {
    int n, target;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> target;

    int lb = lowerBound(arr, n, target);
    cout << "Lower Bound index: " << lb;
    return 0;
}



/*
🔗 Practice Problems

Codeforces

https://codeforces.com/problemset/problem/977/C

https://codeforces.com/problemset/problem/706/B



LeetCode

https://leetcode.com/problems/search-insert-position/

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
