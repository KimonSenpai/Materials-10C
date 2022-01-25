f = open("26.txt", 'r')

S, N = map(int, f.readline().split())
mas = [int(line) for line in f]


mas.sort()

s, k = 0, 0

while s + mas[k] <= S:
    s += mas[k]
    k += 1

print(k, end=' ')

s -= mas[k]

for val in mas[::-1]:
    if s + val <= S:
        print(val)
        break
