#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    int k;
    cin >> k;
    cin.ignore();
    vector<string> words(k);
    int end[200000], link[200000];
    for (int i = 0; i < k; i++) {
        end[i] = i;
        link[i] = i;
        getline(cin, words[i]);
    }
    int a, b;
    for (int i = 0; i < k - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        // update link[]
        link[end[a]] = b;
        // update end[]
        end[a] = end[b];
    }
    // for (int i = 0; i < k; i++) cout << end[i] + 1 << " ";
    // cout << endl;
    // for (int i = 0; i < k; i++) cout << link[i] + 1 << " ";
    // cout << endl;
    for (int i = 0; i < k; i++) {
        cout << words[a];
        a = link[a];
    }
    cout << endl;
}