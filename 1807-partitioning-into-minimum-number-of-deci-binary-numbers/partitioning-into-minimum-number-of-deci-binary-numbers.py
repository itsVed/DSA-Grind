class Solution:
    def minPartitions(self, n: str) -> int:
        ch = ''
        for i in n :
            if i > ch :
                ch = i
        
        return int(ch)
        