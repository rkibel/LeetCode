class Problem1701(object):
    def averageWaitingTime(self, customers):
        currTime = 0
        totWait = 0
        for customer in customers:
            arrival, time = customer
            currTime = max(arrival, currTime)
            currTime += time
            totWait += (currTime - arrival)
        return float(totWait) / len(customers)
        