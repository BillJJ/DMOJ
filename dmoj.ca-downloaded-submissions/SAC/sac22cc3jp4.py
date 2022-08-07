q = int(input())

def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]
while q:
    a, x, b = map(int, input().split())
    x = int(str(x), a)
    print(*numberToBase(x, b), sep="")
    q -=1