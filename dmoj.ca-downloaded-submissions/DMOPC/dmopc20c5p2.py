from math import floor, ceil

n, m = map(int, input().split())

a = []

for i in range(1, m+1):
    left = floor(n*(i-1)/m) + 1
    right = ceil(n*i/m)
    for r in range(left, right + 1):
        a.append((r, i))

print(len(a))
for e in a:
    print(*e)