/*

On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.

 

Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
Example 2:

Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
Example 3:

Input: X = 3, Y = 10
Output: 3
Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
Example 4:

Input: X = 1024, Y = 1
Output: 1023
Explanation: Use decrement operations 1023 times.
 

Note:

1 <= X <= 10^9
1 <= Y <= 10^9

*/



class Solution {
public:
    int brokenCalc(int X, int Y) {
        set<int> st;
        queue<pair<int,int>> stk;
        if(X==Y){
            return 0;
        }else{
            stk.push(make_pair(X,0));
            st.insert(X);
            while(!stk.empty()){
                pair<int,int> p = stk.front();
                stk.pop();
                if(p.first-1==Y){
                    return p.second+1;
                }else{
                    if(p.first-1>=0){
                        if(st.find(p.first-1)==st.end()){
                        
                            st.insert(p.first-1);
                            stk.push(make_pair(p.first-1,p.second+1));
                            //cout<<p.first-1<<endl;
                    }
                    }
                    
                }
                if((p.first*2)==Y){
                    return p.second+1;
                }else{
                    if(p.first*2<=Y*2){
                        if(st.find(p.first*2)==st.end()){
                        
                            st.insert(p.first*2);
                            stk.push(make_pair(p.first*2,p.second+1));
                            //cout<<p.first*2<<endl;
                        
                    }
                    }
                    
                }
            }
        }
        return -1;
    }
};
