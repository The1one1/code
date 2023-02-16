
n, w, l = map(int, input().split())
h = []
r = []

for _ in range(n):
    x, y = map(int, input().split())
    h.append(x)
    r.append(y)


def check(mid):
    k = w
    for i in range(n):
        if h[i] + mid * r[i] >= l:
            k -= (h[i] + mid * r[i])
        if k <= 0:
            return True
    return k <= 0


low, high = 0, 10**18 + 1

while high - low > 1:
    mid = (high + low) // 2

    if check(mid):
        high = mid
    else:
        low = mid + 1

if sum(h[i] + low * r[i] for i in range(n)) >= w:
    print(low)
else:
    print(high)
