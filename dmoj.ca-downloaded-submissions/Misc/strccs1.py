t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if (a*a*b - a*b*b) < 0:
        print((a*a*b - a*b*b)%(99996) - 99996)
    else: print(int((a*a*b - a*b*b)%(99996)))