#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t, x = 0, b = 1;
    scanf("%d", &t);
    vector<int> v;
    while (t != 0) {
        v.push_back(t % 2);
        t /= 2;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        x += v[i] * b;
        b *= 2;
    }
    printf("%d\n", x);
    return 0;
}
