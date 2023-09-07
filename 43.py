class Solution(object):
    def multiply(self, num1, num2):
        def getNum(x):
            num = 0
            for char in x:
                num *= 10
                num += ord(char)-48
            return num

        x = getNum(num1) * getNum(num2)
        res = ''
        while x != 0:
            res = chr(x%10 + 48) + res
            x //= 10
        return '0' if res == '' else res
