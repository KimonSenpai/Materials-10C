for file in ("D:\\Downloads\\27_A (1).txt", "D:\\Downloads\\27_B (1).txt"):
    f = open(file, 'r')

    N = int(f.readline())

    dp = [[-10**18]*17 for _ in range(N + 1)]

    dp[0][0] = 0
    i = 0
    for line in f:
        val = int(line)
        i += 1
        for d in range(17):
            dp[i][d] = max(dp[i][d], dp[i-1][d])
            dp[i][(d + val)%17] = max(dp[i][(d + val)%17], dp[i-1][d] + val)

    print(dp[N][0])