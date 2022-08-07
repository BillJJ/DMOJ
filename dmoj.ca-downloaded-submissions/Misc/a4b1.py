n = int(input())
data = []
for _ in range(n):
    data.append(int(input()))
print(*sorted(data), sep="\n")