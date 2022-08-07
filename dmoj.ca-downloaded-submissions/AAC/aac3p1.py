a, b, c, d = map(int, input().split())

a = b - a
c = d - c

if a > 0 and c > 0:
    print("Go to the department store")
elif a > 0:
    print("Go to the grocery store")
elif c > 0:
    print("Go to the pharmacy")
else:
    print("Stay home")