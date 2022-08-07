t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))

    s = set()
    from itertools import permutations
    for d in permutations([0, 1, 2, 3]):
        s.add((a[d[0]] + a[d[2]], a[d[1]]+a[d[3]]))

    print(len(s))
    s = list(s)
    s.sort()
    for x in s:
        print(*x)