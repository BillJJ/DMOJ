n = int(input())

freq = [0 for i in range(1005)]

for _ in range(n):
    freq[int(input())] += 1

counter = 0
for c in freq:
    if c > 0: counter += 1

if counter == 1:
    print(0)
    exit()

fL = max(freq)
largest = []

for i in range(1000, -1, -1):
    if freq[i] == fL:
        largest.append(i)

largest.sort()
if len(largest) > 1:
    print(abs(largest[-1] - largest[0]))
else:
    fS = 0
    for i in freq:
        if i < fL and i > fS: fS = i
    
    second = []
    for i in range(1001):
        if freq[i] == fS:
            second.append(i)
    
    second.sort()
    
    print(max(abs(second[-1] - largest[0]), abs(largest[-1] - second[0])))