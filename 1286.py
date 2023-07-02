class Problem1286(object):
    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.combinations = list(combinations(characters, combinationLength))
        self.counter = 0

    def next(self):
        
        """
        :rtype: str
        """
        self.counter += 1
        return "".join(self.combinations[self.counter-1])
        
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.counter < len(self.combinations)
        


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()