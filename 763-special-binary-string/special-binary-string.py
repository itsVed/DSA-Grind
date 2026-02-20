class Solution:
    def solve(self, s: str) -> str:
        total = 0
        start = 0
        result = []

        for i in range(len(s)):
            total += 1 if s[i] == '1' else -1

            if total == 0:
                inner = s[start + 1:i]
                result.append("1" + self.solve(inner) + "0")
                start = i + 1

        result.sort(reverse=True)

        return "".join(result)

    def makeLargestSpecial(self, s: str) -> str:
        
        return self.solve(s)
