def count_split_inversions(L, left, right):
    lptr, rptr, inv = 0, 0, 0
    for i in range(len(L)):
        #print(lptr, rptr, inv, left, right)
        if rptr == len(right):
            L[i] = left[lptr]
            lptr += 1
        elif lptr == len(left):
            L[i] = right[rptr]
            rptr += 1
            inv += len(left) - lptr
        elif left[lptr] < right[rptr]:
            L[i] = left[lptr]
            lptr += 1
        elif left[lptr] > right[rptr]:
            L[i] = right[rptr]
            rptr += 1
            inv += len(left) - lptr
    # print(L)
    return inv


def sort_and_count_inversions(L):
    if len(L) == 1:
        return 0
    if len(L) == 2:
        if L[0] > L[1]:
            L[0], L[1] = L[1], L[0]
            return 1
        else:
            return 0
    mid = len(L) // 2
    left, right = L[:mid], L[mid:]
    l_inv = sort_and_count_inversions(left)
    r_inv = sort_and_count_inversions(right)
    s_inv = count_split_inversions(L, left, right)
    return l_inv + r_inv + s_inv


print(sort_and_count_inversions([int(x.strip())
                                 for x in open("IntegerArray.txt").readlines()]))
