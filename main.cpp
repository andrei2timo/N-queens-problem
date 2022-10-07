#include <iostream>
#include <windows.h>
#include <graphics.h>
using namespace std;
int d=100,n,k,st[20];
int x=250,R=47;
char *f1="img.png";
void Afisare()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            if(st[i]==j)
                cout<<"("<<i<<","<<j<<") "<<" ";
        cout<<endl;
    }
}
void Afisare_grafic()
{
    int i,j;
    int x=10,x1,x2;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            if(st[i]==j)
            {
                setcolor(10);
                x1=x+(i-1)*d;
                x2=x+(j-1)*d;
                setfillstyle(1,0);
                circle(x1+d,x2+d,R);
                setlinestyle(0,0,3);
                delay(500);
            }
        setcolor(0);
        circle(x1+d,x2+d,R);
    }

}
void desenare()
{
    cout<<"n=";
    cin>>n;
    int W,H,x=10,x1,x2;
    W=100*n+d;
    H=100*n+d;
    initwindow(W,H," * * Problema Damelor * * ");
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            setcolor(11);
            x1=x+(i-1)*d;
            x2=x+(j-1)*d;
            setlinestyle(0,0,3);
            rectangle(x1+5*x,x+5*x,x1+d+5*x,x2+d+5*x);
        }
}
int Valid()
{
    for(int i=1; i<=k-1; i++)
        if(st[k]==st[i] || abs(i-k)==abs(st[i]-st[k]))
            return 0;
    return 1;
}
void Back()
{
    k=1;
    while(k>0)
    {
        if(st[k]<n)
        {
            st[k]=st[k]+1;
            if(Valid()==1)
                if(k==n)
                {
                    Afisare();
                    Afisare_grafic();
                }
                else
                {
                    k++;
                    st[k]=0;
                }
        }
        else
            k--;
    }
}
int main()
{
    desenare();
    Back();
    cout<<endl;
    system("pause");
    return 0;
}
