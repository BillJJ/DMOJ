import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    c, r = map(int, input().strip().split())
    start = ()
    end = ()
    room = []
    for i in range(r):
        room.append(input().strip())
        if room[-1].count("C") > 0:
            start = (i,room[-1].index("C"))
        if room[-1].count("W") > 0:
            end = (i,room[-1].index("W"))

    dis = [[-1 for i in range(c)] for j in range(r)]
    dis[start[0]][start[1]] = 0
    q = deque()
    q.append(start)
    while q:
        m = q.popleft()
        x = m[0]
        y = m[1]
        if room[x][y] == "W":
            if dis[end[0]][end[1]] < 60:
                print(dis[end[0]][end[1]])
            else:
                print("#notworth")
            break
        if x + 1 < r and dis[x+1][y] == -1 and room[x+1][y] != "X":
            q.append((x+1, y))
            dis[x+1][y] = dis[x][y] + 1

        if x != 0 and dis[x-1][y] == -1 and room[x-1][y] != "X":
            q.append((x-1, y))
            dis[x - 1][y] = dis[x][y] + 1

        if y != 0 and dis[x][y-1] == -1 and room[x][y-1] != "X":
            q.append((x, y-1))
            dis[x][y-1] = dis[x][y] + 1

        if y+1 < c and dis[x][y+1] == -1 and room[x][y+1] != "X":
            q.append((x, y+1))
            dis[x][y + 1] = dis[x][y] + 1
    else:
        print("#notworth")