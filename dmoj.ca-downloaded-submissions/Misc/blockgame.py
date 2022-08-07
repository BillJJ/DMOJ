n, k, d = map(int, input().split())
j = float(input())
for _ in range(n):
    a, b = map(int, input().split())
    k += a
    d += b

if d == 0:
    print("stop hacking!")
else:
    print("Y" if k/d >= j else "N")