def get_pivot(A, l, r):
    mid = (l + ((r - l + 1) // 2)) - (1 if (r - l + 1) % 2 == 0 else 0)
    left_val, mid_val, right_val = A[l], A[mid], A[r]
    L = [(left_val, l), (mid_val, mid), (right_val, r)]
    L.sort()
    return L[1][1]


def partition(A, l, r, pivot):
    pivot_value = A[pivot]
    A[pivot], A[l] = A[l], A[pivot]
    i = l + 1
    for j in range(l + 1, r + 1):
        if A[j] < pivot_value:
            A[j], A[i] = A[i], A[j]
            i = i + 1
    A[l], A[i - 1] = A[i - 1], A[l]
    return i - 1


def quicksort(A, l, r):
    if r - l + 1 <= 1:
        return 0  # Already sorted
    pivot = get_pivot(A, l, r)
    pivot = partition(A, l, r, pivot)
    comparisons = r - l + \
        quicksort(A, l, pivot - 1) + quicksort(A, pivot + 1, r)
    return comparisons


L = [int(line.strip()) for line in open("QuickSort.txt").readlines()]
print(quicksort(L, 0, len(L) - 1))
