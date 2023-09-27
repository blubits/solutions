#include <bits/stdc++.h>

using namespace std;

int num_addends;
char addends[11][11];
char sum[11];

vector<char> unique_chars;
vector<int> char_assignments;
set<char> unique_charset;
map<char, int> char_map;
set<char> leftmost_letters;

int bitmask_nums = 0;
int bitmask_chars = 0;
int OK_nums = (1 << 10) - 1;
int OK_chars;

int valid_sums = 0;

void calculate(int pos) {
    if (bitmask_chars == OK_chars) {
        // calculate sum of assignment

        bool all_zeros = true;
        int col = 0;
        int pow = 1;
        int found_sum = 0;
        int actual_sum = 0;

        for (int i = 0; sum[i] != '\0'; i++) {
            actual_sum += char_map[sum[i]] * pow;
            pow *= 10;
        }

        pow = 1;
        do {
            all_zeros = true;
            for (int i = 0; i < num_addends; i++) {
                if (addends[i][col] != '\0') {
                    all_zeros = false;
                    found_sum += char_map[addends[i][col]] * pow;
                }
            }
            pow *= 10;
            col++;
        } while (!all_zeros);

        if (actual_sum == found_sum) {
            // for (auto i: char_assignments) {
            //     cout << i;
            // }
            //cout << " " << actual_sum << " " << found_sum << endl;
            valid_sums++;
        }

    } else {
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && leftmost_letters.find(unique_chars[pos]) != leftmost_letters.end()) {
                continue;
            }
            int check = 1 << i;
            if (!(bitmask_nums & check)) {
                char_assignments[pos] = i;
                char_map[unique_chars[pos]] = i;
                bitmask_nums |= check;
                bitmask_chars |= (1 << pos);
                calculate(pos + 1);
                bitmask_chars &= ~(1 << pos);
                bitmask_nums &= ~check;
            }
        }
    }
}

int main() {
    int T;
    while (cin >> T) {
        unique_chars.clear();
        char_assignments.clear();
        unique_charset.clear();
        char_map.clear();
        leftmost_letters.clear();
        bitmask_nums = 0;
        bitmask_chars = 0;
        valid_sums = 0;
        for (int i = 0; i < 11; i++) {
            sum[i] = '\0';
            for (int j = 0; j < 11; j++) {
                addends[i][j] = '\0';
            }
        }
        num_addends = T - 1;
        for (int i = 0; i < T - 1; i++) {
            string s;
            cin >> s;
            int j = 0;
            leftmost_letters.insert(s[0]);
            for (auto it = s.rbegin(); it < s.rend(); it++) {
                addends[i][j++] = *it;
                unique_charset.insert(*it);
            }
            addends[i][j] = '\0';
        }
        
        string s;
        cin >> s;
        int i = 0;
        leftmost_letters.insert(s[0]);
        for (auto it = s.rbegin(); it < s.rend(); it++) {
            sum[i++] = *it;
            unique_charset.insert(*it);
        }

        // for (int i = 0; i < T - 1; i++) {
        //     cout << addends[i] << endl;
        // }
        // cout << sum << endl;

        for (auto c: unique_charset) {
            unique_chars.push_back( c);
            char_assignments.push_back(-1);
            // cout << c;
        }
        // cout << endl;

        OK_chars = (1 << (unique_chars.size())) - 1;
        calculate(0);
        cout << valid_sums << endl;

    }
}