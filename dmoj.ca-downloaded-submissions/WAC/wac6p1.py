import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    p, c = map(float, input().split())
    o = p / (1+c/100)
    print(o)