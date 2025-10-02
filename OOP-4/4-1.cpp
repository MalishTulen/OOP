#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> temps(n);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> temps[i];
        total += temps[i];
    }

    int average = total / n;
    vector<int> above_avg_indices;

    for (int i = 0; i < n; i++) {
        if (temps[i] > average) {
            above_avg_indices.push_back(i);
        }
    }

    cout << above_avg_indices.size() << endl;

    for (int i = 0; i < above_avg_indices.size(); i++) {
        cout << above_avg_indices[i];
        if (i < above_avg_indices.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
