#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long int k, n, w;
    cin >> k >> n >> w;
    long long int needed = k * w * (w + 1) / 2;
    cout << max((long long int)(0), needed - n) << endl;
}
