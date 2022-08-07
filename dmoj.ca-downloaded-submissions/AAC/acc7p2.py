from random import shuffle

n = int(input())

a = [i for i in range(1,n+1)]
shuffle(a)
print(*a, flush=True)

t = int(input())

while t != 0 and t!= -1:
    previous = a[t - 1]

    shuffle(a)

    if a[t-1] == previous:
        a[t-1], a[1]= a[1], a[t-1]

    print(*a, flush=True)

    t = int(input())