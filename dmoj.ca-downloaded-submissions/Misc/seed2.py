l = 0
r = int(2e9)

while l <= r:
    mid = (l+r)//2
    print(mid)
    s = input()
    if s[0] == 'F':
        r = mid
    elif s[0] == 'S':
        l = mid
    else:
        break