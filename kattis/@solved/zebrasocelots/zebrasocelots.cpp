#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int T, ans = 0;
	scanf("%lld ", &T);
	while (T--) {
		char c;
		scanf("%c ", &c);
        ans <<= 1;
        if (c == 'O') ans += 1;
	}
	printf("%lld\n", ans);
	return 0;
}