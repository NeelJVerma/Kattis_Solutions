class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.child = 1

class Tree:
    def __init__(self):
        self.root = None
        self.dp = [[1 for i in range(100)] for j in range(100)]

    def fill_dp(self):
        for i in range(1, 100):
            for j in range(1, 100):
                self.dp[i][j] = self.dp[i - 1][j] + self.dp[i][j - 1]

    def add_helper(self, node, data):
        if data < node.data:
            if node.left:
                self.add_helper(node.left, data)
            else:
                node.left = Node(data)
        else:
            if node.right:
                self.add_helper(node.right, data)
            else:
                node.right = Node(data)

        node.child += 1

    def add(self, data):
        if not self.root:
            self.root = Node(data)
        else:
            self.add_helper(self.root, data)

    def print_tree_helper(self, node):
        if node:
            self.print_tree_helper(node.left)
            print(node.data)
            self.print_tree_helper(node.right)

    def print_tree(self):
        self.print_tree_helper(self.root)

    def different_perms_helper(self, node):
        if not node:
            return 1

        total = 1

        if node.right and node.left:
            total = self.dp[node.left.child][node.right.child]

        total *= self.different_perms_helper(node.left)
        total *= self.different_perms_helper(node.right)

        return total

    def different_perms(self):
        return self.different_perms_helper(self.root)

while True:
    numnodes = int(input())

    if numnodes == 0:
        break

    nodes = [int(x) for x in input().split()]
    tree = Tree()

    for node in nodes:
        tree.add(node)

    tree.fill_dp()
    
    print(tree.different_perms())