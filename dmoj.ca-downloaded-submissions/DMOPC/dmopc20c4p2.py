n, m, k = map(int, input().split())

row, col = set(), set()
for _ in range(k):
    r, c = map(int, input().split())

    if r in row:
        row.remove(r)
    else:
        row.add(r)
    if c in col:
        col.remove(c)
    else:
        col.add(c)

if len(col) > len(row):
    col, row = row, col

row = list(row)
col = list(col)

print(len(row))
# for a in row:
#     if len(col) == 0:
#         col.append(1)
# 
#     print(a, col.pop())