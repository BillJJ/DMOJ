n, c, v = map(int, input().split())

word = input()

Vrun = 0
Crun = 0
cons = "bcdfghjklmnpqrstvwxyz"
vow = "aeiouy"

for letter in word:
    if letter == 'y':
        Vrun += 1
        Crun += 1
        if Crun > c:
            print("NO")
            break
        if Vrun > v:
            print("NO")
            break
    elif letter in cons:
        Crun += 1
        Vrun = 0
        if Crun > c:
            print("NO")
            break
    elif letter in vow:
        Vrun += 1
        Crun = 0
        if Vrun > v:
            print("NO")
            break
else:
    print("YES")