#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[l + i];
  for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) arr[k++] = L[i++];
    else arr[k++] = R[j++];
  }
  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = R[j++];

  cout << "Merged [" << l << " to " << r << "] : ";
  for (int x = l; x <= r; x++) cout << arr[x] << " ";
  cout << endl;
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    cout << "Divide [" << l << " to " << r << "] into ";
    cout << "[" << l << " to " << mid << "] and ";
    cout << "[" << mid + 1 << " to " << r << "]" << endl;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  mergeSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
