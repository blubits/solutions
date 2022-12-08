#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    vector<pair<int, int>> states;
    map<pair<int, int>, pair<int, int>> votes;
    int dtw = 0;
    while (t--) {
        int d, c, f, u;
        scanf("%d %d %d %d", &d, &c, &f, &u);
        auto k = make_pair(-d, u);
        auto v = make_pair(c, f);
        states.push_back(k);
        votes[k] = v;
        dtw += d;
    }
    dtw = (dtw / 2) + 1;
    sort(states.begin(), states.end());
    int cv = 0, fv = 0, n = 0;
    bool cw = false;
    for (auto s : states) {
        cout << s.second << " " << s.first << endl;
        auto tally = votes[s];
        auto cs = tally.first, fs = tally.second, delegates = -s.first,
             ss = s.second;
        printf("%d delegates\n", delegates);
        // guaranteed win
        if (cs > fs + ss) {
            cv += delegates;
        }
        // guaranteed lose
        else if (fs >= cs + ss) {
            fv += delegates;
        }
        // swing state
        else {
            // get gap
            int gap = cs - fs;
            // get half of votes
            int ud = ss / 2;
            // if this gap is negative, u need more votes
            if (gap > 0) {
                n += -gap;
                gap = 0;
            }
            n += ud - gap + 1;
            cv += delegates;
            printf("gap %d %d %d\n", gap, ud, ud - gap);
        }
        printf("del {%d to win} %d %d\n", dtw, cv, fv);
        if (cv >= dtw) {
            // you won!
            cw = true;
            break;
        }
    }
    if (cv >= dtw) {
        // you won!
        cw = true;
    } else if (fv >= (dtw - 1)) {
        // you lost :(
        cw = false;
    }
    if (cw)
        printf("%d\n", n);
    else
        printf("impossible\n");
    return 0;
}
