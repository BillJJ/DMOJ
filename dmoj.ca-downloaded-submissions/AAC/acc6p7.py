n = int(input())
s = input()

str = ""

for c in s:
    if c in 'bcdfghjklmnpqrstvwxz':
        str += '1'
    else:
        str += '0'

print(str)