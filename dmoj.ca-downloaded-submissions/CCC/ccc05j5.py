def pew(s: str):
    s = s.replace("ANA", "A")
    s = s.replace("BAS", "A")
    return s

sin = input()
while sin != "X":

    while sin != "A":
        new = pew(sin)
        if new == sin: break
        sin = new

    print("YES" if sin == "A" else "NO")
    sin = input()