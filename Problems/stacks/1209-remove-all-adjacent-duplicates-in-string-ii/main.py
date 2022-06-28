# my solution, very complex though
# class Solution:
#     def removeDuplicates(self, s: str, k: int) -> str:
#         stack = []
#         for c in s:
#             if len(stack) >= k-1 and all(stack[-i] == c for i in range(1, k)):
#                 for _ in range(k-1):
#                     stack.pop()
#             else:
#                 stack.append(c)
#         return ''.join(stack)

# the best solution
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = [['#', 0]]
        for c in s:
            if stack[-1][0] == c:
                stack[-1][1] += 1
                if stack[-1][1] == k:
                    stack.pop()
            else:
                stack.append([c, 1])
        return ''.join(c * k for c, k in stack)


testcase = Solution()
print(testcase.removeDuplicates(input(), int(input())))
