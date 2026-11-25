// Selection Sort
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx]) minIdx = j;
    }
    swap(arr[i], arr[minIdx]);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  cout << "Name: Samridh Chaudhary\n";
  cout << "Roll No: 2400320100976\n\n";

  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << "Before sorting: ";
  printArray(arr.data(), n);

  selectionSort(arr.data(), n);

  cout << "After sorting: ";
  printArray(arr.data(), n);

  return 0;
}
