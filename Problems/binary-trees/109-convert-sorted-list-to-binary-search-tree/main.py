class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def invertList(head):
    prev = None
    while head:
        next = head.next
        head.next = prev
        prev = head
        head = next
    return prev


def sortList(head):
    if head:
        slow = head
        while slow.next:
            fast = slow.next
            while fast:
                if slow.val > fast.val:
                    temp = slow.val
                    slow.val = fast.val
                    fast.val = temp
                fast = fast.next
            slow = slow.next
    return head


def insertBST(root, val):
    if root is None:
        return TreeNode(val)
    else:
        if val > root.val:
            root.right = insertBST(root.right, val)
        else:
            root.left = insertBST(root.left, val)
        return root


def divideList(head, a, b):
    a = head
    prev_slow = None
    slow = head
    fast = head
    while fast and fast.next:
        prev_slow = slow
        slow = slow.next
        fast = fast.next.next
    if prev_slow:
        prev_slow.next = None
        b = slow
    else:
        b = None


def sortedListToBST(head: ListNode) -> TreeNode:
    if head is None:
        root = None
    else:
        prev_slow = None
        slow = head
        fast = head
        while fast and fast.next:
            prev_slow = slow
            slow = slow.next
            fast = fast.next.next
        root = TreeNode(slow.val)
        if prev_slow:
            prev_slow.next = None
            root.left = sortedListToBST(head)
            root.right = sortedListToBST(slow.next)
        else:
            root.left = None
            root.right = None
    return root

# def sortedListToBST(head: ListNode) -> TreeNode:
#     root = None
#     if head:
#         left = None
#         right = None
#         # divideList(head, left, right)
#
#         left = head
#         prev_slow = None
#         slow = head
#         fast = head
#         while fast and fast.next:
#             prev_slow = slow
#             slow = slow.next
#             fast = fast.next.next
#         if prev_slow:
#             prev_slow.next = None
#             right = slow
#         else:
#             right = None
#
#         left = invertList(left)
#         right = invertList(right)
#         if right:
#             root = TreeNode(right.val)
#             right = right.next
#
#         node = right
#         while node:
#             root = insertBST(root, node.val)
#             node = node.next
#
#         node = left
#         while node:
#             root = insertBST(root, node.val)
#             node = node.next
#
#     return root
