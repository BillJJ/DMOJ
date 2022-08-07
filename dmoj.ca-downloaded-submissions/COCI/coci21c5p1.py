t = int(input())
for _ in range(t):
    a, b = input().split("->")
    fa, fb = dict(), dict()
    for c in (a+b):
        fa[c]=0
        fb[c]=0

    for mole in a.split("+"):
        mole = str(mole)
        mole = mole.strip()

        mult = 1
        if mole[0].isdigit(): mult = int(mole[0])

        for i in range(len(mole)):
            if mole[i].isdigit(): continue
            if i == len(mole)-1: fa[mole[i]] += mult
            else:
                if mole[i+1].isdigit(): fa[mole[i]] += mult*int(mole[i+1])
                else: fa[mole[i]] += mult

    for mole in b.split("+"):
        mole = str(mole)
        mole = mole.strip()

        mult = 1
        if mole[0].isdigit(): mult = int(mole[0])

        for i in range(len(mole)):
            if mole[i].isdigit(): continue
            if i == len(mole)-1:
                fb[mole[i]] += mult
            else:
                if mole[i + 1].isdigit():
                    fb[mole[i]] += mult * int(mole[i + 1])
                else:
                    fb[mole[i]] += mult

    if fa == fb:
        print("DA")
    else:
        print("NE")