#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double fact[33];

double doublepower(double base, int x) {
	double ret = 1.0;
	for(int i=1; i<=x; i++)
	{
        ret *= base;
    }
	return ret;
}

double _function(double x) {
	double ret = 0.0;
	double ca0 = 42.0, cb0 = 28.0, cc0 = 4.0;
	double k = 0.016;
	ret = cc0 + x;
	ret /= ((ca0-2.0*x)*(ca0-2.0*x)*(cb0 - x));
	return ret-k;
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
int main() {
	freopen("out21.csv", "w", stdout);
	for(int x = 0; x<=20; x++) {
		cout<<x<<", "<<_function(x)<<endl;
	}
	return 0;
}
