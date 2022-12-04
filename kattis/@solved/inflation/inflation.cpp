#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    vector<int> balloons(a), canisters(a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &canisters[i]);
        balloons[i] = i + 1;
    }
    sort(canisters.begin(), canisters.end());
    double minf = 100;
    for (int i = 0; i < a; i++) {
        double f = double(canisters[i]) / double(balloons[i]);
        if (f > 1) minf = -1;
        minf = min(minf, f);
    }
    if (minf == -1)
        printf("impossible\n");
    else
        printf("%lf\n", minf);
    return 0;
}
