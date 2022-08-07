n = int(input())

data = []

for _ in range(n):
    data.append(list(map(int, input().split())))

a = [0 for i in range(n)]

for i in range(n):
    for j in range(n):
        if i == j:continue

        a[i] |= data[i][j]
        a[j] |= data[i][j]

print(*a)