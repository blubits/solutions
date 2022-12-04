#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

bool compare(int a, int b) {
    int am = a % m, bm = b % m;
    if (am == bm) {
        if (a % 2 == b % 2 || a % 2 == -(b % 2)) {
            if (a % 2 == 1 || a % 2 == -1) return a > b;
            else return a < b;
        }
        return a % 2;
    }
    return am < bm;
}

int main() {
    vector<int> ans;
    while (scanf("%d %d\n", &n, &m) && n != 0 && m != 0) {
        ans.clear();
        printf("%d %d\n", n, m);
        while (n--) {
            int num;
            cin >> num;
            ans.push_back(num);
        }
        sort(ans.begin(), ans.end(), compare);
        for (auto i: ans) cout << i << endl;
    }
    printf("0 0\n");
}