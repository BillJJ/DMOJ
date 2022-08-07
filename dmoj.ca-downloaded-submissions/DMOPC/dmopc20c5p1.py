s = input()
t = input()

total = 0

for i in range(min(len(s), len(t))):
    if s[i] == t[i]:
        total += 1
    else:
        break

print(len(t) + len(s) - 2*total)