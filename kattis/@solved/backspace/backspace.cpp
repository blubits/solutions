#include <cstdio>
#include <deque>

using namespace std;

int main() {
    char c;
    deque<char> text;
    while (scanf("%c", &c) && c != '\n') {
        if (c == '<' && text.size() != 0) {
            text.pop_back();
        } else {
            text.push_back(c);
        }
    }
    for (auto c : text) printf("%c", c);
    printf("\n");
}
