k, d = map(int, input().split())

a = list(map(int, input().split()))

a.sort()
if a[0] == 0 and len(a) == 1:
    print(-1)
elif a[0] == 0 and k <= 2:
    print(str(a[1]) * k)
elif a[0] == 0 and k > 2:
    print(str(a[1]) + "0"*(k-2) + str(a[1]))
else:
    print(str(a[0]) * k)