s = input()

if s.find("java") == -1:
    print(len(s))
else:
    print(s.index("java"))