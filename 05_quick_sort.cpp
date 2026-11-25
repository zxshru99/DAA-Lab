/*
 * Program 5: Quick Sort
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Places the pivot (last element) at its final sorted position.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int smallerEnd = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++smallerEnd;
            swap(arr[smallerEnd], arr[j]);
        }
    }

    swap(arr[smallerEnd + 1], arr[high]);
    return smallerEnd + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
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
    cout << "Program: Quick Sort\n\n";

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

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
