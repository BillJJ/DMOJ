import sys
input = sys.stdin.readline

n = int(input())
max_time = int(1e7+5)
concurrent = [0 for i in range(max_time)] # max time
for i in range(n):
    a, b = map(int, input().split())
    concurrent[a] += 1
    concurrent[b] -= 1

for i in range(1, max_time):
    concurrent[i] += concurrent[i-1]

print(max(concurrent))