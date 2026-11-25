// Recursive Linear and Binary Search
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key, int i = 0) {
  if (i >= n) return -1;
  if (arr[i] == key) return i;
  return linearSearch(arr, n, key, i + 1);
}

int binarySearch(int arr[], int low, int high, int key) {
  if (low > high) return -1;
  int mid = low + (high - low) / 2;
  if (arr[mid] == key) return mid;
  if (key < arr[mid]) return binarySearch(arr, low, mid - 1, key);
  return binarySearch(arr, mid + 1, high, key);
}

int main() {
  cout << "Name: Samridh Chaudhary\n";
  cout << "Roll No: 2400320100976\n\n";

  int n, key;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << "Enter element to search: ";
  cin >> key;

  int pos1 = linearSearch(arr.data(), n, key);
  if (pos1 != -1) cout << "Linear Search: found at index " << pos1 << endl;
  else cout << "Linear Search: not found" << endl;

  sort(arr.begin(), arr.end());
  cout << "Sorted array for Binary Search: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  int pos2 = binarySearch(arr.data(), 0, n - 1, key);
  if (pos2 != -1) cout << "Binary Search: found at index " << pos2 << endl;
  else cout << "Binary Search: not found" << endl;

  return 0;
}
