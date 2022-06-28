class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def inOrder(root, inOrderValues):
    if root:
        inOrder(root.left, inOrderValues)
        inOrderValues.append(root.val)
        inOrder(root.right, inOrderValues)


def getMinimumDifference(root: TreeNode) -> int:
    inOrderValues = []
    inOrder(root, inOrderValues)
    distances = []
    for i in range(len(inOrderValues)-1):
        for j in range(i+1, len(inOrderValues)):
            distances.append(abs(inOrderValues[i]-inOrderValues[j]))
    return min(distances)

