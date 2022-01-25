#135

for val in range(321654, 654321):
    mas = []
    for div in range(2, int(val**0.5) + 1):
        if val%div == 0:
            mas += [div]
            if div != val//div:
                mas += [val//div]

    if len(mas) > 70 and all(map(lambda x: x%2 == 1, mas)):
        print(val, max(mas))