#include <bits/stdc++.h>
#define N 1001

using namespace std;

int calcarea(bool mato[N][N],int n)
{
    int bmat1[n+1][n+1];

    for(int i=0;i<n;i++)
    {
        bmat1[0][i]=mato[0][i];

        for(int j=1;j<n;j++)
        {
            bmat1[j][i]=(mato[j][i]==0)?0:bmat1[j-1][i]+1;
        }
    }

    for(int i=0;i<n;i++)
    {
        int con[n+1]={0};

        for(int j=0;j<n;j++)
        {
            con[bmat1[i][j]]++;
        }

        int coln=0;

        for(int j=n;j>=0;j--)
        {
            if(con[j]>0)
            {
                for(int k=0;k<con[j];k++)
                {
                    bmat1[i][coln]=j;

                    coln++;
                }
            }
        }
    }

    int carea,finarea=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            carea=(j+1)*bmat1[i][j];

            if(carea>finarea)
            {
                finarea=carea;
            }
        }
    }

    return finarea;

}

int main()
{
    bool areamat[N][N];

    int x,y,z;

    cin>>z;

    for(x=0;x<z;x++)
    {
        for(y=0;y<z;y++)
        {
            cin>>areamat[x][y];
        }
    }

    cout <<calcarea(areamat,z);

    return 0;
}
