# простите, что сделал это, но на плюсах не залетало
# решение объяснил в C
# удалять это - поздно

def print_coords(x):
    n_left = ((8 * x + 1) ** 0.5 - 3) / 2
    # n_right = (math.sqrt(8 * x + 1)-1)/2
    n = int(n_left) + 1
    x_left = (n * (n + 1)) // 2
    # x_right = ((n + 1) * (n + 2)) // 2
    print(x_left)
    t = x - x_left
    return n - t, t
    
    
with open("input.txt", "r") as inp, open("output.txt", "w") as out:
    input_text = inp.read().split()
    n = int(input_text[0])
    
    for i in input_text[1:]:
        x = int(i)
        x, y = print_coords(x)
        out.write(f"{x} {y}\n")