#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

const int TREE_NODE = 12345;
const int CYCLE_NODE = 54321;

int n, q;
vi succ;
vector<vi> adj_t;

map<int, int> cycle_length;

vector<bool> visited;
vi cycle_id;
vi cycle_posn;
vi dist_from_cycle;
vi attachment_to_cycle;
int cycle_timer = 0;

int succ_bin[32][200010];

// TODO: Explore alternate solution of numbering everything
// to reduce # of cases to 3.

void calculate_successors() {
    int MAX_K = 29; 
    for (int v = 0; v <= n; v++) { succ_bin[0][v] = succ[v]; }
    for (int k = 1; k <= MAX_K; k++) {
        for (int v = 0; v <= n; v++) {
            succ_bin[k][v] = succ_bin[k - 1][succ_bin[k - 1][v]];
        }
    }
}

int get_successor(int v, int k) {
    int MAX_K = 29; 
    for (int p = 0; p <= MAX_K; p++) {
        if (k & (1 << p)) {
            v = succ_bin[p][v];
        }
    }
    return v;
}

void fill_tree(int v, int dist, int mu) {
	for (auto n: adj_t[v]) {
        if (cycle_id[n] != -1) continue;
        if (dist_from_cycle[n] != -1) continue;
        visited[n] = true;
		dist_from_cycle[n] = dist + 1;
        attachment_to_cycle[n] = mu;
		fill_tree(n, dist + 1, mu);
	}
}

void fill(int v) {
    visited[v] = true;
    int a = v, b = v;

    // Find start of cycle
	do {
		a = succ[a];
		b = succ[succ[b]];
	} while (a != b);
	a = v;
	while (a != b) {
		a = succ[a];
		b = succ[b];
	}
	int mu = a;
    int lambda = 1;
	b = succ[b];
	while (a != b) {
		b = succ[b];
		lambda++;
	}

    // Set info for everything in the cycle
    // cycle_id[b] = cycle_timer
    // cycle_posn[b] = cycle_posn_timer
    cycle_length[cycle_timer] = lambda;
    int cycle_posn_timer = 0;
    do {
        cycle_id[b] = cycle_timer;
        cycle_posn[b] = cycle_posn_timer++;
        visited[b] = true;
        b = succ[b];
    } while (a != b);

    // Set info for every tree poking out of the cycle
    do {
		fill_tree(b, 0, b);
		b = succ[b];
	} while (b != mu);

    cycle_timer++;
}

tuple<int, int, int> identify_node(int v) {
    if (cycle_id[v] == -1) {
        printf("%d: tree (%d, %d)\n", v, attachment_to_cycle[v], dist_from_cycle[v]);
        return {TREE_NODE, attachment_to_cycle[v], dist_from_cycle[v]};
    } else {
        printf("%d: cycle (%d, %d)\n", v, cycle_id[v], cycle_posn[v]);
        return {CYCLE_NODE, cycle_id[v], cycle_posn[v]};
    }
}

bool in_same_component(int u, int v) {
    return cycle_id[succ_bin[29][u]] == cycle_id[succ_bin[29][v]]; 
}

int main() {
    cin >> n >> q;
    succ.resize(n);
    adj_t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> succ[i];
        succ[i]--;
        adj_t[succ[i]].push_back(i);
    }
    visited.resize(n);
    cycle_id.resize(n, -1);
    cycle_posn.resize(n, -1);
    dist_from_cycle.resize(n, -1);
    attachment_to_cycle.resize(n, -1);

    // Precalculate for queries
    calculate_successors();
    for (int i = 0; i < n; i++) {
        if (!visited[i]) fill(i);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (!in_same_component(a, b)) {
            cout << -1 << endl;
            continue;
        }
        auto a_info = identify_node(a), b_info = identify_node(b);
        int a_type = get<0>(a_info), b_type = get<0>(b_info);
        if (a_type == CYCLE_NODE && b_type == CYCLE_NODE) {
            int a_posn = get<2>(a_info), b_posn = get<2>(b_info);
            int a_cycle_id = get<1>(a_info);
            if (a_posn <= b_posn) cout << b_posn - a_posn << endl;
            else cout << cycle_length[a_cycle_id] - (a_posn - b_posn) << endl;
        } else if (a_type == CYCLE_NODE && b_type == TREE_NODE) {
            cout << -1 << endl;
        } else if (a_type == TREE_NODE && b_type == CYCLE_NODE) {
            // a->c + c->b, c = mu
            int ans = dist_from_cycle[a];
            int c = attachment_to_cycle[a];
            int c_posn = cycle_posn[c];
            int b_cycle_id = get<1>(b_info);
            int b_posn = get<2>(b_info);
            if (c_posn <= b_posn) ans += b_posn - c_posn;
            else ans += cycle_length[b_cycle_id] - (c_posn - b_posn);
            cout << ans << endl;
        } else {
            int a_dist = get<2>(a_info), b_dist = get<2>(b_info);
            if (a_dist < b_dist) cout << -1 << endl;
            else {
                int distance_to_hop = a_dist - b_dist;
                if (get_successor(a, distance_to_hop) == b) {
                    cout << distance_to_hop << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}