// Quick Sort
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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

  quickSort(arr.data(), 0, n - 1);

  cout << "After sorting: ";
  printArray(arr.data(), n);

  return 0;
}
