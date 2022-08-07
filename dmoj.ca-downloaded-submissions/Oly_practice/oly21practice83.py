n = int(input())
a = list(map(int, input().split()))

a.insert(0, 0)
a.append(0)

res = 0
for i in range(1, len(a)):
    res += abs(a[i] - a[i-1])

for i in range(1, len(a)-1):
    before = abs(a[i+1]-a[i]) + abs(a[i] - a[i-1])
    after = abs(a[i+1] - a[i-1])
    print(res - before + after)