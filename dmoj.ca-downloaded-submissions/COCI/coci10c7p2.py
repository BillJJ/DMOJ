n, k = map(int, input().split())

a = [0 for i in range(n)]
curr = 0

for _ in range(k):
	spin, c = input().split()
	curr = (curr + int(spin)) % n
	if a[curr] and a[curr] != c:
		print("!")
		break
	a[curr] = c
else:
    if any([x for x in a if a.count(x) > 1]):
        print("!")
    else:
        for i in range(curr, -1, -1):
            print(a[i] if a[i] else "?", end="")
        for i in range(n-1, curr, -1):
            print(a[i] if a[i] else "?", end="")