from math import ceil

def binarySearch(a, b, c, q):
    l, r = 0, 10**11 + 1

    while l < r:
        mid = l + ceil((r - l + 1) / 2)
        if a * mid * mid + b * mid <= q - c:
            l = mid
        else:
            r = mid - 1

    return l

t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    a = 4 * n
    b = c = 0
    for it in arr:
        b += it
        c += it * it
    b *= 4

    print(binarySearch(a, b, c, q))