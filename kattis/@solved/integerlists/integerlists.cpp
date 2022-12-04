#include <cstdio>
#include <deque>

using namespace std;

char program[100005];
int p_size = 0;

void print_deque(deque<int> &d, bool reversed) {
    printf("[");
    int l = 0;
    if (!reversed) {
        while (!d.empty()) {
            int i = d.front();
            d.pop_front();
            if (l++) printf(",");
            printf("%d", i);
        }
    } else {
        while (!d.empty()) {
            int i = d.back();
            d.pop_back();
            if (l++) printf(",");
            printf("%d", i);
        }
    }
    printf("]\n");
}

int main() {
    deque<int> list;
    int t;
    scanf("%d ", &t);
    while (t--) {
        p_size = 0;

        // get input
        int no_elements, el_i;
        char dummy, prog_comm;

        while (scanf("%c", &prog_comm) && prog_comm != '\n') {
            program[p_size++] = prog_comm;
        }

        scanf("%d ", &no_elements);
        scanf("%*c");
        while (no_elements--) {
            scanf("%d%*c ", &el_i);
            list.push_back(el_i);
        }
        if (list.size() == 0) scanf("%*c ");

        bool reversed = false, error = false;
        for (int i = 0; i < p_size; i++) {
            if (program[i] == 'R')
                reversed = !reversed;
            else {
                if (list.empty()) {
                    error = true;
                    break;
                } else if (reversed) {
                    list.pop_back();
                } else {
                    list.pop_front();
                }
            }
        }
        if (error)
            printf("error\n");
        else
            print_deque(list, reversed);
    }
    return 0;
}
