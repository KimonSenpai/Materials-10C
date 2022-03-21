n = int(input())

mas = [0]*7
m1 = m2 = m13 = m26 = m = 0
for i in range(7):
    mas[i] = int(input())

for i in range(7, n):
    val = int(input())
    v = mas[i%7]
    if v % 26 == 0:
        m26 = max(m26, v)
    elif v % 13 == 0:
        m13 = max(m13, v)
    elif v % 2 == 0:
        m2 = max(m2, v)
    else:
        m1 = max(m1, v)

    if val % 26 == 0:
        m = max(m, m26 + val, m13 + val, m2 + val, m1 + val)
    elif val % 13 == 0:
        m = max(m, m2 + val, m26 + val)
    elif val % 2 == 0:
        m = max(m, m13 + val, m26 + val)
    else:
        m = max(m, m26 + val)
    
    mas[i%7] = val

print(m)