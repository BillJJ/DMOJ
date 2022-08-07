from collections import deque

dirc = [[2, -1], [2, 1], [1, 2], [-1, 2], [-2, 1], [-2, -1], [-1, -2], [1, -2]]

n = int(input())

for _ in range(n):
    row = int(input())
    col = int(input())
    pr = int(input())
    pc = int(input())
    kr = int(input())
    kc = int(input())

    if pc == kc and pr + 1 == kr:
        print("Stalemate in 0 knight move(s).")
        continue

    dis = [[1000 for j in range(col + 1)] for i in range(row + 1)]

    q = deque()
    dis[kr][kc] = 0
    q.append((kr, kc))
    while q:
        r, c = q.popleft()
        for dirca in dirc:
            x, y = dirca
            x += r
            y += c
            if x > row or x < 1 or y > col or y < 1: continue

            if dis[x][y] > dis[r][c] + 1:
                dis[x][y] = dis[r][c] + 1
                q.append((x, y))

    done = 0
    for y in range(pr + 1, row):
        if dis[y][pc] == y - pr or ((y-pr) > dis[y][pc] and ((y-pr) - dis[y][pc]) % 2 == 0):
            done = 1
            print(f"Win in {y - pr} knight move(s).")
            break

    if not done:
        for y in range(pr + 1, row):
            if dis[y + 1][pc] == y - pr or ((y-pr) > dis[1+y][pc] and ((y-pr) - dis[y+1][pc]) % 2 == 0):
                done = 1
                print(f"Stalemate in {y - pr} knight move(s).")
                break
    if not done:
        print(f"Loss in {row - pr - 1} knight move(s).")