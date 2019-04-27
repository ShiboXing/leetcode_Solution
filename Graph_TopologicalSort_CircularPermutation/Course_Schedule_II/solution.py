#again, should have used defaultdict
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        
        n=numCourses
        p=prerequisites
        
        g={}
        d={}
        for x in range(n):
            d.setdefault(x,0)
            g.setdefault(x,set())
            
            
        for x in p:
            print(x[0])
            g[x[1]].add(x[0])
            d[x[0]]+=1 
        
        zeros=[]
        for x in d.keys():
            if not d[x]:
                zeros.append(x)
                
        res=[]
        while zeros:
            new=zeros.pop(0)
            res.append(new)
            for x in g[new]:
                d[x]-=1
                if not d[x]:
                    zeros.append(x)
                    
        if not len(res)==n:
            return []
        
        return res
