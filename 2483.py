class Solution(object):
    def bestClosingTime(self, customers):
        # O(1) space and O(n) time
        curr = m = 0
        index = -1
        for i, char in enumerate(customers):
            curr += 1 if char == 'N' else -1
            if curr < m: m, index = curr, i
        
        return index+1

        # O(n) space and O(n) time
        '''
        losses = [0] * (len(customers)+1)
        for i, char in enumerate(customers):
            losses[i+1] = losses[i] + int(char == 'N')
        tot = 0
        for i in reversed(range(len(customers))):
            tot += int(customers[i] == 'Y')
            losses[i] += tot
        return losses.index(min(losses))
        '''