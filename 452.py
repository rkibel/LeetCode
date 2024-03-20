class Solution(object):
    def findMinArrowShots(self, points):
        points = sorted(points, key = lambda x: x[1])
        arrows = 1
        placementArrow = points[0][1]
        for index in range(1, len(points)):
            if points[index][0] > placementArrow:
                placementArrow = points[index][1]
                arrows += 1
        return arrows