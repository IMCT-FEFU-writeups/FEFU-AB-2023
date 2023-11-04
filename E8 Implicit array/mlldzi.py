# лучше всего будет понять алгоритм создания тестовых данных (он в самом конце) и написать решения с нуля, тк здесь тупо перебор всех ситуаций

with open('input.txt', 'r') as f:
    s = f.readlines()
    N = int(s[0])
    sets = [sorted(list(map(int, i.split()[1:]))) for i in s[1:]]

result = []

for i in range(len(sets)):
    # если длина множества соседей и самого числа (мссч) = 1, то выбираем однозначно
    if len(sets[i]) == 1:
        result.append(sets[i][0])
    # если длина мссч = 3, то выбираем среднее, тк сосед слева меньше, справа больше
    elif len(sets[i]) == 3:
        result.append(sets[i][1])
    else:
        # если мы на 1 элементе массива и его длина мссч равна 2, то выбираем меньшее из чисел
        if i == 0 and len(sets[i]) == 2:
            result.append(sets[i][0])

        # дальше мне лень всё расписывать, и это бесполезно, тк нужно показывать на примерах
        elif i != N - 1:
            if len(sets[i - 1]) == 2 and len(sets[i + 1]) == 1 and sets[i] == sets[i - 1]:
                result.append(sets[i][1])

            # случаи, когда len(sets[i +-(=) 1]) == 2
            elif len(sets[i - 1]) == 1 and len(sets[i + 1]) == 2 and sets[i] == sets[i + 1]:
                result.append(sets[i][0])

            elif len(sets[i - 1]) == 2 and len(sets[i + 1]) == 2 and sets[i] == sets[i - 1]:
                result.append(sets[i][1])
            elif len(sets[i - 1]) == 2 and len(sets[i + 1]) == 2 and sets[i] != sets[i - 1]:
                result.append(sets[i][0])

            elif len(sets[i - 1]) == 2 and len(sets[i + 1]) == 1 and sets[i] == sets[i - 1]:
                result.append(sets[i][1])

            # случаи, когда len(sets[i +- 1]) == 3
            elif len(sets[i - 1]) <= 2 and len(sets[i + 1]) == 3:
                result.append(sets[i][0])

            elif len(sets[i - 1]) == 3 and len(sets[i + 1]) <= 2:
                result.append(sets[i][1])

        elif len(sets[i - 1]) <= 3 and i == N - 1:
            result.append(sets[i][1])
with open('output.txt', 'w') as f:
    f.write(" ".join(map(str, result)))

# алгоритм создания входных данных
# a = [-11, -10, -10, -10, 1, 1, 1, 1, 2, 2, 2, 10000, 100000]
#
# N = len(a)
# print(N)
# for i in range(len(a)):
#     sub = set()
#     sub.add(a[i])
#     if i == 0 and N != 1:
#         sub.add(a[i + 1])
#     elif i == N - 1:
#         sub.add(a[i - 1])
#     else:
#         sub.add(a[i - 1])
#         sub.add(a[i + 1])
#     print(len(sub), *sorted(list(sub)))
#

