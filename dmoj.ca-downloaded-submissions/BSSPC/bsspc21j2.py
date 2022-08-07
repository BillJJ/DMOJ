m = int(input())
c = [0 for i in range(1500)]

for _ in range(m):
    x, y = map(int, input().split())
    for i in range(x, y+1):
        c[i] = 1

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    for i in range(a, b+1):
        if c[i]:
            print("Break is Over! Stop playing games! Stop watching Youtube!")
            break
    else:
        print(":eyy:")