import queue

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        #dlen=len(days)
        last7=[]
        last30=[]
        cost=0
        
        for x in days:
            while last7 and x-last7[0][0]>=7:
                del last7[0]
            while last30 and x-last30[0][0]>=30:
                del last30[0]
            
            last7.append([x,cost+costs[1]])
            last30.append([x,cost+costs[2]])
            #print(last7.queue,last30.queue)
            cost=min(cost+costs[0],last7[0][1],last30[0][1])
            #print("cost:" ,cost,"x: ",x)
        return cost    