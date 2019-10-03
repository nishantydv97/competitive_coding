
/*
Gven an array A, having N integers A1 A2 . . . . An. Two elements of the array Ai and Aj are called similer if Ai = Aj or Aj = Ai + 1.
Also, the similarity follows transitivit. if Ai and Aj are similer and Aj and Ak are similer , then Ai and Ak are also similer 

Note : i,j and k are all distinct.

input:

The first line contain a single integer N denoting number of elements in the array.

The second line contains N space separated integers where ith elements indicate Ai.

output:

Output the number of pairs of indices (i,j) such that i < j and Ai is similer to  Aj in a single  line.

Constrint:

i<=N<=10^6
10^-9 <= Ai <= 10^9

Sample Input 

8

1 3 5 7 8 2 5 7

Sample Output 

6

*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long int




long long SimilarElementsPairs (vector<int> A,int N) {
   // Write your code here
   ll sum=0;
   sort(A.begin(),A.end());
   /*
   for(auto  i :  A){
       cout<<i<<" ";
   }

   cout<<endl;
   */
   for(ll i=1;i<N;i++){
       ll cnt=0;
       ll same=0;
       for(ll j=i;j<N;j++){
           if(abs(A[j]-A[j-1])==1){
               cnt++;
               i++;
           }else if(abs(A[j]-A[j-1])==0){
               same++;
               i++;
           }else{
               break;
           }
       }
       if(same>0 && cnt>0){
           //sum+=pow(2,(same+cnt));
           ll s=same+cnt;
           sum+=((s*(s+1))/2);
       }else{
           if(cnt!=0){
               //sum+=pow(2,(cnt));
               ll s=cnt;
               sum+=((s*(s+1))/2);
           }

       }
       //cout<<sum<<" "<<i<<endl;
   }
   return sum;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    long long out_;
    out_ = SimilarElementsPairs(A,N);
    cout << out_;
}
