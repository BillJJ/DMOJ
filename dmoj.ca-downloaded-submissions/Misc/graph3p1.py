import sys
input = sys.stdin.readline

from collections import deque

n, m = map(int, input().split())
edge = [list() for i in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    edge[u].append(v)
    edge[v].append(u)

dis = [0 for _ in range(n+1)]

q = deque()
k = int(input())
for _ in range(k):
    a = int(input())
    q.append(a)
    dis[a] = 1

far = 0

while q:
    m = q.popleft()
    far = max(dis[m], far)
    for city in edge[m]:
        if not dis[city]:
            q.append(city)
            dis[city] = dis[m] + 1

print(far-1)