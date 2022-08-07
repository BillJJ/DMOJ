import sys
input = sys.stdin.readline

n, q = map(int, input().split())
rating = list(map(int, input().split()))
# psa here
for i in range(1, n):
    rating[i] += rating[i-1]

total_sum = rating[n-1]
for _ in range(q):
    a, b = map(int, input().split())
    a, b = a-1, b-1 # account for 1 indexing
    if a == 0:
        print(total_sum - rating[b])
    else:
        print(total_sum - (rating[b] - rating[a-1]))