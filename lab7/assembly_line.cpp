#include <iostream>
using namespace std;

void Assembly_line(int *a1, int *a2, int *t1, int *t2, int n, int e1, int e2, int x1, int x2)
{
    int f1[n], f2[n], l1[n+1], l2[n+1], f_last, last;
    int final[n];
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];
    l1[0] = 1;
    l2[0] = 2;
    for (int j = 1; j < n; j++)
    {
        if (f1[j - 1] + a1[j] < f2[j - 1] + t2[j - 1] + a1[j])
        {
            f1[j] = f1[j - 1] + a1[j];
        }
        else
        {
            f1[j] = f2[j - 1] + t2[j - 1] + a1[j];
        }
        if (f2[j - 1] + a2[j] < f1[j - 1] + t1[j - 1] + a2[j])
        {
            f2[j] = f2[j - 1] + a2[j];
        }
        else
        {
            f2[j] = f1[j - 1] + t1[j - 1] + a2[j];
        }

        if (f1[n-1] + x1 < f2[n-1] + x2)
        {
            f_last= f1[n-1] + x1;
        }
        else
        {
            f_last= f2[n-1] + x2;
        }
    }
        cout<<"total_cost = "<<f_last;
}
int main()
{
    int a1[]={4,2,6};
    int a2[]={3,7,3};
    int t1[] = {2,2};
    int t2[] = {1,2};
    int e1 = 2;
    int e2 = 1;
    int x1 = 3;
    int x2 = 1;
    int n = sizeof(a1) / sizeof(a1[0]);
    cout<<"a1 : ";
    for(int i=0;i<n;i++)
    {
        cout<<a1[i]<<"\t";
    }
    cout<<endl;
    cout<<"a2 : ";
     for(int i=0;i<n;i++)
    {
        cout<<a2[i]<<"\t";
    }
    cout<<endl;
     cout<<"t1 : ";
     for(int i=0;i<n;i++)
    {
        cout<<t1[i]<<"\t";
    }
    cout<<endl;
     cout<<"t2 : ";
     for(int i=0;i<n;i++)
    {
        cout<<t2[i]<<"\t";
    }
    cout<<endl;
    cout<<"e1 = "<<e1<<endl;
    cout<<"e2 = "<<e2<<endl;
    cout<<"x1 = "<<x1<<endl;
    cout<<"x2 = "<<x2<<endl;
    Assembly_line(a1,a2,t1,t2,n,e1,e2,x1,x2);
    return 0;
}