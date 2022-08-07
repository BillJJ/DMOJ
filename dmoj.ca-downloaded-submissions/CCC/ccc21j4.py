a = input()
l = a.count("L")
m = a.count("M")
s = a.count("S")
total = 0
MinL = 0
LinM = 0
for i in range(l):
    if a[i] == 'M': MinL += 1

for i in range(l, l+m):
    if a[i] == 'L': LinM += 1

for i in range(l+m, l+m+s):
    if a[i] != 'S': total += 1

total += max(MinL, LinM)
print(total)