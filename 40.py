class Solution(object):
    def combinationSum2(self, candidates, target):
        candidates.sort()
        dp = [[] for i in range(target+1)]
        dp[0].append([])
        freq = 1
        for i, c in enumerate(candidates):
            if c > target: break
            elif i != len(candidates)-1 and c == candidates[i+1]: freq += 1
            else:
                temp = [c]
                temp_dp = [[] for it in range(target+1)]
                for val in range(c, target+1, c):
                    if len(temp) > freq: break
                    for j in range(0, target+1-val):
                        for arr in dp[j]:
                            new_arr = arr[:]
                            new_arr.extend(temp)
                            temp_dp[j + val].append(new_arr)
                    temp.append(c)
                for j in range(1, target+1): dp[j].extend(temp_dp[j])
                freq = 1
        return dp[target]

        