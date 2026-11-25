/*
 * Program 3: Insertion Sort
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift larger elements one position right to make room for key.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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
    cout << "Program: Insertion Sort\n\n";

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

    insertionSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
