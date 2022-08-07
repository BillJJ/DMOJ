n = int(input())
m = int(input())
a = list(map(int, input().split()))

a.sort()

print(sum(a[len(a)-m:]))