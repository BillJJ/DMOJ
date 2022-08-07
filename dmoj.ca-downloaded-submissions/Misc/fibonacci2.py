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

mod = 1000000007
period = 2000000016
n = int(input())
n %= period

a = mat([[0, 1], [1, 1]])
b = mat([[0, 1], [1, 1]])


n -= 2
while n > 0:
    if n & 1:
        a = a*b
    b = b*b
    n >>= 1

print((a.m[0][0] + a.m[1][0]) % mod)