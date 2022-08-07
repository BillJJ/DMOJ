import sys
input = sys.stdin.readline
g = int(input())
p = int(input())

total = 0
time = float('inf')

for g, i in sorted([(int(input()), i) for i in range(p)]):
  if i < time and total + 1 <= g:
    total += 1
  else:
    time = min(time, i)
print(total)