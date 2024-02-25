#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int A, B, C;
		bool sol = false;
		scanf("%d %d %d", &A, &B, &C);
		for (int x = -22; x <= 22 && !sol; x++) { if (x*x <= C)
			for (int y = -100; y <= 100 && !sol; y++) { if ((y != x) && (x*x + y*y <= C))
				for (int z = -100; z <= 100 && !sol; z++) {
					if (z != x && z != y 
						&& x + y + z == A
						&& x * y * z == B
						&& x * x + y * y + z * z == C) {
						if (y > x) printf("%d %d %d\n", x, y, z);
						else printf("%d %d %d\n", y, x, z);
						sol = true;	
					}
				}
			}
		}
		if (!sol) printf("No solution.\n");
	}
	return 0;
}