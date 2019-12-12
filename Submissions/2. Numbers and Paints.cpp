#include <bits/stdc++.h>

using namespace std;

const int MAX=1000004;

int A[MAX],B[MAX],C[MAX];
int n;

int main()
{
    int k;
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;i<=1000*1000;i++)
    {
    	if(A[i]==0)
        {
    		for(int j=i;j<=1000*1000;j+=i)
            {
    			A[j]=1;
    			if(B[j]==0)
                {
                    B[j]=i;
                }
    		}
    	}
    }
    
    cin>>k;

    assert(k>=1 && k<=20);

    while(k--)
    {
    	cin>>n;

        int x=0;

    	assert(n>=1 && n<=10000);
    	memset(C,0,sizeof(C));

    	while(n--)
        {
    		int val;
    		cin>>val;

    		assert(val>=1 && val<=1000*1000);
    		while(val>1)
            {
    			C[B[val]]++;
    			val/=B[val];
    		}
    	}

    	for(int i=1;i<=1000*1000;i++)
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
