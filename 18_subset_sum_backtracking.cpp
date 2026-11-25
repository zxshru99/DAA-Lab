#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d;
vector<int> S;
vector<int> subset;
bool found = false;

void subsetSum(int index, int currSum, int remaining) {
  if (currSum == d) {
    found = true;
    cout << "{ ";
    for (int i = 0; i < (int)subset.size(); i++) cout << subset[i] << " ";
    cout << "}" << endl;
    return;
  }
  if (index == n || currSum > d || currSum + remaining < d)
    return;

  // include S[index]
  subset.push_back(S[index]);
  subsetSum(index + 1, currSum + S[index], remaining - S[index]);
  subset.pop_back(); // backtrack

  // exclude S[index]
  subsetSum(index + 1, currSum, remaining - S[index]);
}

int main() {
  cout << "Enter number of elements: ";
  cin >> n;
  S.resize(n);
  cout << "Enter the elements: ";
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
    total += S[i];
  }
  cout << "Enter the required sum d: ";
  cin >> d;
  sort(S.begin(), S.end());

  cout << "Subsets with sum " << d << ":" << endl;
  subsetSum(0, 0, total);
  if (!found)
    cout << "No subset with the given sum exists" << endl;
  cout << "This program is executed by Samridh Chaudhary (Roll No: 2400320100976)" << endl;
  return 0;
}
