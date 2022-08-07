a = []
n = int(input())

for i in range(n):
    a.append(input())

m = input() 
vis = [0 for i in range(26)]
for s in a:
    if s.startswith(m):
        vis[ord(s[len(m)])-65] = 1

keyboard = "***ABCDE\nFGHIJKLM\nNOPQRSTU\nVWXYZ***"
for i in range(26):
    if not vis[i]:
        keyboard = keyboard.replace(chr(i+65), "*")

print(keyboard)