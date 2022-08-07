import sys
input = sys.stdin.readline

n = int(input())
tree = []
tree.append(int(input()))
for i in range(1, n):
    tree.append(tree[-1] + int(input()))

q = int(input())
for i in range(q):
    a, b = map(int, input().split())
    if(a == 0):
        print(tree[b])
    else:
        print(tree[b] - tree[a-1])