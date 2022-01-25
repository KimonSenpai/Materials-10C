#96

for val in range(81234, 134689 + 1):
    mas = []
    for div in range(2, int(val**0.5) + 1):
        if val % div == 0:
            mas += [div]
            if div != val//div:
                mas += [val//div]
            
    if len(mas) == 3:
        print(mas)
        print(mas[0], mas[1])