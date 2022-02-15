#roads

N, t = map(int, input().split())
A, B = 0, t

for i in range(N):
    a, b = map(int, input().split())
    A = A + a
    B = min(B + b, A + t)

print(B)
