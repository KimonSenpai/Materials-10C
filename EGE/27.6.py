for file in ("D:\\Downloads\\27-A.txt", "D:\\Downloads\\27-B.txt"):
    f = open(file, 'r')

    N = int(f.readline())
    mas = []
    for line in f:
        val = int(line)
        mas += [val]

    sums = [0]
    s = 0
    cnt = 0
    for val in mas:
        s += val
        if val%2 == 0:
            cnt += 1
            sums += [s]
        
        if cnt == 9:
            break

    s = 0
    cnt = 0
    res = 0

    for val in mas:
        s += val
        if val % 2 == 0:
            cnt += 1
        res = max(res, s - sums[cnt%10])

    print(res)