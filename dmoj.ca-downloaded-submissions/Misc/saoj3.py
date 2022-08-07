s = open(0).read()
s = s.lower()
for i in range(26):
    print(s.count(chr(i + ord('a'))), end=" ")