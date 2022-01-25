INF = 10000000000000
for file in ("27_A.txt", "27_B.txt"):
    f = open(file, 'r')

    N = int(f.readline())

    pref = [INF]*43
    pref[0] = 0
    prefl = [0]*43

    s = 0
    l = 0
    maxS, maxL = 0, 0
    for line in f:
        val = int(line)
        s += val
        l += 1
        if maxS < s - pref[s%43] or (maxS == s - pref[s%43] and maxL > l - prefl[s%43]):
            maxS = s - pref[s%43]
            maxL = l - prefl[s%43]

        if pref[s%43] >= s:
            pref[s%43] = s
            prefl[s%43] = l 


    print(maxL, end=' ')

print()