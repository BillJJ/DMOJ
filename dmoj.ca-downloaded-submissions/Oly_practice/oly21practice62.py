n = int(input())

a = []
for i in range(n):
    a.append(sum(map(int, list(input()))))

print(max(a))