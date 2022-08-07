n = int(input())

data = []
for _ in range(n):
    data.append(tuple(map(int, input().split())))

data.sort(key=lambda x:x[0])

fast = 0
for i in range(1, n):
    dis = abs(data[i][1] - data[i-1][1])
    t = data[i][0] - data[i-1][0]
    fast = max(fast, dis/t)

print(fast)