#include <cstdio>

using namespace std;

// if i'm guessing correctly, this is the number of shots you can make
// that end at that height and hit nothing more
int counts[1000001] = {};

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        // let's assume that at this point in the balloon sequence,
        // a shot ends here
        counts[t]++;
        // but! if we've said before in the sequence that a shot ended at
        // 1 + the current height, we know that the arrow will end
        // at this new lower height, NOT the height that it was before.
        // this part of the code effectively "refines" earlier guesses.
        if (counts[t + 1] != 0) {
            counts[t + 1]--;
        }
        // effectively, this code counts the number of distinct subsequences
        // that end at a certain height.
        // this is equivalent to the number of arrows you're supposed to hit,
        // since one arrow will hit one subsequence.

        // debug code:
        // for (int i = 1; i <= n; i++) {
        //     printf("%d ", counts[i]);
        // }
        // printf("\n");
    }

    int shots = 0;
    for (int i = 0; i <= 1000000; i++) {
        shots += counts[i];
    }

    printf("%d\n", shots);
    return 0;
}
