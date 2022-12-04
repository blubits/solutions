class TreeNode:

    def __init__(self):
        self.parent = None
        self.children = []
        self.metadata = []

    def add_child(self, child):
        self.child.parent = self
        self.children.append(child)

    def add_metadata(self, data):
        self.metadata.append(data)

def treefy(L, n):
    if n == 0:
        return None
    node = TreeNode()
    num_children = L[0]
    num_metadata = L[1]
