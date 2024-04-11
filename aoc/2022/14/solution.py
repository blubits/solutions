class SandSimulator:
    def __init__(self):
        self.xlo = 0
        self.xhi = 0
        self.yleft = float("inf")
        self.yright = 0
        self.structures = set()
        self.sand = set()

    def add_structure(self, fr, to):
        self.xlo = min(self.xlo, fr[0], to[0])
        self.xhi = max(self.xhi, fr[0], to[0])
        self.yleft = min(self.yleft, fr[1], to[1])
        self.yright = max(self.yright, fr[1], to[1])
        if fr[0] == to[0]:
            x = fr[0]
            yfr, yto = min(fr[1], to[1]), max(fr[1], to[1])
            for y in range(yfr, yto + 1):
                self.structures.add((x, y))
        if fr[1] == to[1]:
            y = fr[1]
            xfr, xto = min(fr[0], to[0]), max(fr[0], to[0])
            for x in range(xfr, xto + 1):
                self.structures.add((x, y))

    def add_floor(self):
        self.add_structure((self.xhi + 2, self.yleft - 1000), (self.xhi + 2, self.yright + 1000))

    def flood_fill(self):
        xs, ys = 0, 500

        def drop():
            x, y = xs, ys
            while not self.out_of_bounds(x, y):
                if self.can_drop(x + 1, y):
                    x, y = x + 1, y
                elif self.can_drop(x + 1, y - 1):
                    x, y = x + 1, y - 1
                elif self.can_drop(x + 1, y + 1):
                    x, y = x + 1, y + 1
                else:
                    if (x, y) in self.sand:
                        return False
                    self.sand.add((x, y))
                    return True
            return False
                
        while drop():
            pass

        return len(self.sand)

    def __str__(self):
        def represent(x, y):
            if (x, y) in self.structures:
                return "#"
            elif (x, y) in self.sand:
                return "o"
            elif (x, y) == (0, 500):
                return "+"
            else:
                return "."
        board = [
            [
                represent(x, y)
                for y in range(self.yleft, self.yright + 1)
            ]
            for x in range(self.xlo, self.xhi + 1)
        ]
        return "\n".join(["".join(row) for row in board])

    def out_of_bounds(self, x, y):
        return not (self.xlo <= x <= self.xhi)

    def can_drop(self, x, y):
        return (x, y) not in self.sand and (x, y) not in self.structures

def solve1(lines):
    structures = [line.split(" -> ") for line in lines]
    sim = SandSimulator()
    for structure in structures:
        for i in range(len(structure) - 1):
            fr, to = structure[i], structure[i + 1]
            yfr, xfr = [int(x) for x in fr.split(",")]
            yto, xto = [int(x) for x in to.split(",")]
            sim.add_structure((xfr, yfr), (xto, yto))
    return sim.flood_fill()

def solve2(lines):
    structures = [line.split(" -> ") for line in lines]
    sim = SandSimulator()
    for structure in structures:
        for i in range(len(structure) - 1):
            fr, to = structure[i], structure[i + 1]
            yfr, xfr = [int(x) for x in fr.split(",")]
            yto, xto = [int(x) for x in to.split(",")]
            sim.add_structure((xfr, yfr), (xto, yto))
    sim.add_floor()
    return sim.flood_fill()


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
