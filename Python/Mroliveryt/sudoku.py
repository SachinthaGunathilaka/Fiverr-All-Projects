import numpy as np


def grid_to_values(grid, boxes):
    sudoku_grid = {}
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                sudoku_grid[boxes[i * 9 + j]] = '123456789'

            else:
                sudoku_grid[boxes[i * 9 + j]] = str(grid[i][j])
    return sudoku_grid


def cross(A, B):
    return [x + y for x in A for y in B]


def is_solved(values, boxes, unitlist):
    fully_reduced = all(len(values[s]) == 1 for s in boxes)
    if not fully_reduced:
        return False

    for unit in unitlist:
        required_digits = '123456789'
        for box in unit:
            required_digits = required_digits.replace(values[box], '')
        if len(required_digits) != 0:
            return False
    return True


def naked_twins(values, unitlist):
    for unit in unitlist:
        twin_values = find_twins(values, unit)
        values = eliminate_twin_values(values, unit, twin_values)
    return values


def eliminate_twin_values(values, unit, twin_values):
    for box in unit:
        if values[box] in twin_values:
            continue
        for twin in twin_values:
            for digit in twin:
                values = remove_digit(values, box, digit)
    return values


def find_twins(values, unit):
    unit_values = [values[box] for box in unit]
    return [value for value in unit_values if unit_values.count(value) == 2 and len(value) == 2]


def remove_digit(values, box, digit):
    values[box] = values[box].replace(digit, '')
    return values


def eliminate(values, peers):
    for box, value in values.items():
        if len(value) == 1:
            for peer in peers[box]:
                values = remove_digit(values, peer, value)
    return values


def only_choice(values, unitlist):
    for group in unitlist:
        for digit in '123456789':
            remainder = [box for box in group if digit in values[box]]
            if len(remainder) == 1:
                values[remainder[0]] = digit
    return values


def reduce_puzzle(values, peers, unitlist):
    stalled = False
    while not stalled:
        solved_values_before = len([box for box in values.keys() if len(values[box]) == 1])

        values = eliminate(values, peers)

        values = naked_twins(values, unitlist)

        values = only_choice(values, unitlist)

        # Check how many boxes have a determined value, to compare
        solved_values_after = len([box for box in values.keys() if len(values[box]) == 1])
        # If no new values were added, stop the loop.
        stalled = solved_values_before == solved_values_after
        # Sanity check, return False if there is a box with zero available values:
        if len([box for box in values.keys() if len(values[box]) == 0]):
            return False
    return values


def search(values, boxes, peers, unitlist):
    values = reduce_puzzle(values, peers, unitlist)
    if values is False:
        return False  ## Failed earlier
    if all(len(values[s]) == 1 for s in boxes):
        return values  ## Solved!
    # Choose one of the unfilled squares with the fewest possibilities
    n, s = min((len(values[s]), s) for s in boxes if len(values[s]) > 1)
    # Now use recurrence to solve each one of the resulting sudokus, and
    for value in values[s]:
        new_sudoku = values.copy()
        new_sudoku[s] = value
        attempt = search(new_sudoku, boxes, peers, unitlist)
        if attempt:
            return attempt


def solve(grid):
    rows = 'ABCDEFGHI'
    cols = '123456789'

    boxes = [r + c for r in rows for c in cols]
    row_units = [cross(r, cols) for r in rows]
    column_units = [cross(rows, c) for c in cols]
    square_units = [cross(rs, cs) for rs in ('ABC', 'DEF', 'GHI') for cs in ('123', '456', '789')]
    unitlist = row_units + column_units + square_units

    units = dict((s, [u for u in unitlist if s in u]) for s in boxes)
    peers = dict((s, set(sum(units[s], [])) - set([s])) for s in boxes)

    values = grid_to_values(grid, boxes)
    values = search(values, boxes, peers, unitlist)

    result = np.full((9, 9), -1)

    if is_solved(values, boxes, unitlist):
        for i in range(9):
            for j in range(9):
                result[i][j] = values[boxes[i * 9 + j]]

    return result


matrix = np.array([[1, 0, 4, 3, 8, 2, 9, 5, 6],
                   [2, 0, 5, 4, 6, 7, 1, 3, 8],
                   [3, 8, 6, 9, 5, 1, 4, 0, 2],
                   [4, 6, 1, 5, 2, 3, 8, 9, 7],
                   [7, 3, 8, 1, 4, 9, 6, 2, 5],
                   [9, 5, 2, 8, 7, 6, 3, 1, 4],
                   [5, 2, 9, 6, 3, 4, 7, 8, 1],
                   [6, 0, 7, 2, 9, 8, 5, 4, 3],
                   [8, 4, 3, 0, 1, 5, 2, 6, 9]])

result = solve(matrix)
print(result)
