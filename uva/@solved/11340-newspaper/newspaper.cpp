#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int cost[10000] = {0};
        int k;
        cin >> k;
        cin.ignore();
        while (k--) {
            unsigned char c;
            unsigned long long int p;
            scanf("%c %llu\n", &c, &p);
            cost[int(c) + 128] = p;
        }
        cin >> k;
        unsigned long long int total = 0;
        string s;
        cin.ignore();
        while (k--) {
            getline(cin, s);
            for (auto c : s) {
                total += cost[int(c) + 128];
            }
        }
        printf("%llu.%02llu$\n", total / 100, total % 100);
    }
    return 0;
}
