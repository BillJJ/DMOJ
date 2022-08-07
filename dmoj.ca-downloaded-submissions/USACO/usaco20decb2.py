import sys
input = sys.stdin.readline

n = int(input())
f = [int(i) for i in input().split()]

total = n
for i in range(2, n+1):
    for j in range(i,n+1):
        if sum(f[j-i: j])/i in f[j-i : j]:
            total += 1

print(total)