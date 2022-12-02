import math

def angle(a, b, c):
    return math.acos((c*c + a*a - b*b) / (2*a*c))

n = int(input())

res = 0
for _ in range(n):
    a, b, c = map(int, input().split())

    res += 2 * math.sin(angle(b, c, a)/2) * b
print(res)


