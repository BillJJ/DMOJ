s = input()

if "DMOJ" in s:
    print(0)
elif len(s) == 1:
    print(3)
elif "DMO" in s:
    print(1)
elif "DMJ" in s:
    print(1)
elif "DOJ" in s:
    print(1)
elif "MOJ" in s:
    print(1)
elif "DM" in s:
    print(2)
elif "DO" in s:
    print(2)
elif "DJ" in s:
    print(2)
elif "MO" in s:
    print(2)
elif "MJ" in s:
    print(2)
elif "OJ" in s:
    print(2)
else:
    print(3)