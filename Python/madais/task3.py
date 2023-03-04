def cal_distance(p1, p2):
    x1, y1 = p1
    x2, y2 = p2

    x_dist = (x2 - x1) ** 2
    y_dist = (y2 - y1) ** 2

    return (x_dist + y_dist) ** (1 / 2)


def run_robot():
    print("------ Robot Program ------")

    step = 1
    x = 0
    y = 0
    points = [[0, 0]]

    while x != 999 and y != 999:
        x = int(input(f"Input x{step} coordinates: "))
        y = int(input(f"Input y{step} coordinates: "))

        points.append((x, y))
        step += 1

    print("----------")
    total_distance = 0
    for i in range(1, len(points) - 1):
        distance = cal_distance(points[i - 1], points[i])
        total_distance += distance
        print("Step %d: %.2f units." % (i, distance))

    print("----------")
    print("Total distance travelled by the robot: %.2f units" % total_distance)
    print("----------")

    print("-Direction-")

    for i in range(1, len(points) - 1):
        direction = ""
        x1, y1 = points[i - 1]
        x2, y2 = points[i]
        if (x1 == x2) and (y1 < y2):
            direction = "Top"

        elif (x1 == x2) and (y1 > y2):
            direction = "Bottom"

        elif (y1 == y2) and (x1 < x2):
            direction = "Right"

        elif (y1 == y2) and (x1 > x2):
            direction = "Left"

        elif (x1 < x2) and (y1 < y2):
            direction = "Top Right"

        elif (x1 < x2) and (y1 > y2):
            direction = "Bottom Right"

        elif (x1 > x2) and (y1 < y2):
            direction = "Top Left"

        elif (x1 > x2) and (y1 > y2):
            direction = "Bottom Left"

        print(f"Step {i}: {direction}")

if __name__ == '__main__':

    run_robot()
