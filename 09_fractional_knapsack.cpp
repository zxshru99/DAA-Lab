// Fractional Knapsack
// Name: Samridh Chaudhary
// Roll No: 2400320100976

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int id;
  double value, weight;
};

bool cmp(Item a, Item b) {
  double r1 = (a.weight > 0) ? a.value / a.weight : 0;
  double r2 = (b.weight > 0) ? b.value / b.weight : 0;
  return r1 > r2;
}

int main() {
  cout << "Name: Samridh Chaudhary\n";
  cout << "Roll No: 2400320100976\n\n";

  int n;
  double cap;
  cout << "Enter number of items: ";
  cin >> n;

  vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    items[i].id = i + 1;
    cout << "Enter value and weight of item " << i + 1 << ": ";
    cin >> items[i].value >> items[i].weight;
  }

  cout << "Enter knapsack capacity: ";
  cin >> cap;

  sort(items.begin(), items.end(), cmp);

  double ans = 0.0;
  for (int i = 0; i < n && cap > 0; i++) {
    if (items[i].weight <= 0) {
      ans += items[i].value;
      continue;
    }
    if (items[i].weight <= cap) {
      ans += items[i].value;
      cap -= items[i].weight;
      cout << "Item " << items[i].id << ": 100%\n";
    } else {
      double frac = cap / items[i].weight;
      ans += items[i].value * frac;
      cout << "Item " << items[i].id << ": " << fixed << setprecision(2) << frac * 100 << "%\n";
      cap = 0;
    }
  }

  cout << "Maximum profit = " << fixed << setprecision(2) << ans << endl;
  return 0;
}
