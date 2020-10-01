# This program counts the inversions in the given text file using the merge sort
# 2407905288 is the final answer( for reference )

def merge_countsplit(v1, v2):
    i, j = 0, 0
    ls = []
    cnt = 0
    n = len(v1) + len(v2)
    while i < len(v1) and j < len(v2):
        if v1[i] < v2[j]:
            ls.append(v1[i])
            i = i + 1
        else:
            ls.append(v2[j])
            cnt += len(v1[i:])
            j += 1

    ls.extend(v1[i:])
    ls.extend(v2[j:])
    return ls, cnt


def sort_counts(vec):
    n = len(vec)
    if n == 1:
        return vec, 0
    else:
        split = n // 2
        v1 = vec[:-split]
        v2 = vec[-split:]
        # if len(vec)<=6:
        # print(v1)
        # print(v2)

        v1, x = sort_counts(v1)
        v2, y = sort_counts(v2)
        vec, z = merge_countsplit(v1, v2)
        return vec, x + y + z


file = open('a.txt', 'r')
vec = []
for i in file:
    vec.append(int(i))

vec, l = sort_counts(vec)

print(l)
