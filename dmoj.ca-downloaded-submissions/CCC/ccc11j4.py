# Current tunnel coords list
tunnel = [(0, -1),(0, -2),(0, -3),(1, -3),(2, -3),(3, -3),(3, -4),(3, -5),(4, -5),(5, -5),(5, -4),(5, -3),(6, -3),(7, -3),
 (7, -4),(7, -5),(7, -6),(7, -7),(6, -7),(5, -7),(4, -7),(3, -7),(2, -7),(1, -7),(0, -7),(-1, -7),(-1, -6),(-1, -5)]

intersecting = False

# Keep going until you dig in a circle
while not intersecting:

    direction, movement = input().split()

    if direction == "q":
        break

    if direction == "r":
        axis = 0
        negative = 1
    elif direction == "l":
        axis = 0
        negative = -1
    elif direction == "u":
        axis = 1
        negative = 1
    elif direction == "d":
        axis = 1
        negative = -1


    # Go for the amount of times in theInput[1]
    for i in range(int(movement)):

        # new = last element + direction
        if axis == 0:
            new = (tunnel[-1][0] + negative, tunnel[-1][1])
        else:
            new = (tunnel[-1][0], tunnel[-1][1] + negative)

        # If coords are already in the tunnel
        if new in tunnel:
            intersecting = True
        tunnel.append(new)

    # Print end result, and if safe or danger
    print(*tunnel[-1], "DANGER" if intersecting else "safe")