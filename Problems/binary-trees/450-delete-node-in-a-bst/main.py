# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def printInOrder(root: TreeNode):
    if root is not None:
        printInOrder(root.left)
        print(root.val)
        printInOrder(root.right)


def findFullNode(root):
    if root is not None:
        findFullNode(root.left)
        if root.left is not None and root.right is not None:
            print(root.val, end=" ")
        findFullNode(root.right)


def lowestCommonAncestor(root: TreeNode):
    if root is None or root.left is None:
        return root
    else:
        return lowestCommonAncestor(root.left)


def deleteNode(root: TreeNode, key: int) -> TreeNode:
    if root is not None:
        if root.val == key:
            if root.left is None and root.right is None:
                root = None
            elif root.left is None and root.right is not None:
                temp = root.right
                # root = None
                root = temp
            elif root.left is not None and root.right is None:
                temp = root.left
                # root = None
                root = temp
            else:
                temp = lowestCommonAncestor(root.right)
                root.val = temp.val
                root.right = deleteNode(root.right, temp.val)
        elif key > root.val:
            root.right = deleteNode(root.right, key)
        else:
            root.left = deleteNode(root.left, key)

    return root


tree = TreeNode(5)
tree.left = TreeNode(7)
tree.right = TreeNode(12)
tree.right.right = TreeNode(33)
tree.right.left = TreeNode(-1)
tree.left.left = TreeNode(4)
# print(lowestCommonAncestor(tree).val)
findFullNode(tree)
# deleteNode(tree, 5)
findFullNode(tree)
# printInOrder(tree)
