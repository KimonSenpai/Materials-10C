# Количество пар, произведение которых кратно 26

n1 = n2 = n13 = n26 = 0
n = int(input())
S = 0

for i in range(n):
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


#S = (n1 + n2 + n13)*n26 + n2*n13 + n26*(n26-1)//2