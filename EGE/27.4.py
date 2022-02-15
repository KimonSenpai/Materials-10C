# Количество пар, сумма которых кратна 120

N = int(input())

mas = [0]*120
S = 0

for i in range(N):
    val = int(input())
    S += mas[(-val)%120]
    mas[val%120] += 1

print(S)
