from _collections import deque
import sys
input = sys.stdin.readline
r, c = map(int, input().split())

map = [input() for i in range(r)]
vis = set()
stack = deque()
total = 0

for i in range(1, r-1):
    for j in range(1, c-1):
        if map[i][j] == "M" and (i,j) not in vis:
            total += 1
            stack.append((i,j))
            while stack:
                m = stack.pop()
                vis.add(m)
                if map[m[0]][m[1] + 1] != "#" and (m[0],m[1] + 1) not in vis:
                    stack.append((m[0],m[1] + 1))
                if map[m[0]][m[1] - 1] != "#" and (m[0],m[1] - 1) not in vis:
                    stack.append((m[0],m[1] - 1))
                if map[m[0] + 1][m[1]] != "#" and (m[0] + 1,m[1]) not in vis:
                    stack.append((m[0] + 1, m[1]))
                if map[m[0] - 1][m[1]] != "#" and (m[0] - 1,m[1]) not in vis:
                    stack.append((m[0] - 1, m[1]))

print(total)