class MyStack(object):
    q = None
    def __init__(self):
        self.q = []
    def push(self, x):
        self.q.append(x)
    def pop(self):
        return self.q.pop(-1)
    def top(self):
        return self.q[-1]
    def empty(self):
        return len(self.q) == 0