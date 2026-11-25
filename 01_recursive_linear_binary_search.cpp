/*
 * Program 1: Recursive Linear Search and Binary Search
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursively checks each element from left to right.
int recursiveLinearSearch(const vector<int>& arr, int index, int target) {
    if (index >= static_cast<int>(arr.size())) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return recursiveLinearSearch(arr, index + 1, target);
}

// Recursively halves the search range on a sorted array.
int recursiveBinarySearch(const vector<int>& arr, int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    }
    if (target < arr[mid]) {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }
    return recursiveBinarySearch(arr, mid + 1, high, target);
}

int main() {
    cout << "Name: Samridh Chaudhary\n";
    cout << "Roll No: 2400320100976\n";
    cout << "Program: Recursive Linear and Binary Search\n\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int linearIdx = recursiveLinearSearch(arr, 0, target);
    if (linearIdx != -1) {
        cout << "[Linear Search] Found at index " << linearIdx << " (0-based).\n";
    } else {
        cout << "[Linear Search] Element not found.\n";
    }

    // Binary search requires a sorted array, so sort a copy if needed.
    vector<int> sortedArr = arr;
    if (!is_sorted(sortedArr.begin(), sortedArr.end())) {
        sort(sortedArr.begin(), sortedArr.end());
        cout << "Sorted array for Binary Search: ";
        for (int x : sortedArr) {
            cout << x << " ";
        }
        cout << "\n";
    }

    int binaryIdx = recursiveBinarySearch(sortedArr, 0, n - 1, target);
    if (binaryIdx != -1) {
        cout << "[Binary Search] Found at index " << binaryIdx << " in sorted array.\n";
    } else {
        cout << "[Binary Search] Element not found.\n";
    }

    return 0;
}
