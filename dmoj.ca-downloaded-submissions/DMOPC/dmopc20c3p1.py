import sys
input = sys.stdin.readline

n = int(input())
correct = [i for i in range(1, n+1)]

data = [int(i) for i in input().split()]
data.sort()
if(correct == data):
    print("YES")
else:
    print("NO")