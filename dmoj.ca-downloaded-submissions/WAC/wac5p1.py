n = map(int, input())
acorns = sorted(map(int, input().split()), reverse=True)

count = dict()
unique = [acorns[0]]

for i in acorns:
    if i in count: count[i] += 1
    else: count[i] = 1

    if unique[-1] != i:
        unique.append(i)

total = 0
covers = 0
for i in unique:
    if covers >= count[i]:
        continue

    total += (count[i] - covers)*i
    covers = count[i]

print(total)