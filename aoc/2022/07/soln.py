class Filesystem:
    def __init__(self, name, size, is_directory=False, parent=None):
        self.name = name
        self.is_directory = is_directory
        self.children = [] if is_directory else None
        self.size = size
        self.parent = parent

    def add_child(self, name, size, is_directory=False):
        self.children.append(
            Filesystem(name, size, is_directory=is_directory, parent=self)
        )

    def up(self):
        if self.parent is None:
            return self
        else:
            return self.parent

    def to_child(self, name):
        if name == "..":
            return self.up()
        for child in self.children:
            if child.name == name:
                return child
        raise ValueError

total = 1000000000
def update_size(folder):
    if folder.is_directory:
        size = 0
        for child in folder.children:
            #if not child.is_directory:
            size += update_size(child)
        folder.size = size
        global total
        if size >= 6728267:
            total = min(size, total)
        return size
    else:
        return folder.size

def recurse(folder, level):
    print("{0}- {1} ({2}, {3})".format(
        "  " * level,
        folder.name,
        "dir" if folder.is_directory else "file",
        folder.size
    ))
    if folder.is_directory:
        for child in folder.children:
            recurse(child, level + 1)

def solve(lines):
    root = Filesystem("/", -1, is_directory=True)
    cwd = root
    for line in lines:
        if line.startswith("$ cd /"):
            continue
        elif line.startswith("$ cd"):
            cwd = cwd.to_child(line.split(" ")[-1])
        elif line.startswith("$ ls"):
            continue
        elif line.startswith("dir"):
            _, name = line.split(" ")
            cwd.add_child(name, -1, is_directory=True)
        else:
            size, name = line.split(" ")
            cwd.add_child(name, int(size), is_directory=False)
    update_size(root)
    recurse(root, 0)
    global total
    return total


with open("input") as input_file:
    # with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))

    23271733
