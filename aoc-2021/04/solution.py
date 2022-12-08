class Board:

    def __init__(self, lines):
        self.board = lines
        self.marked = [[False for i in range(5)] for j in range(5)]
        self.marked_reverse = [[False for i in range(5)] for j in range(5)]

    def mark(self, number):
        for i, line in enumerate(self.board):
            for j, item in enumerate(line):
                if item == number:
                    self.marked[i][j] = True
                    self.marked_reverse[j][i] = True
                    return

    def won(self):
        return any(
            [all(line) for line in self.marked] +
            [all(line) for line in self.marked_reverse]
        )

    def score(self):
        ans = 0
        for i, line in enumerate(self.marked):
            for j, is_marked in enumerate(line):
                if not is_marked:
                    ans += self.board[i][j]
        return ans


def solve(lines):
    call_order, boards = [int(x) for x in lines[0].split(",")], lines[1:]
    board_lines = [line for line in boards if line]
    boards = []
    board = []
    for line in board_lines:
        board.append([int(x) for x in line.split()])
        if len(board) == 5:
            boards.append(Board(board))
            board = []
    scores = []
    for ball in call_order:
        for board in boards:
            if not board.won():
                board.mark(ball)
                if board.won():
                    scores.append(board.score() * ball)
    return scores[-1]

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))