n = int(input())

for _ in range(n):
    nums = list(map(int, input().split()))
    c = max(nums)
    a = min(nums)
    nums.remove(a)
    nums.remove(c)
    b = nums[0]

    if c*c == a*a + b*b:
        print("R")
    elif c*c > a*a + b*b:
        print("O")
    elif c*c < a*a + b*b:
        print("A")