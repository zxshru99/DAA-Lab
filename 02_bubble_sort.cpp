/*
 * Program 2: Bubble Sort
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;

        // After each pass, the largest remaining element settles at the end.
        for (int j = 0; j < n - pass - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Stop early if the array is already in order.
        if (!swapped) {
            break;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    cout << "Name: Samridh Chaudhary\n";
    cout << "Roll No: 2400320100976\n";
    cout << "Program: Bubble Sort\n\n";

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

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
