class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for c in s:
            if len(stack) and c == stack[-1]:
                stack.pop()
            else:
                stack.append(c)
        return ''.join(stack)


testcase = Solution()
print(testcase.removeDuplicates(input()))
