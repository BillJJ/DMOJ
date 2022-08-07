n, x, y = map(int, input().split())

total = 1

while (x+y)//2 != n:
    total += 1

    mid = (x+y)//2
    if n > mid:
        x = mid
    elif n < mid:
        y = mid
    else:
        break

print(total)