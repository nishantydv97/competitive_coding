/*
Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.



*/

vector<int> Solution::sieve(int A) {
    vector <int> ans(A+1,0);
    
    for(int i=2;i<sqrt(A+1);i++){
        int fac=2;
        while(i*fac<A+1){
            ans[fac*i]=1;
            fac++;
        }
    }
    
    vector <int> res;
    for (int i=2;i<ans.size();i++){
        if(ans[i]==0){
            res.push_back(i);
        }
    }
    return res;
}
