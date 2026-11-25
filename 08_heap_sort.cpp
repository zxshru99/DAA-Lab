/*
 * Program 8: Heap Sort
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Restores the max-heap property for a subtree rooted at index `root`.
void heapify(vector<int>& arr, int heapSize, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, heapSize, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    // Build max-heap bottom-up from the last non-leaf node.
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Move the current maximum to the end and shrink the heap.
    for (int end = n - 1; end > 0; --end) {
        swap(arr[0], arr[end]);
        heapify(arr, end, 0);
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
    cout << "Program: Heap Sort\n\n";

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

    heapSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
