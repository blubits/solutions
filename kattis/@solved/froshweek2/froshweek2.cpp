#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> tasks(n), quiets(m);
    for (int i = 0; i < n; i++) cin >> tasks[i];
    for (int i = 0; i < m; i++) cin >> quiets[i];
    sort(tasks.begin(), tasks.end());
    sort(quiets.begin(), quiets.end());
    // try to match each task to a quiet interval
    int ta = 0;
    for (int t = 0, q = 0; t < n; t++) {
        while (q < m && tasks[t] > quiets[q]) q++;
        if (q != m)
            ta++;
        else
            break;
        q++;
    }
    cout << ta << endl;
}
