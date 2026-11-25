// Counting Sort
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n) {
  if (n <= 0) return;

  int mn = *min_element(arr, arr + n);
  int mx = *max_element(arr, arr + n);
  int range = mx - mn + 1;

  vector<int> count(range, 0), output(n);
  for (int i = 0; i < n; i++) count[arr[i] - mn]++;
  for (int i = 1; i < range; i++) count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i] - mn] - 1] = arr[i];
    count[arr[i] - mn]--;
  }
  for (int i = 0; i < n; i++) arr[i] = output[i];
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

  countingSort(arr.data(), n);

  cout << "After sorting: ";
  printArray(arr.data(), n);

  return 0;
}
