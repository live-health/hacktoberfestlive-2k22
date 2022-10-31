// Recursive Approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(mincost(cost,0), mincost(cost,1));
    }
    
    int mincost(vector<int>&cost, int current){
        
        if(current == cost.size()){
            return 0;
        }
        
        if(current>cost.size()){
            return 1001;
        }
        
        int single = cost[current] + mincost(cost,current+1);
        int two = cost[current] + mincost(cost,current+2);

        return min(single,two);
    }
};


//Dp optimized using maps
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {  
        return min(mincost(cost,0), mincost(cost,1));
    }
    unordered_map<int, int>map;
    int mincost(vector<int>& cost, int current){
        if(current == cost.size())
            return 0;
        if(current>cost.size())
            return 1001;
        
        //checking Overlapping Subproblem
        
        int current_key = current;
        if(map.find(current) != map.end())
            return map[current_key];
        
        int onejump = cost[current] + mincost(cost, current+1);
        int twojump = cost[current] + mincost(cost, current+2);
        
        map[current_key] = min(onejump, twojump);
        return min(onejump, twojump);
        
    }
};