from collections import defaultdict
class Solution(object):
    def findItinerary(self, tickets):
        d = defaultdict(list)
        for org, to in tickets: d[org].append(to)
        for key in d: d[key] = sorted(d[key])

        def constructPath(d, org):
            if not d: return [org]
            if org not in d: return None
            for dest in sorted(d[org]):
                d[org].remove(dest)
                if len(d[org]) == 0: d.pop(org)
                m = constructPath(d, dest)
                if m != None:
                    m.insert(0, str(org))
                    return m
                d[org].append(dest)
            return None
        
        return constructPath(d, "JFK")
        