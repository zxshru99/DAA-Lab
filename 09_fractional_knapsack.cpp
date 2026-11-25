/*
 * Program 9: Fractional Knapsack (Greedy)
 * Name: Samridh Chaudhary
 * Roll No: 2400320100976
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    double weight;
    double value;
};

double ratioOf(const Item& item) {
    return (item.weight > 0.0) ? (item.value / item.weight) : 0.0;
}

int main() {
    cout << "Name: Samridh Chaudhary\n";
    cout << "Roll No: 2400320100976\n";
    cout << "Program: Fractional Knapsack\n\n";

    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of items must be positive.\n";
        return 0;
    }

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i].id = i + 1;
        cout << "Enter value and weight for item " << items[i].id << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Capacity cannot be negative.\n";
        return 0;
    }

    // Greedy choice: pick items with the highest value-to-weight ratio first.
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return ratioOf(a) > ratioOf(b);
    });

    double totalValue = 0.0;
    double remaining = capacity;

    cout << "\nSelected items:\n";
    cout << fixed << setprecision(2);

    for (const Item& item : items) {
        if (item.weight <= 0) {
            if (item.value > 0) {
                totalValue += item.value;
                cout << "Item " << item.id << ": 100.00% (weight 0, value " << item.value << ")\n";
            }
            continue;
        }

        if (remaining <= 0) {
            break;
        }

        if (item.weight <= remaining) {
            remaining -= item.weight;
            totalValue += item.value;
            cout << "Item " << item.id << ": 100.00% (value " << item.value << ")\n";
        } else {
            double fraction = remaining / item.weight;
            double gained = item.value * fraction;
            totalValue += gained;
            remaining = 0.0;
            cout << "Item " << item.id << ": " << (fraction * 100.0)
                 << "% (value " << gained << ")\n";
        }
    }

    cout << "\nMaximum value in knapsack = " << totalValue << "\n";

    return 0;
}
