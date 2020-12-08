/*


Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. 
Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, 
but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. 
The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].


*/

class Solution {
public:
    void dfs(unordered_map<string, set<string>>& graph, unordered_map<string, bool>& visitEmail, string currEmail, 
            vector<string>& email){
        if(!visitEmail[currEmail]){
            email.push_back(currEmail);
            visitEmail[currEmail]=1;
            for(auto i : graph[currEmail]){
                dfs(graph, visitEmail, i, email);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> vec;
        unordered_map<string,set<string>> graph;
        unordered_map<string, string> emailName;
        unordered_map<string, bool> visitEmail;
        set<string> st;
        for(auto i : accounts){
            auto j=i.begin();
            string name=*j;
            j++;
            string src=*j;
            visitEmail[src]=0;
            for(;j!=i.end();j++){
                emailName[*j]=name;
                graph[src].insert(*j);
                graph[*j].insert(src);
                visitEmail[*j]=0;
            }
        }
        
        vector<string> email;
        for(auto i : graph){
            if(!visitEmail[i.first]){
                dfs(graph, visitEmail, i.first, email);
                sort(email.begin(), email.end());
                vector<string> tmp;
                tmp.push_back(emailName[i.first]);
                tmp.insert(tmp.end(), email.begin(), email.end());
                email.clear();
                vec.push_back(tmp);
                tmp.clear();
            }
        }
        return vec;
    }
};
