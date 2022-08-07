import sys
import math
input = sys.stdin.readline

n = int(input())
line = input()
chars = []
place = []
pos = 0
highest = 0
lowest = 10000
for c in line:
    if c == "^":
        pos -= 1
        if chars and (chars[-1] == "_" or chars[-1] == "\\"):
            pos += 1
        place.append(pos)
        chars.append("/")
    elif c == "v":
        pos += 1
        if chars and chars[-1] == "/":
            pos -= 1
        elif chars and chars[-1] == "_":
            pass
        chars.append(chr(92))
        place.append(pos)
    elif c == ">":
        if chars and chars[-1] == "/":
            pos -= 1
        chars.append("_")
        place.append(pos)
    lowest = min(pos, lowest)
    highest = max(pos, highest)

for i in range(lowest, highest+1):
    if place.count(i) == 0:
        continue
    for j in range(len(place)):
        if i != place[j]:
            print(".", end="")
        else:
            print(chars[j], end="")
    print()