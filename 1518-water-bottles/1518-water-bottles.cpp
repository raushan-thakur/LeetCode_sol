class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total_drinking_bottles = numBottles;
        int remaining_empty = 0;
        while(numBottles >= numExchange){
           total_drinking_bottles += numBottles/numExchange;
           remaining_empty = numBottles/numExchange + numBottles%numExchange;
           numBottles = remaining_empty;
        }
        return total_drinking_bottles;
    }
};