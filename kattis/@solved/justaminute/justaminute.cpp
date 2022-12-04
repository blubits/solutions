#include <cstdio>

using namespace std;

int main() {
    int obv, tsec = 0, tmin = 0;
    scanf("%d", &obv);
    for (int i = 0; i < obv; i++) {
        int min, sec;
        scanf("%d %d", &min, &sec);
        tsec += sec;
        tmin += min;
    }
    double ave = tsec / (tmin * 60.0);
    if (ave <= 1.0)
        printf("measurement error\n");
    else
        printf("%.9lf\n", ave);
}
