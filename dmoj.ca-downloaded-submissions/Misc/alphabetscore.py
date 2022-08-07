s = input()
print(sum([(i+1) * s.count(chr(i+97)) for i in range(0, 26)]))