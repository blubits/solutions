#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int t, c = 1;
    priority_queue<int> r, b;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (n--) {
            string rope;
            cin >> rope;
            if (rope[rope.size() - 1] == 'B')
                b.push(stoi(rope.substr(0, rope.size() - 1)));
            if (rope[rope.size() - 1] == 'R')
                r.push(stoi(rope.substr(0, rope.size() - 1)));
        }
        int dist = 0;
        while (!r.empty() && !b.empty()) {
            dist += r.top() + b.top() - 2;
            r.pop();
            b.pop();
        }
        cout << "Case #" << c++ << ": " << dist << endl;
        while (!r.empty()) r.pop();
        while (!b.empty()) b.pop();
    }
    return 0;
}
