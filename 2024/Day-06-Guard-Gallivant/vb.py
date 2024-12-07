def get_test_input():
    return """....#.....
    .........#
    ..........
    ..#.......
    .......#..
    ..........
    .#..^.....
    ........#.
    #.........
    ......#...""".strip().split()

def get_input():
    with open("input.txt") as f:
        return f.read().strip().split()

def rotate_right(direction):
    if direction == (0, -1):
        return (1, 0)
    if direction == (0, 1):
        return (-1, 0)
    if direction == (1, 0):
        return (0, 1)
    # if direction == (-1, 0):
    return (0, -1)

def part1(data, extra=None):
    data = list(map(list, data))
    x = 0
    y = 0
    for i, row in enumerate(data):
        if "^" in row:
            x = row.index("^")
            y = i
            break
    direction = (0, -1)
    visited = set()
    visited_pairs = set()

    if extra:
        data[extra[1]][extra[0]] = "#"

    while True:
        if y + direction[1] < 0 or y + direction[1] >= len(data) or x + direction[0] < 0 or x + direction[0] >= len(data[0]):
            break

        while data[y + direction[1]][x + direction[0]] == "#":
            direction = rotate_right(direction)

        x += direction[0]
        y += direction[1]
        if ((x, y), direction) in visited_pairs:
            return True

        visited_pairs.add(((x, y), direction))
        visited.add((x, y))
    return visited

path = part1(get_test_input())
print(f"Part 1 testing: {len(path)}, {path}")

data = get_input()
og_path = part1(data)
print(f"Part 1 input: {len(og_path)}")
print(f"Part 2 test: {sum(part1(get_test_input(), x) is True for x in path)}")
p2 = sum(part1(data, x) is True for x in og_path)
print(f"Part 2: {p2}")

# Part 1: 4883
# Part 2: 1655