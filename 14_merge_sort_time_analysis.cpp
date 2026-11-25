#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int l, int mid, int r) {
  vector<int> L(arr.begin() + l, arr.begin() + mid + 1);
  vector<int> R(arr.begin() + mid + 1, arr.begin() + r + 1);

  int i = 0, j = 0, k = l;
  while (i < (int)L.size() && j < (int)R.size()) {
    if (L[i] <= R[j]) arr[k++] = L[i++];
    else arr[k++] = R[j++];
  }
  while (i < (int)L.size()) arr[k++] = L[i++];
  while (j < (int)R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

int main() {
  srand(time(0));
  int sizes[] = {5000, 10000, 20000, 40000, 80000, 160000, 320000};
  int count = sizeof(sizes) / sizeof(sizes[0]);

  cout << "\nn\tTime taken (microseconds)" << endl;
  for (int t = 0; t < count; t++) {
    int n = sizes[t];
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();

    long long time_taken = duration_cast<microseconds>(stop - start).count();
    cout << n << "\t" << time_taken << endl;
  }

  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
