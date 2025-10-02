class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int bottledrunk = numBottles;
        int empty = numBottles;
        int fullbottle = 0;

        while(empty >= numExchange){
            
            empty -= numExchange;
            numExchange++;
            bottledrunk++;
            empty++;
        }

        return bottledrunk;
    }
};