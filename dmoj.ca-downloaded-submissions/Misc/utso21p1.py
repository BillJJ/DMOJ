from math import sqrt, ceil

n = int(input())
if n <= 0:
    print(0)
elif n % 2 == 0:
    s = ceil(sqrt(n*2))
    print(s - 1)
elif n % 2 == 1:
    n -= 0.5
    s = ceil(sqrt(n*2))
    print(s - 1)