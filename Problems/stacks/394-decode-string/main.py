class Solution:
    def decodeString(self, s: str) -> str:
        stack = [["", 1]]
        num = ""
        for c in s:
            if c.isdigit():
                num += c
            elif c == '[':
                stack.append(["", int(num)])
                num = ""
            elif c == ']':
                l, n = stack.pop()
                stack[-1][0] += l*n
            else:
                stack[-1][0] += c

        return stack[0][0]


testcase = Solution()
print(testcase.decodeString(input()))
