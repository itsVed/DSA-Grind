class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []

        for i in range(12):
            for j in range(60):
                if i.bit_count() + j.bit_count() == turnedOn :
                    h = str(i)
                    m = "0" + str(j) if j < 10 else str(j)

                    ans.append(h + ":" + m)
        
        return ans