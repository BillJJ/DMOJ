class mat:
    def __init__(self, arr):
        self.m = arr
    def __mul__(self, other):
        new = [[0 for _ in i] for i in self.m]
        for row in range(len(self.m)):
            for col in range(len(other.m[0])):
                for i in range(len(self.m[row])):
                    new[row][col] += self.m[row][i] * other.m[col][i]
                    new[row][col] %= mod
        return mat(new)

x, y, n = map(int, input().split())
a = mat([[0, 1], [1, 1]])
b = mat([[0, 1], [1, 1]])

mod = 10**9

leave = 0
if n == 0:
    print(x)
    leave = 1
elif n == 1:
    print(y)
    leave = 1
elif n == 2:
    print(x + y)
    leave = 1

n -= 1
while n > 0:
    if n & 1:
        a = a*b
    b = b*b
    n >>= 1


num = a.m[0][0] * x + a.m[1][0] * y
if(not leave):
    print(num%mod)