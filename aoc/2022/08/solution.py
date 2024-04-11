def solve(lines):
    board = [[int(x) for x in line] for line in lines]
    r, c = len(board), len(board[0])
    scenic_score = 0
    for row in range(1, r - 1):
        for col in range(1, c - 1):
            left, right, top, bottom = 1, 1, 1, 1
            # left visibility
            curr_row, curr_col = row, col - 1
            while curr_col != 0 and board[curr_row][curr_col] < board[row][col]:
                left += 1
                curr_col -= 1
            # right visibility
            curr_row, curr_col = row, col + 1
            while curr_col != c - 1 and board[curr_row][curr_col] < board[row][col]:
                right += 1
                curr_col += 1
            # top visibility
            curr_row, curr_col = row - 1, col
            while curr_row != 0 and board[curr_row][curr_col] < board[row][col]:
                top += 1
                curr_row -= 1
            # bottom visibility
            curr_row, curr_col = row + 1, col
            while curr_row != r - 1 and board[curr_row][curr_col] < board[row][col]:
                bottom += 1
                curr_row += 1
            #print(row, col, board[row][col], top, left, right, bottom, left * right * top * bottom)
            scenic_score = max(scenic_score, left * right * top * bottom)
    return scenic_score
    

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))