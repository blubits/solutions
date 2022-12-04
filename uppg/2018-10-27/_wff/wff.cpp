#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;
    while (x != "0") {
        deque<string> wffs;
        stack<string> nots;
        stack<string> joins;
        for (char c : x) {
            string s(1, c);
            if (s == "p" || s == "q" || s == "r" || s == "s" || s == "t") {
                wffs.push_back(s);
            } else if (s == "N") {
                nots.push(s);
            } else {
                joins.push(s);
            }
        }
        if (wffs.size() == 0) {
            cout << "no WFF possible" << endl;
            cin >> x;
            continue;
        }
        // finish nots
        while (nots.size() != 0) {
            string s = wffs.front();
            wffs.pop_front();
            wffs.push_back("N" + s);
            nots.pop();
        }
        // finish ands
        while (wffs.size() != 1 && joins.size() != 0) {
            string join = joins.top();
            joins.pop();
            string p1 = wffs.back();
            wffs.pop_back();
            string p2 = wffs.back();
            wffs.pop_back();
            wffs.push_back(join + p1 + p2);
        }
        cout << wffs.back() << endl;
        cin >> x;
    }
}
