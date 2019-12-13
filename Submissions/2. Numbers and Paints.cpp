#include <bits/stdc++.h>
#define N 1000000

using namespace std;

int A[N],B[N],C[N];
int n;

int main()
{
    int k;
    
    cin>>k;

    for(int i=2;i<=N;i++)
    {
        if(A[i]==0)
        {
            for(int j=i;j<=N;j+=i)
            {
                A[j]=1;
                if(B[j]==0)
                {
                    B[j]=i;
                }
            }
        }
    }

    while(k--)
    {
        cin>>n;

        int x=0;
        
        memset(C,0,sizeof(C));

        while(n--)
        {
            int val;
            cin>>val;

            while(val>1)
            {
                C[B[val]]++;
                val/=B[val];
            }
        }

        for(int i=1;i<=N;i++)
        {
            x^=C[i];
        }
            
        if(x>0)
        {
            cout<<"Rishit"<<endl;
        }
        else
        {
            cout<<"Ruchika"<<endl;
        }    
    }
    return 0;
}
