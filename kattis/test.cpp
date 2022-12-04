#include <cstdio>
using namespace std;

// f(i, j) = f(i + 1, j - 1)

int main() {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            printf("f[%d][%d] = f[%d][%d]\n", i, j, i + 1, j - 1);
        }
    }
}