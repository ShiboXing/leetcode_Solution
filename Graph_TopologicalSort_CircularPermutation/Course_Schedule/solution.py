#should have just used collections.defaultdict
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        if not prerequisites:
            return True
        g={}
        degrees={}
        zeros=[]
        res=set()
    
        for x in prerequisites:
            degrees.setdefault(x[0],0)
            degrees.setdefault(x[1],0)
            degrees[x[0]]+=1
            
            g.setdefault(x[1],set())
            g.setdefault(x[0],set())
            g[x[1]].add(x[0])
            
        for x in range(numCourses):
            degrees.setdefault(x,0)
            if  degrees[x]==0:
                res.add(x)
                if x in g:
                    zeros.append(x)
                
        print(zeros) 
        while zeros:
            new=zeros.pop(0)
            res.add(new)
            #print(new)
            for x in g[new]:
                degrees[x]-=1
                if degrees[x]==0:
                    zeros.append(x)
                
        print(res)
        return numCourses==len(res)
 
