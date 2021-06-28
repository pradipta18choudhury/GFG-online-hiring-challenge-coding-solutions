#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int l,r;
//         cin>>l>>r;
//         int cnt=0;
//         for(int i=l;i<=r;i++)
//         {
//             int c=0;
//             int rev=0;
//             int temp=i;
            
//             for(int j=1;j<=temp;j++)
//             {
//                 if(temp%j==0)
//                 c++;
//             }
//             if(c==2)
//             {
//                 while(temp>0)
// 			    {
// 				    rev=rev*10+(temp%10);
// 				    temp/=10;
// 			    }
// 			    if(rev==i)
// 			    cnt++;
//             }
//         }
//         cout<<cnt<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int oneDigit(int num)
{
    return (num >= 0 && num < 10);
}


bool isPalUtil(int num, int* dupNum)
{

    if (oneDigit(num))

        return (num == (*dupNum) % 10);

    if (!isPalUtil(num/10, dupNum))

        return false;
 

    *dupNum /= 10;

    return (num % 10 == (*dupNum) % 10);
}
 


int isPal(int num)
{
    if (num < 0)

       num = -num;

    int *dupNum = new int(num);
    return isPalUtil(num, dupNum);
}
 

void printPalPrimesLessThanN(int l,int r)
{

    bool prime[r+1];

    memset(prime, true, sizeof(prime));
 

    for (int p=2; p*p<=r; p++)

    {

        if (prime[p] == true)

        {

            for (int i=p*2; i<=r; i += p)

                prime[i] = false;

        }

    }
    int count=0;
    for (int p=l; p<=r; p++)
 

       if (prime[p] && isPal(p))
       count++;
        
    cout<<count<<endl;
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        printPalPrimesLessThanN(l,r);
        cout<<endl;
    }
    return 0;
}
