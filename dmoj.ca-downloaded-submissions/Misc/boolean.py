import sys
input = sys.stdin.readline

arr = str(input()).strip()
if arr:
    nots = arr.count("not") %2

    if arr[-2] == "u":
        last = True
    else:
        last = False
    if nots:
        last = not last
    print(last)