#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (1) {
        int N, M;
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) return 0;

        vector<pair<int, int>> calls;
        bool is_active[N];

        for (int i = 0; i < N; i++) {
            is_active[i] = false;
            long long int s, d, start, duration;
            cin >> s >> d >> start >> duration;
            auto ps = make_pair(start, 1);
            auto pe = make_pair(start + duration, -1);
            calls.push_back(ps);
            calls.push_back(pe);
        }

        sort(calls.begin(), calls.end());

        // vector<pair<long long int, long long int>> active_calls;
        // long long int no_calls = 0;
        // for (auto pair : calls) {
        //     auto start = pair.first;
        //     auto id = pair.second;
        //     // cout << "    " << start << " " << id << endl;
        //     if (is_active[id]) {
        //         no_calls -= 1;
        //     } else {
        //         no_calls += 1;
        //     }
        //     is_active[id] = !is_active[id];
        //     // cout << start << " " << no_calls << endl;
        //     auto pp = make_pair(start, no_calls);
        //     active_calls.push_back(pp);
        // }

        while (M--) {
            long long int start, duration;
            cin >> start >> duration;
            long long int m = 0;
            // cout << start << " " << duration << endl;
            // for (auto p : active_calls) {
            //     auto istart = p.first;
            //     auto icalls = p.second;
            //     // cout << istart << " " << icalls << endl;
            //     if (istart <= start) {
            //         // cout << 1 << endl;
            //         m = icalls;
            //     } else if (istart >= start + duration) {
            //         // cout << 2 << endl;
            //         break;
            //     } else if (istart > start) {
            //         // cout << 3 << endl;
            //         m = max(m, icalls);
            //     }
            // }
            for (auto p : calls) {
                auto istart = p.first;
                auto itype = p.second;
                if (istart < start || istart == start && itype == -1) {
                    // cout << istart << "x" << itype << endl;
                    m += itype;
                    continue;
                } else if (istart >= start + duration) {
                    // cout << istart << "*" << itype << endl;
                    // cout << 2 << endl;
                    break;
                } else if (istart >= start && itype != -1) {
                    // cout << 3 << endl;
                    // cout << istart << " " << itype << endl;
                    m += itype;
                }
            }
            cout << m << endl;
        }
    }
}
