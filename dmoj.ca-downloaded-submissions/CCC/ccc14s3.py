import sys
input = sys.stdin.readline

t = int(input())
for test in range(t):
    n = int(input())
    top = []
    side = []
    for i in range(n):
        top.append(int(input()))
    place = 1
    while top or side:
        if not top and side[-1] != place:
            print("N")
            break
        if side and side[-1] == place:
            side.pop()
            place += 1
        else:
            m = top.pop()
            if m != place:
                side.append(m)
            elif m == place:
                place += 1

    else:
        print("Y")