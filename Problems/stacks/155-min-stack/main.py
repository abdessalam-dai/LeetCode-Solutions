class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)

    def pop(self) -> None:
        if len(self.stack):
            self.stack.pop()

    def top(self) -> int:
        if len(self.stack):
            return self.stack[-1]

    def getMin(self) -> int:
        if len(self.stack):
            return min(self.stack)


# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(int(input()))
obj.pop()
param_3 = obj.top()
param_4 = obj.getMin()
