class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def inOrder(root):
    if root is not None:
        inOrder(root.left)
        print(root.val, end=', ')
        inOrder(root.right)


def inorderTraversal(root: TreeNode) -> list[int]:
    res = []
    if root is not None:
        S = []
        curr = root
        while curr is not None or len(S):
            if curr is not None:
                S.append(curr)
                curr = curr.left
            elif len(S):
                curr = S.pop()
                res.append(curr.val)
                curr = curr.right
    return res


tree = TreeNode(3, TreeNode(1, TreeNode(2, TreeNode(10)), TreeNode(0)), TreeNode(8))
inOrder(tree)
print()
print(inorderTraversal(tree))

