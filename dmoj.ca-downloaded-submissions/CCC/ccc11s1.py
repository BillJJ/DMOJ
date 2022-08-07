n = int(input())
s = ""
for i in range(n):
    s += input().lower()

sc = s.count("s")
tc = s.count("t")

if tc > sc:
    print("English")
else:
    print("French")