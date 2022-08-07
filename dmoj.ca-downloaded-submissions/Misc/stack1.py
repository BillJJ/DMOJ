from collections import deque

t, m = map(int, input().split())

q = deque()

for i in range(t):
    name, go = input().split()
    if go == "in":
        q.append(name)
    else: # out
        if name == q[-1]:
            q.pop()
        elif m >= 1 and name == q[0]:
            q.popleft()
            m -= 1

for name in q:
    print(name)