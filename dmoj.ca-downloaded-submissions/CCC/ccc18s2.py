def matrix_print(list_):
    for row in list_:
        for x in range(len(row) - 1):
            print(row[x], '', end="")
        else:
            print(row[len(row) - 1])


matrix = list([int(x) for x in input().split(" ")] for r in range(int(input())))
change = False
while True:
    for row in matrix:
        for place in range(len(row) - 1):
            if row[place] > row[place + 1]:
                change = True
                break

        if change:
            break

    if change:
        matrix = list(zip(*matrix[::-1]))
        change = False
    else:

        for x in range(len(matrix) - 1):
            if matrix[x][0] > matrix[x + 1][0]:
                matrix = list(zip(*matrix[::-1]))
                break
        else:
            matrix_print(matrix)
            break