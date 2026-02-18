class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        
        one = False
        zero = False
        
        while n > 0 :
            
            bit = n & 1

            if bit:
                if one:
                    return False
                one = True
                zero = False
            else:
                if zero:
                    return False
                zero = True
                one = False
            
            n >>= 1
        
        return True
