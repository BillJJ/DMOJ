m, n = map(int, input().split())

d = ["" for i in range(n+5)]

jwass = dict()

for _ in range(m):
    a, b = input().split()
    jwass[int(a)] = b

jwass = sorted(jwass.items() ,key=lambda x:x[0])

for num, p in jwass:
    for i in range(0, n+1, num):
        d[i] += p

for i in range(1, n+1):
    if d[i] == "": print(i)
    else: print(d[i])