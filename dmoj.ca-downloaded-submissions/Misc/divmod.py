q = int(input())
while q:
    a,b,c = map(int, input().split())
    print(a*b + (c%a))
    q-=1