class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        water = 0
        leftMax = [-1 for h in height]
        rightMax = [-1 for h in height]

        currMax = -1
        for i, h in enumerate(height):
            currMax = max(currMax, height[i])
            leftMax[i] = currMax
        currMax = -1
        for i, h in reversed(list(enumerate(height))):
            currMax = max(currMax, height[i])
            rightMax[i] = currMax

        for i in range(1, len(height)-1):
            totHeight = min(leftMax[i], rightMax[i])
            if height[i] < totHeight:
                water += totHeight - height[i]

        return water

