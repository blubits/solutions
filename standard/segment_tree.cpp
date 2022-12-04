/**
 * Segment tree in C++.
 * Solves the Range Sum Query problem.
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int identity() { return 0; }
int combine(int left, int right) { return left + right; }

class segment_tree {
   private:
    int sz;
    int capacity;
    int *tree;

   public:
    segment_tree(int arr[], int size);
    int sum(int start, int end);
    void update(int index, int value);

   private:
    int parent(int index);
    int left(int index);
    int right(int index);
    void build_helper(int arr[], int curr_index, int curr_start, int curr_end);
    int sum_helper(int curr_index, int curr_start, int curr_end, int start,
                   int end);
    void update_helper(int curr_index, int curr_start, int curr_end, int index,
                       int value);
};

segment_tree::segment_tree(int arr[], int size) {
    sz = size;
    capacity = 4 * sz;
    tree = new int[capacity + 1];
    build_helper(arr, 1, 0, sz - 1);
}

void segment_tree::build_helper(int arr[], int curr_index, int curr_start,
                                int curr_end) {
    if (curr_start == curr_end)
        tree[curr_index] = arr[curr_start];
    else {
        int middle = (curr_start + curr_end) / 2;
        // left ST
        build_helper(arr, left(curr_index), curr_start, middle);
        // right ST
        build_helper(arr, right(curr_index), middle + 1, curr_end);
        // current node: figure out value from both subtrees
        tree[curr_index] =
            combine(tree[left(curr_index)], tree[right(curr_index)]);
    }
}

int segment_tree::sum(int start, int end) {
    return sum_helper(1, 0, sz - 1, start, end);
}

int segment_tree::sum_helper(int curr_index, int curr_start, int curr_end,
                             int start, int end) {
    printf("I'm at node [%d:%d] (tree[%d]), trying to look for [%d:%d]\n",
           curr_start, curr_end, curr_index, start, end);
    if (start > end) return identity();
    if (start == curr_start && end == curr_end) return tree[curr_index];
    int middle = (curr_start + curr_end) / 2;
    int res_left = sum_helper(left(curr_index), curr_start, middle, start,
                              min(end, middle));
    int res_right = sum_helper(right(curr_index), middle + 1, curr_end,
                               max(start, middle + 1), end);
    return combine(res_left, res_right);
}

void segment_tree::update(int index, int value) {
    update_helper(1, 0, sz - 1, index, value);
}

void segment_tree::update_helper(int curr_index, int curr_start, int curr_end,
                                 int index, int value) {
    printf("I'm at node [%d:%d] (tree[%d]), trying to change arr[%d] = %d\n",
           curr_start, curr_end, curr_index, index, value);
    if (curr_start == curr_end) {
        tree[curr_index] = value;
    } else {
        int middle = (curr_start + curr_end) / 2;
        if (index <= middle) {
            // update left
            update_helper(left(curr_index), curr_start, middle, index, value);
        } else {
            update_helper(right(curr_index), middle + 1, curr_end, index,
                          value);
        }
        tree[curr_index] =
            combine(tree[left(curr_index)], tree[right(curr_index)]);
    }
}

int segment_tree::parent(int index) { return index / 2; }
int segment_tree::left(int index) { return 2 * index; }
int segment_tree::right(int index) { return 2 * index + 1; }

int main() {
    int arr[] = {1, 3, -2, 8, -7};
    segment_tree st(arr, 5);
    printf("%d\n", st.sum(2, 4));
    st.update(2, 5);
    printf("%d\n", st.sum(2, 4));
}
