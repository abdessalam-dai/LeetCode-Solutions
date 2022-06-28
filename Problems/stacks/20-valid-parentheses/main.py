class Solution:
    def isValid(self, s: str) -> bool:
        parentheses = []  # parentheses stack
        closers = {')': '(',
                   '}': '{',
                   ']': '['}
        if not len(s):
            return True

        for par in s:
            if par in closers:
                if len(parentheses) == 0:
                    return False
                last_par = parentheses.pop()
                parentheses.append(last_par)
                if closers[par] == last_par:
                    parentheses.pop()
                else:
                    return False
            else:
                parentheses.append(par)
        return not len(parentheses)


testcase = Solution()
print(testcase.isValid(input()))
