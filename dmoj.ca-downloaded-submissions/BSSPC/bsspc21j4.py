# holy how does this pass
# get ur shit together guys

import sys
input = sys.stdin.readline

x, n = map(int, input().split())
ans = 0
for i in range(n):
    t, f = map(int, input().split())
    if t - f <= x:
        ans += 1

print(ans)