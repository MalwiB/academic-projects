# porzucenie dalszych podzialow, gdy cigi staja sie male
# dzieki temu elementy beda czesciowo uporzadkowane


def modified_quicksort(L, left, right):
    if left >= right:
        return
    if (right - left) <= 3:
         return
    pivot = partition(L, left, right)
    modified_quicksort(L, left, pivot - 1)
    modified_quicksort(L, pivot + 1, right)


def swap(L, a, b):
    L[a], L[b] = L[b], L[a]


def partition(L, left, right):
    x = L[right]
    i = left
    for j in range(left, right):
        if L[j] <= x:
            swap(L, i, j)
            i += 1
    swap(L, i, right)
    return i
