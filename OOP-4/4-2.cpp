#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector<bool> queue;

    for (int q = 0; q < Q; ++q) {
        string command;
        cin >> command;

        if (command == "WORRY") {
            int i;
            cin >> i;
            queue[i] = true;
        } else if (command == "QUIET") {
            int i;
            cin >> i;
            queue[i] = false;
        } else if (command == "COME") {
            int k;
            cin >> k;
            if (k > 0) {
                for (int j = 0; j < k; ++j) {
                    queue.push_back(false);
                }
            } else {
                for (int j = 0; j < -k; ++j) {
                    queue.pop_back();
                }
            }
        } else if (command == "WORRY_COUNT") {
            int count = 0;
            for (bool person : queue) {
                if (person) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
