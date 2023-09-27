#include <bits/stdc++.h>
using namespace std;

double eqn(double A, double B, double C, double x) {
    return (x * x * x)
        - (A * x * x)
        + (((A * A - C) / 2.0) * x)
        - B;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long int A, B, C;
		int sol = 0;
		scanf("%lld %lld %lld", &A, &B, &C);
        // bisect to find 1 root
        double lo = -2000000, hi = 2000000, mid = (lo + hi) / 2;
        for (int i = 0; i < 100; i++) {
            mid = (lo + hi) / 2;
            double soln = eqn(A, B, C, mid);
            //cout << lo << " " << mid << " " << hi << " = " << eqn(A, B, C, lo) << " " << soln << " " << eqn(A, B, C, hi) << endl;
            if (soln < 0) lo = mid;
            else if (soln > 0) hi = mid;
            else break;
        }
        int root1 = int(round(mid));
        cout << root1 << endl;
		//if (!sol) printf("No solution.\n");
	}
	return 0;
}