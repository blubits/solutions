#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> previous(200, 0);

int main() {
    int bk, to;
    cin >> bk;
    while (cin >> to && to != -1) {
        if (previous[to] == 0) previous[to] = -1;
        int fr;
        while (cin.peek() != '\n') {
            cin >> fr;
            previous[fr] = to;
        }
    }
    int root;
    for (int i = 1; i <= 200; i++) {
        if (previous[i] == -1) {
            root = i;
            break;
        }
    }
    int n = bk;
    stack<int> path;
    while (previous[n] != -1) {
        cout << n << " ";
        n = previous[n];
    }
    cout << root << endl;
}
