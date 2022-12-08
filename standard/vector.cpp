/**
 * Segment tree in C++.
 * Solves the Range Sum Query problem.
 */

#include <cstdio>

using namespace std;

class vector {
   private:
    int sz;
    int capacity;
    int* data;

   public:
    vector();
    vector(int arr[], int N);
    int size();
    int get(int index);
    void set(int index, int val);
    void push_back(int val);
    int pop_back();
    void insert(int index, int val);
    int remove(int index);

   private:
    void resize();
};

vector::vector() {
    sz = 0;
    capacity = 10;
    data = new int[capacity];
}

vector::vector(int arr[], int N) {
    sz = N;
    capacity = 2 * N;
    data = new int[capacity];

    for (int i = 0; i < N; i++) {
        data[i] = arr[i];
    }
}

int vector::size() { return sz; }

int vector::get(int index) { return data[index]; }

void vector::set(int index, int val) { data[index] = val; }

void vector::push_back(int val) {
    data[sz] = val;
    sz++;
    if (sz >= capacity) resize();
}

int vector::pop_back() {
    sz--;
    int ret = data[sz];
    return ret;
}

void vector::insert(int index, int val) {
    if (index < 0) index = 0;
    if (index >= sz) index = sz;
    for (int i = sz; i >= index; i--) {
        data[i + 1] = data[i];
    }
    data[index] = val;
    sz++;
    if (sz >= capacity) resize();
}

int vector::remove(int index) {
    int d = data[index];
    for (int i = index; i < sz; i++) {
        data[i] = data[i + 1];
    }
    sz--;
    return d;
}

void vector::resize() {
    capacity *= 2;
    int* newdata = new int[capacity];
    for (int i = 0; i < sz; i++) {
        newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
}

int main() {
    vector v;
    for (int i = 0; i < 10; i++) v.push_back(i);
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v.get(i));
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("popped back %d\n", v.pop_back());
    }
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v.get(i));
    }
    printf("\n");
}
