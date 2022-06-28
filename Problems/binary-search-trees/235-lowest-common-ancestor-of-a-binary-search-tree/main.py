class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None





def searchInBST(root, val):
    if root is None or root.val == val:
        return root
    elif val > root.val:
        return searchInBST(root.right, val)
    else:
        return searchInBST(root.left, val)


def lowestCommonAncestor(root, p, q):
    pileAncestors = []
    pileNodes = [root]
    while len(pileNodes):
        node = pileNodes.pop()
        if searchInBST(node, p.val) and searchInBST(node, q.val):
            pileAncestors.append(node)
            if node.left:
                pileNodes.append(node.left)
            if node.right:
                pileNodes.append(node.right)
    if len(pileAncestors):
        return pileAncestors.pop()
