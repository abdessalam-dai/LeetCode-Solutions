class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Dump code (My first attempt)
# def isValidBST(root: TreeNode) -> bool:
#     if root is None:
#         return True
#     elif root.left is None and root.right is None:
#         return True
#     elif root.left is not None and root.right is not None:
#         return root.right.val > root.val > root.left.val and isValidBST(root.right) and isValidBST(root.left)
#     elif root.left is not None and root.right is None:
#         return root.val > root.left.val and isValidBST(root.left)
#     else:
#         return root.val < root.right.val and isValidBST(root.right)


def isArrSorted(arr: list[int], size: int) -> bool:
    valid = True
    prev = arr[0]
    i = 1
    while valid and i < len(arr):
        if arr[i] <= prev:
            valid = False
        prev = arr[i]
        i += 1
    return valid


def isValidBST(root: TreeNode) -> bool:
    inOrderValues = []
    size = -1
    P = []
    curr = root
    while len(P) or curr is not None:
        if curr is not None:
            P.append(curr)
            curr = curr.left
        else:
            curr = P.pop()
            size += 1
            inOrderValues.append(curr.val)
            curr = curr.right
    return isArrSorted(inOrderValues, size)


tree = TreeNode(1, TreeNode(1))
print()
print(isValidBST(tree))