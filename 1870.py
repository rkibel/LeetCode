import math
class Solution(object):
    def minSpeedOnTime(self, dist, hour):
        def makesOnTime(speed):
            totalTime = 0
            for i, d in enumerate(dist):
                if i == len(dist)-1:
                    totalTime += d / (1.0*speed)
                else:
                    totalTime += math.ceil(d / (1.0*speed))
            return totalTime <= hour
        lower = 1
        upper = 10e9
        if not makesOnTime(upper): return -1
        med = upper
        while upper > lower:
            test = int((upper+lower)/2)
            if makesOnTime(test):
                med = test
                upper = med
            else:
                lower = test+1
        return med