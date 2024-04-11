class Monkey:
    def __init__(self, items, op, opval, testval, if_true, if_false):
        self.items = items
        self.op = op
        self.opval = opval
        self.testval = testval
        if op == "+":
            if opval == "old":
                self.operation = lambda x: x + x
                self.operation_with_modulo = lambda x, m: ((x % m) + (x % m)) % m
            else:
                self.operation = lambda x: x + int(opval)
                self.operation_with_modulo = lambda x, m: ((x % m) + (int(opval) % m)) % m
        else:
            if opval == "old":
                self.operation = lambda x: x * x
                self.operation_with_modulo = lambda x, m: ((x % m) * (x % m)) % m
            else:
                self.operation = lambda x: x * int(opval)
                self.operation_with_modulo = lambda x, m: ((x % m) * (int(opval) % m)) % m
        self.if_true = if_true
        self.if_false = if_false
        self.throw = lambda x: if_true if (x % testval == 0) else if_false
        self.inspected_items = 0

    def initialize(self, modulos):
        items = []
        for item in self.items:
            items.append([])
            for modulo in modulos:
                items[-1].append(item % modulo)
        self.modulos = modulos
        self.items_new = items

    def operate(self, i):
        item = []
        for j, modulo in enumerate(self.modulos):
            item.append(self.operation_with_modulo(self.items_new[i][j], modulo))
        return item


def parse(lines):
    monkeys = []
    items, op, opval, testval, if_true, if_false = [], "", "", 0, 0, 0
    for line in lines:
        if line.startswith("Monkey"):
            if items == []: continue
            monkeys.append(Monkey(items, op, opval, testval, if_true, if_false))
            items, op, opval, testval, if_true, if_false = [], "", "", 0, 0, 0
        elif line.startswith("  Starting"):
            items = [int(x) for x in line.replace("  Starting items: ", "").split(", ")]
        elif line.startswith("  Operation"):
            op, opval = line.replace("  Operation: new = old ", "").split(" ")
        elif line.startswith("  Test"):
            testval = int(line.replace("  Test: divisible by ", ""))
        elif line.startswith("    If true"):
            if_true = int(line.replace("    If true: throw to monkey ", ""))
        elif line.startswith("    If false"):
            if_false = int(line.replace("    If false: throw to monkey ", ""))
    monkeys.append(Monkey(items, op, opval, testval, if_true, if_false))
    return monkeys


def solve1(lines):
    monkeys = parse(lines)
    for r in range(20):
        for monkey in monkeys:
            for item in monkey.items:
                new_item = monkey.operation(item) // 3
                i = monkey.throw(new_item)
                monkeys[i].items.append(new_item)
                monkey.inspected_items += 1
            monkey.items = []
    monkeys.sort(key=lambda x: x.inspected_items, reverse=True)
    return monkeys[0].inspected_items * monkeys[1].inspected_items


def solve2(lines):
    monkeys = parse(lines)
    modulos = []
    for monkey in monkeys:
        modulos.append(monkey.testval)
    for i in range(len(monkeys)):
        monkeys[i].initialize(modulos)
    for r in range(10000):
        for i, monkey in enumerate(monkeys):
            for j, item in enumerate(monkey.items_new):
                new_items = monkey.operate(j)
                idx = monkey.throw(new_items[i])
                monkeys[idx].items_new.append(new_items)
                monkey.inspected_items += 1
            monkey.items_new = []
    monkeys.sort(key=lambda x: x.inspected_items, reverse=True)
    return monkeys[0].inspected_items * monkeys[1].inspected_items
    pass


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
