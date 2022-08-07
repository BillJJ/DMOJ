import sys
input = sys.stdin.readline

n, t = map(int, input().split())
cups = [0 for _ in range(n)]
dif = [0]*(n+1)
for _ in range(t):
    a, b, c = map(int, input().split())
    dif[a-1] += c
    dif[b] -= c

cups[0] = dif[0]
for i in range(1, n):
    cups[i] = dif[i] + cups[i-1]

l = int(input())

length, bar = 1, l
first, last = 0,0

while first < n:
    while first < n and cups[first] >= bar:
        first += 1
        last += 1

    if first == n:
        break

    sum = 0
    for i in range(last, first + 1):
        sum += cups[i]

    length += 1
    first += 1
    while sum <= l and first < n:
        length += 1
        first += 1
        sum += cups[first]
    if sum > l:
        bar = last

print(length - 1)