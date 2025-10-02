#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int Q;
    cin >> Q;

    int current_month = 0;
    vector<vector<string>> tasks(month_days[current_month]);

    for (int q = 0; q < Q; ++q) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int day;
            string task;
            cin >> day >> task;
            tasks[day - 1].push_back(task);

        } else if (command == "DUMP") {
            int day;
            cin >> day;
            cout << tasks[day - 1].size() << " ";
            for (const string& t : tasks[day - 1]) {
                cout << t << " ";
            }
            cout << endl;

        } else if (command == "NEXT") {
            int next_month = (current_month + 1) % 12;
            int current_len = month_days[current_month];
            int next_len = month_days[next_month];

            vector<vector<string>> old_tasks = tasks;

            tasks.resize(next_len);

            if (next_len < current_len) {
                for (int day = next_len; day < current_len; ++day) {
                    tasks[next_len - 1].insert(
                        tasks[next_len - 1].end(),
                        old_tasks[day].begin(),
                        old_tasks[day].end()
                    );
                }
            }

            current_month = next_month;
        }
    }

    return 0;
}
