class Problem1598(object):
    def minOperations(self, logs):
        num = 0
        for log in logs:
            if log == "../":
                num -= 1
                num = max(0, num)
            elif log != "./": num += 1
        return num
        