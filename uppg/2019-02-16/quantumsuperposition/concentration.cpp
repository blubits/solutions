#include <bits/stdc++.h>
using namespace std;

bool arr[2000000];
int ant[2000000], mat[2000000];
int a, b, c, d, n, r;

void rec(int p) {
    if (p == 1) {
        if (b == 2 * n) return;
        while (arr[mat[b]]) {
            ++b;
            if (b == 2 * n) return;
        }
        arr[mat[b]] = 1;
        r = mat[b];
        if (arr[mat[b] + 1 - 2 * (mat[b] % 2)]) {
            ++d;
            rec(1);
        } else {
            while (arr[mat[b]]) {
                ++b;
                if (b == 2 * n) return;
            }
            arr[mat[b]] = 1;
            if (mat[b] + 1 - 2 * (mat[b] % 2) == r) {
                ++d;
                rec(1);
            } else if (arr[mat[b] + 1 - 2 * (mat[b] % 2)]) {
                ++c;
                rec(0);
            } else
                rec(0);
        }
    } else {
        if (a == 2 * n) return;
        while (arr[ant[a]]) {
            ++a;
            if (a == 2 * n) return;
        }
        arr[ant[a]] = 1;
        r = ant[a];
        if (arr[ant[a] + 1 - 2 * (ant[a] % 2)]) {
            ++c;
            rec(0);
        } else {
            while (arr[ant[a]]) {
                ++a;
                if (a == 2 * n) return;
            }
            arr[ant[a]] = 1;
            if (ant[a] + 1 - 2 * (ant[a] % 2) == r) {
                ++c;
                rec(0);
            } else if (arr[ant[a] + 1 - 2 * (ant[a] % 2)]) {
                ++d;
                rec(1);
            } else
                rec(1);
        }
    }
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i != 2 * n; ++i) cin >> ant[i];
    for (int i = 0; i != 2 * n; ++i) cin >> mat[i];
    a = b = c = d = 0;
    rec(0);
    if (c > d)
        cout << 0 << endl;
    else if (c < d)
        cout << 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}
