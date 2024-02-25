#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

string items;
string ordering;
vector<char> chars;
bool illegal[30][30];

char order[30];
bool visited[30];

bool outputted_anything = false;

void dfs(int n) {
    if (n == chars.size()) {                // if (final_state)
        for (int i = 0; i < n; i++) {       // output_final_state
            if (i != 0) cout << " ";
            cout << order[i];
        }
        cout << endl;
        outputted_anything = true;
    }
    for (auto c: chars) {                   // for (possible state)
        if (!visited[c - 'A']) {
            bool valid_placement = true;
            for (int i = 0; i < n; i++) {
                if (illegal[order[i] - 'A'][c - 'A']) valid_placement = false;
            }
            if (valid_placement) {          // if (state_is_valid)
                visited[c - 'A'] = true;    // set_state
                order[n] = c;
                dfs(n + 1);                 // go to state
                visited[c - 'A'] = false;   // unset_state
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        items.clear();
        ordering.clear();
        chars.clear();
        memset(illegal, false, sizeof(illegal));
        memset(visited, false, sizeof(visited));
        outputted_anything = false;

        cin.ignore();
        getline(cin, items);
        stringstream itemsin(items);
        char i;
        while (itemsin >> i) {
            //cout << i << endl;
            chars.push_back(i);
        }
        getline(cin, ordering);
        stringstream orderingin(ordering);
        string order;
        while (orderingin >> order) {
            int u = order[0] - 'A', v = order[2] - 'A';
            //cout << u << " " << v << endl;
            illegal[v][u] = true;
        }
    
        dfs(0);
        if (!outputted_anything) cout << "NO" << endl;
        if (T) cout << endl;
    }
    return 0;
}