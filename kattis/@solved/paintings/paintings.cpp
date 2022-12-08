#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// problem vars
int N = 0;
string colors[200] = {};
bool hideous_pairs[200][200] = {};
map<string, int> color_to_int;

// state var
int config[200] = {};
int state_size = 0;
bool was_picked[200] = {};

// answer vars
int num_paintings = 0;
vector<string> first_config;

void clear() {
    N = 0;
    num_paintings = 0;
    first_config.clear();
    color_to_int.clear();
    for (int i = 0; i < 200; i++) {
        was_picked[i] = false;
        for (int j = 0; j < 200; j++) {
            hideous_pairs[i][j] = false;
        }
    }
}

bool is_valid(int i) {
    if (state_size == 0) return true;
    if (was_picked[i]) return false;
    return !hideous_pairs[i][config[state_size - 1]];
}

void find_paintings(int i) {
    if (i == N) {
        if (num_paintings++ == 0) {
            for (int k = 0; k < state_size; k++)
                first_config.push_back(colors[config[k]]);
        }
        return;
    }
    for (int c = 0; c < N; c++) {
        if (is_valid(c)) {
            config[state_size++] = c;
            was_picked[c] = true;
            find_paintings(i + 1);
            state_size--;
            was_picked[c] = false;
        }
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        clear();
        int nc, np;
        cin >> nc;
        while (nc--) {
            string color;
            cin >> color;
            colors[N] = color;
            color_to_int[color] = N;
            N++;
        }
        cin >> np;
        while (np--) {
            string c1, c2;
            cin >> c1 >> c2;
            hideous_pairs[color_to_int[c1]][color_to_int[c2]] = true;
            hideous_pairs[color_to_int[c2]][color_to_int[c1]] = true;
        }

        find_paintings(0);

        cout << num_paintings << endl;
        for (int i = 0; i < first_config.size(); i++) {
            if (i != 0) cout << " ";
            cout << first_config[i];
        }
        cout << endl;

    }
}
