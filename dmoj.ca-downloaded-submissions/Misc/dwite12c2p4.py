outputs = []
for i in range(5):

    total = int(input())
    ordered = [x for x in range(1, total + 1)]
    cards = [int(x) for x in input().split()]

    output = ""

    for i in range(total):
        try:
            output += str(ordered.pop(-cards[i] - 1)) + (" " if i != total - 1 else "")

        except IndexError:
            outputs.append("IMPOSSIBLE")
            break

    else:
        outputs.append(output)

print(*outputs, sep="\n")