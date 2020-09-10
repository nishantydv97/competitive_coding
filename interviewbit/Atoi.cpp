/*

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9

*/

int Solution::atoi(const string str) {
    if (str.size() == 0) return 0;
        int index = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') index++;
            else break;
        }
        int result = 0;
        bool isNeg = false;
        if (str[index] == '-') isNeg = true;
        if (str[index] == '-' || str[index] == '+') index++;
        
        for(int i = index; i < str.size(); i++) {
            if (str[i] > 57 || str[i] < 48) break;
            int currNum = str[i] - 48;
            if (result > (INT_MAX/10) || result*10 > INT_MAX - currNum) return isNeg ? INT_MIN : INT_MAX;
            result = result*10 + currNum;
        }
        return isNeg ? result*(-1) : result;
}
