#105

res = None
dif = 10000000000
for val in range(523456, 578925 + 1):
    v = val
    divs = []
    div = 2
    while div*div < v:
        if v % div == 0:
            divs += [div]
            v //= div
        else:
            div += 1
    divs += [v]
    if len(divs) == 2 and len(set(divs)) == 2:
        if dif > divs[1] - divs[0]:
            dif = divs[1] - divs[0]
            res = divs

print(*res)