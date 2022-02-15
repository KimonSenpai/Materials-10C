# roads

N, t = map(int, input().split())

A, B = 0, t

for i in range(N):
    a, b = map(int, input().split())

    A = A + a
    B = min(B + b, A + t)

print(B)




# Количество пар, произведение которых кратно 26

n1 = n2 = n13 = n26 = 0
N = int(input())
S = 0
for i in range(N):
    val = int(input())
    if val%26 == 0:
        S += n1 + n2 + n13 + n26
        n26 += 1
    elif val%13 == 0:
        S += n2 + n26
        n13 += 1
    elif val%2 == 0:
        S += n13 + n26
        n2 += 1
    else:
        S += n26
        n1 += 1

# S = n2*n13 + n26*(n1 + n2 + n13) + n26*(n26-1)//2



# Количество пар, сумма которых кратно 120

mas = [0]*120
N = int(input())
S = 0

for i in range(N):
    val = int(input())
    S += mas[(-val)%120]
    mas[val%120] += 1
print(S)