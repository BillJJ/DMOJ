n = int(input())
a = [tuple(map(int, input().split())) for i in range(n)]
a.sort()

res, t= 0, 0
mod = int(1e9+7)

for v, l in a:
    res += t*l
    res += l * (v + v*l)//2
    res %= mod
    t += v*l
    t%=mod
print(int(res))