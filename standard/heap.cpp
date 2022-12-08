/**
 * Min-heap in C++.
 */

#include <cstdio>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class heap {
   private:
    int sz;
    int capacity;
    int *tree;

   public:
    heap();
    heap(int arr[], int sz);
    int size();
    void push(int val);
    int pop();
    void print();

   private:
    int parent(int index);
    int left(int index);
    int right(int index);
    void resize();
    void swim(int index);
    void sink(int index);
};

heap::heap() {
    sz = 0;
    capacity = 10;
    tree = new int[capacity + 1];
}

int heap::size() { return sz; }

void heap::push(int val) {
    sz++;
    tree[sz] = val;
    swim(sz);
    if (sz >= capacity) resize();
}

int heap::pop() {
    int ret = tree[1];
    tree[1] = tree[sz];
    sz--;
    sink(1);
    return ret;
}

int heap::parent(int index) { return index / 2; }
int heap::left(int index) { return 2 * index; }
int heap::right(int index) { return 2 * index + 1; }

void heap::swim(int index) {
    while (index > 1 && tree[parent(index)] > tree[index]) {
        swap(&tree[index], &tree[parent(index)]);
        index = parent(index);
    }
}

void heap::sink(int index) {
    while (left(index) <= sz || right(index) <= sz) {
        int child = index;
        // determine the smaller child to swap it with
        if (left(index) <= sz && right(index) > sz) child = left(index);
        if (tree[left(index)] < tree[right(index)]) child = left(index);
        if (tree[right(index)] < tree[left(index)]) child = right(index);
        // break if heap property already satisfied
        if (tree[index] < tree[child]) break;
        swap(&tree[index], &tree[child]);
        index = child;
    }
}

void heap::resize() {
    capacity *= 2;
    int *newtree = new int[capacity + 1];
    for (int i = 1; i <= sz; i++) {
        newtree[i] = tree[i];
    }
    delete[] tree;
    tree = newtree;
}

void heap::print() {
    for (int i = 1; i <= sz; i++) printf("%d ", tree[i]);
    printf("\n");
}

int main() {
    heap h;
    for (int i = 9; i >= 0; i--) {
        h.push(i);
    }
    for (int i = 0; i < 5; i++) {
        printf("popped %d\n", h.pop());
        h.print();
    }
}
