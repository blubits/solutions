#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        string q;
        getline(cin, q);
        map<char, int> count;
        for (auto c : q) {
            if (count.find(c) == count.end())
                count[c] = 1;
            else
                count[c]++;
        }
        // calculate 'naive' time
        long long int naive = 0;
        int i = 0;
        map<char, int> q_naive;
        for (auto c : q) {
            if (q_naive.find(c) == q_naive.end())
                q_naive[c] = 1;
            else
                q_naive[c]++;
            if (count[c] == q_naive[c]) {
                naive += count[c] * i;
            }
            i++;
        }
        // calculate 'smart' time
        long long int smart = 0;
        i = 0;
        string newq;
        map<char, int> q_smart;
        for (auto c : q) {
            if (q_smart.find(c) == q_smart.end())
                q_smart[c] = 1;
            else
                q_smart[c]++;
            if (count[c] == q_smart[c]) {
                for (int i = 0; i < count[c]; i++) {
                    newq += c;
                }
            }
            i++;
        }
        q_smart.clear();
        i = 0;
        for (auto c : newq) {
            if (q_smart.find(c) == q_smart.end())
                q_smart[c] = 1;
            else
                q_smart[c]++;
            if (count[c] == q_smart[c]) {
                smart += count[c] * i;
            }
            i++;
        }
        // cout << newq << endl;
        cout << 5 * (naive - smart) << endl;
    }
    return 0;
}
