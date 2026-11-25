/*
 * Program 4: Selection Sort
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;

        // Find the smallest element in the remaining unsorted portion.
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
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
    cout << "Program: Selection Sort\n\n";

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

    selectionSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
