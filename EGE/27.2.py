
INF = 10000000000000
for file in ("27_A.txt", "27_B.txt"):
    f = open(file, 'r')

    N = int(f.readline())
    S = 0
    dif = INF
    for line in f:
        a, b = sorted(map(int, line.split()))
        S += b
        if (b - a)%3 != 0:
            dif = min(dif, b - a)
        
    if S%3 == 0:
        S -= dif

    print(S)