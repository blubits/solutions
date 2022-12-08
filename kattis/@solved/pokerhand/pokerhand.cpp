#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<char, int> freq;
    char rank, suit;
    for (int i = 0; i < 5; i++) {
        scanf("%c%c ", &rank, &suit);
        if (freq.find(rank) != freq.end()) {
            freq[rank]++;
        } else {
            freq[rank] = 1;
        }
    }
    int m = 0;
    for (auto x : freq) {
        if (m < x.second) m = x.second;
    }
    printf("%d\n", m);
    return 0;
}
