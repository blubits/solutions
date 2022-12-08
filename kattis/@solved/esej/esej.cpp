#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

char random_letter() { return 'a' + (rand() % 26); }

int random_length() { return 2 + (rand() % 5); }

int main() {
    srand(time(NULL));
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < b; i++) {
        if (i != 0) printf(" ");
        int l = random_length();
        for (int j = 0; j < l; j++) {
            printf("%c", random_letter());
        }
    }
    printf("\n");
}
