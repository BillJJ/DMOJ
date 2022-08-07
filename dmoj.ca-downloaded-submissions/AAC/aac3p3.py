n = int(input())
a = list(map(int, input().split()))

a.sort()

outside = -1
if len(a) & 1:
    outside = a.pop(len(a)//2)

for i in range(len(a)//2):
    print(a[i], a[i+len(a)//2], end=(" " if i != len(a)//2-1 else ""))

print(f" {outside}" if outside != -1 else "")

for i in range(len(a)//2):
    print("BS", end="")

print("E" if outside != -1 else "")