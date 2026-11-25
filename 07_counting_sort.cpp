/*
 * Program 7: Counting Sort
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Shift by minVal so negative numbers are handled cleanly too.
    vector<int> count(range, 0);
    for (int x : arr) {
        ++count[x - minVal];
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // Iterate backwards to preserve stability for equal elements.
    vector<int> output(arr.size());
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
        int pos = --count[arr[i] - minVal];
        output[pos] = arr[i];
    }

    arr = output;
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
    cout << "Program: Counting Sort\n\n";

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

    countingSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
