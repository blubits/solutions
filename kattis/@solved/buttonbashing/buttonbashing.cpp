#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int b, target;
        cin >> b >> target;

        vector<int> buttons;
        for (int i = 0; i < b; i++) {
            int k;
            cin >> k;
            buttons.push_back(k);
        }

        queue<int> q;
        int distance[3601];
        for (int i = 1; i <= 3600; i++) distance[i] = 1000000000;
        distance[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto &button : buttons) {
                int next = curr + button;
                next = max(0, next);
                next = min(3600, next);
                if (distance[next] > distance[curr] + 1) {
                    distance[next] = distance[curr] + 1;
                    q.push(next);
                }
            }
        }
        for (int i = target; i <= 3600; i++) {
            if (distance[i] != 1000000000) {
                cout << distance[i] << " " << i - target << endl;
                break;
            }
        }
    }
}
