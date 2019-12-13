#include <bits/stdc++.h>
#define N 1001

using namespace std;

int main()
{
    bool A[N][N];

    int B[N][N];

    int carea,finarea=0;

    int x,y,n;

    cin>>n;

    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            cin>>A[x][y];
        }
    }

    for(int i=0;i<n;i++)
    {
        B[0][i]=A[0][i];

        for(int j=1;j<n;j++)
        {
            B[j][i]=(A[j][i]==0)?0:B[j-1][i]+1;
        }
    }

    for(int i=0;i<n;i++)
    {
        int A[n+1]={0};

        for(int j=0;j<n;j++)
        {
            A[B[i][j]]++;
        }

        int coln=0;

        for(int j=n;j>=0;j--)
        {
            if(A[j]>0)
            {
                for(int k=0;k<A[j];k++)
                {
                    B[i][coln]=j;

                    coln++;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            carea=(j+1)*B[i][j];

            if(carea>finarea)
            {
                finarea=carea;
            }
        }
    }

    cout<<finarea;

    return 0;
}
