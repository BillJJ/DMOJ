import sys
input = sys.stdin.readline

dis = list(map(int, input().split()))
dis.insert(0,0)
table = [[0 for i in range(5)] for j in range(5)]

for i in range(5):
    for j in range(i + 1, 5):
        table[i][j] = table[i][j-1] + dis[j];
    for j in range(i-1, -1, -1):
        table[i][j] = table[i][j+1] + dis[j+1]

for row in table:
    print(*row)