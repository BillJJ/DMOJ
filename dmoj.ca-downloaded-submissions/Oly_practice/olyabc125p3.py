from math import gcd

n = int(input())
psa = list(map(int, input().split()))
ssa = psa.copy()

for i in range(1, n):
	psa[i] = gcd(psa[i-1], psa[i])
for i in range(n-2, -1, -1):
	ssa[i] = gcd(ssa[i+1], ssa[i])

res = ssa[1]
for i in range(1, n):
	if i == n-1:
		without = psa[i-1]
	else: without = gcd(psa[i-1], ssa[i+1])
	
	res = max(res, without)
	

print(res)