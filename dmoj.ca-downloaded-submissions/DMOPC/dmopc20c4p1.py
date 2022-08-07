from math import ceil
from math import floor
t = int(input())
for _ in range(t):
    n, s = map(int, input().split())

    if n < 2:
        print(0)
        continue

    diff = (n//2)*(n+1) - s

    if n & 1:
        diff += (n+1)//2

    if diff < 3:
        print(0)
    elif diff % 2 == 0:
        mid = floor(diff / 2)
        dis = min(n-mid, mid-1)
        print(int(dis))
    else:
        mid = floor(diff / 2)
        dis = min(n-mid, mid)
        print(int(dis))

# n = 1000000000
# Sn = 500000000500000000
# sn - 3 = 500000000499999997
# least possible sum = 4999999850000001