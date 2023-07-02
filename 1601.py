import List

class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        ans = 0
        def recurse(start, indeg, count):
            nonlocal ans, n, requests
            if start == len(requests):
                for i in range(n):
                    if indeg[i] != 0: return
                ans = max(ans, count)
                return
            
            indeg[requests[start][0]] -= 1
            indeg[requests[start][1]] += 1
            recurse(start + 1, indeg, count + 1)

            indeg[requests[start][0]] += 1
            indeg[requests[start][1]] -= 1
            recurse(start + 1, indeg, count)
        
        indeg = [0 for i in range(n)]
        recurse(0, indeg, 0)
        return ans

