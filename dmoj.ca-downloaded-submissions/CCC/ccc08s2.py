from math import pi
import math

r = int(input())
while(r != 0):
    right = r
    total = r
    for row in range(1, r+1):
        while row**2+right**2 > r*r:
            right -= 1
        total += right
    print(total*4 + 1)
    r = int(input())