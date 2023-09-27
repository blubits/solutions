#include <bits/stdc++.h>
using namespace std;

bool is_valid_date(vector<int> &date) {
    int day = (date[6] * 10) + date[7];
    int month = (date[4] * 10) + date[5];
    int year = (date[0] * 1000) + (date[1] * 100) + (date[2] * 10) + date[3];
    if (year < 2000) return false;
    bool is_leap_year = (year % 4 == 0);
    if (year % 100 == 0) is_leap_year = false;
    if (year % 400 == 0) is_leap_year = true;
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 1 <= day && day <= 30;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 1 <= day && day <= 31;
        case 2:
            return (1 <= day && day <= 28) || (is_leap_year && day == 29);
        default:
            return false;
    }
}

int main() {
    int T;
    cin >> T;
    vector<int> date;
    vector<int> first_date;
    while (T--) {
        int ans = 0;
        first_date.clear();
        date.clear();
        for (int i = 0; i <= 7; i++) {
            char c;
            cin >> c;
            if (c != ' ' && c != '\n') date.push_back(c - '0');
        }
        sort(date.begin(), date.end());
        do {
            if (is_valid_date(date)) {
                ans++;
                if (first_date.empty()) {
                    first_date.resize(8);
                    copy(date.begin(), date.end(), first_date.begin());
                }
            }
        } while (next_permutation(date.begin(), date.end()));
        cout << ans;
        if (ans != 0) {
            cout << " ";
            cout << first_date[6] << first_date[7];
            cout << " ";
            cout << first_date[4] << first_date[5];
            cout << " ";
            cout << first_date[0] << first_date[1] << first_date[2] << first_date[3];
        }
        cout << endl;
    }
}