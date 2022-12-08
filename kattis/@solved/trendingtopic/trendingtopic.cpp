#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    queue<unordered_map<string, int>> day_counters;
    unordered_map<string, int> week_counter;
    unordered_map<string, int> current_day_counter;
    string tok;
    while (cin >> tok) {
        if (tok == "<text>") {
            current_day_counter.clear();
        } else if (tok == "</text>") {
            // commit current day
            day_counters.push(current_day_counter);
            // place it in the counter
            for (auto p : current_day_counter) {
                auto word = p.first;
                auto count = p.second;
                if (week_counter.find(word) == week_counter.end()) {
                    week_counter[word] = count;
                } else {
                    week_counter[word] += count;
                }
            }
            if (day_counters.size() == 8) {
                // get earliest day
                auto outgoing_day_counter = day_counters.front();
                day_counters.pop();
                // remove it from the week counter
                for (auto p : outgoing_day_counter) {
                    auto word = p.first;
                    auto count = p.second;
                    week_counter[word] -= count;
                }
            }
        } else if (tok == "<top") {
            // extract number
            // get top 5
            int t;
            cin >> t >> tok;
            cout << "<top " << t << ">" << endl;
            vector<pair<int, string>> sorted_week_counter;
            for (auto p : week_counter) {
                sorted_week_counter.push_back({-p.second, p.first});
            }
            if (sorted_week_counter.size() == 0) {
                cout << "</top>" << endl;
                continue;
            }
            sort(sorted_week_counter.begin(), sorted_week_counter.end());
            int cnt = 0, curr = sorted_week_counter[0].first;
            for (int i = 0; i <= sorted_week_counter.size(); i++) {
                cnt++;
                if (curr != sorted_week_counter[i].first) {
                    if (cnt > t)
                        break;
                    else
                        curr = sorted_week_counter[i].first;
                }
                cout << sorted_week_counter[i].second << " "
                     << -sorted_week_counter[i].first << endl;
            }
            cout << "</top>" << endl;
        } else {
            if (tok.size() >= 4) {
                if (current_day_counter.find(tok) ==
                    current_day_counter.end()) {
                    current_day_counter[tok] = 1;
                } else {
                    current_day_counter[tok] += 1;
                }
            }
        }
    }
}
