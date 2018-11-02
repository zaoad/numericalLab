#include<bits/stdc++.h>
using namespace std;
#define epsilon 0.01
double func(double x)
{
    return (x-4)*(x-4)*(x+2);
}
double gfunc(double x)
{
    return x;

}
void bisection(double a,double b)
{
    if(func(a)*func(b)>=0)
    {
        cout<<"you have to assumed right a and b"<<endl;
    }
    double c;
    int it=1;
    while((b-a)>=epsilon)
    {
        c=(a+b)/2;
        if(func(c)==0.0)
            break;
        else if(func(c)*func(a)<0)
            b=c;
        else
            a=c;
        cout<<"iteration "<<it<<" a "<<a<<" b "<<b<<endl;
        it++;
    }
    cout<<"the value of root is : "<<c<<endl;
}
void falseMethod(double xl,double xu)
{
    int it=1,e=1000;
    double xm,fu,fl,fm;
    do
    {
        fu=func(xu);
        fl=func(xl);
        if(fu*fl>0)
        {
            cout<<"x1 and x2 doesn't bracket the root"<<endl;
            return;

        }
        else
        {
            xm=xu-fu*(xu-xl)/(fu-fl);
            fm=func(xm);
            cout<<"xl "<<xl<<" xu "<<xu<<" f(xl) "<<fl<<" f(xu) "<<fu<<" xm "<<xm<<" f(xm) "<<fm<<endl;
            e=fabs((xu-xl)/xu);
            if(fl*fm<0)
                xu=xm;
            else
                xl=xm;
                   }
        it++;
    }
    while(e>=0.0001&&fl!=0&&it!=100);
    cout<<"the root of the equation is : "<<xm<<endl;

}
void newtonrapshon(double x)
{
    double fi,gi,xm,fm,e;
    int it=1;
    do
    {
        fi=func(x);
        gi=gfunc(x);
        xm=x-fi/gi;
        fm=func(xm);
        e=fabs((xm-x)/x);
        cout<<"iteration "<<it<<" x "<<x<<" f(x) "<<fi<<" f'(x) "<<gi<<" xm "<<xm<<" f(xm) "<<fm<<" error "<<e<<endl;
        x=xm;
        it++;
    }while(e>=0.0001&&fm!=0);
    cout<<"the root of the equation is : "<<x<<endl;

}
void sacant(double x)
{
    double x1,xm,fx,e,fx1,fm;
    int it=1;
    do{
        fx=func(x);
        fx1=func(x1);
        xm=x-(fx*(x-x1)/(fx-fx1));
        fm=func(xm);
        e=fabs(x1-x)/xm;
        cout<<" iteration "<<it<<" x0 "<<x<<" x-1 "<<x1<<" f(x0) "<<fx<<" f(x-1) "<<fx1<<" error "<<e<<endl;
        x=xm;
        it++;
    }while(e>=0.0001&&fm!=0);
    cout<<"the root of the equation is : "<<x<<endl;
}
int main()
{
    double xl,xu;
    cin>>xl>>xu;
    falseMethod(xl,xu);



}
