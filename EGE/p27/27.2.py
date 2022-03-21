n = int(input())

mas = [0]*5

for i in range(5):
    mas[i] = int(input())

for i in range(5, n):
    val = int(input())
    v = mas[i%5]
    if v % 26 == 0:
        m26 = max(m26, v)
    elif v % 13 == 0:
        m13 = max(m13, v)
    elif v % 2 == 0:
        m2 = max(m2, v)
    else:
        m1 = max(m1, v)

    if val % 26 == 0:
        m = max(m, val+m26, val+m13, val+m2, val+m1)
    elif val % 13 == 0:
        m = max(m, val+m26, val+m2)
    elif val % 2 == 0:
        m = max(m, val+m26, val+m13)
    else:
        m = max(m, val+m26)


    mas[i%5] = val

print(m)
