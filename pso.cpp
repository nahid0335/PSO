#include<bits/stdc++.h>
using namespace std;


float func(float x)
{
    return 1+2*x-x*x;
}


int main()
{
    int n,m;
    float c1,c2,w;
    cout<<"Enter iteration :";
    cin>>n;
    cout<<"Enter particle size :";
    cin>>m;
    float v[m+1],x[m+1];
    float r1[m+1],r2[m+1];
    cout<<"Enter c1 :";
    cin>>c1;
    cout<<"Enter c2 :";
    cin>>c2;
    cout<<"Enter w :";
    cin>>w;
    cout<<"Enter v0 :";
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    cout<<"Enter x0 :";
    for(int i=0;i<m;i++)
    {
        cin>>x[i];
    }
    cout<<"Enter r1 :";
    for(int i=0;i<m;i++)
    {
        cin>>r1[i];
    }
    cout<<"Enter r2 :";
    for(int i=0;i<m;i++)
    {
        cin>>r2[i];
    }
    float p[m+1];
    float pg=-100000.0,xg=0;
    for(int i=0;i<m;i++)
    {
        p[i]=func(x[i]);
        if(pg<p[i])
        {
            pg = p[i];
            xg = x[i];
        }

    }
    cout<<endl;
    cout<<endl;
    cout<<"P0 : ";
    for(int i=0;i<m;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<" Pg : "<<pg<<" (x = "<<xg<<" )"<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j =0 ;j<m;j++)
        {
            float vt = w*v[j]+c1*r1[j]*(p[j]-x[j])+c2*r2[j]*(pg-x[j]);
            v[j]=vt;
        }
        for(int j =0 ;j<m;j++)
        {
            float xt = x[j]+v[j];
            x[j]=xt;
        }
        for(int j =0 ;j<m;j++)
        {
            float pt = func(x[j]);
            if(pt>p[j])
            {
                p[j]=pt;
            }
            if(pt>pg)
            {
                pg=pt;
                xg = x[j];
            }
        }
        cout<<endl;
        cout<<"V"<<i+1<<" : ";
        for(int j =0 ;j<m;j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
        cout<<"X"<<i+1<<" : ";
        for(int j =0 ;j<m;j++)
        {
            cout<<x[j]<<" ";
        }
        cout<<endl;
        cout<<"P"<<i+1<<" : ";
        for(int j =0 ;j<m;j++)
        {
            cout<<p[j]<<" ";
        }
        cout<<endl;
        cout<<" Pg : "<<pg<<" (x = "<<xg<<" )"<<endl;
    }

}
