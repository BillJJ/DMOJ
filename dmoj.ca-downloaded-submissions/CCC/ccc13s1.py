year = int(input())

while 1: # same as while True: (since 1 == True)
    year += 1

    distinct = set()
    for digit in str(year):
        distinct.add(digit)

    if len(distinct) == len(str(year)):
        print(year)
        break