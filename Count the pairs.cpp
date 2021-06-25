/*********

********/

class Solution{
    public:
    long long countPairs(int N, vector<long long> A, long long X)
    {
     
    
    long long a=0;
    //long long ar[];
    long long ans=0;
    for(long long i=0;i<N;i++)
    {
        //cin>>ar[i];
        A[i]&=X;
    }
   sort(A.begin(),A.end());
    long long curV=A[0];
    a=1;
    for(long long i=1;i<N;i++)
    {
        if(A[i]==curV)
        a++;
        else{
            ans+=(a)*(a-1)/2;
            a=1;
            curV=A[i];
        }

    }
    ans+=(a)*(a-1)/2;
    //cout<<ans<<endl;
    return ans;
    
    }
};
