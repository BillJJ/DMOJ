import sys
input = sys.stdin.readline

n = int(input())
s = input().split()
max = 0
for i in range(n):
    s[i] = int(s[i])
    if s[i] > s[max]:
        max = i

total = 0
for i in range(1, max):
    if s[i] < s[i-1]:
        total += s[i-1] - s[i]
        s[i] = s[i-1]
for i in range(n-1, max, -1):
    if s[i] > s[i-1]:
        total += s[i] - s[i-1]
        s[i-1] = s[i]
print(total)