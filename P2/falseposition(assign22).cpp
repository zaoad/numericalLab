#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxi = 311111;

double _function(double x) {
	double ret = 0.0;
	double ca0 = 42.0, cb0 = 28.0, cc0 = 4.0;
	double k = 0.016;
	ret = cc0 + x;
	ret /= ((ca0-2.0*x)*(ca0-2.0*x)*(cb0 - x));
	return ret-k;
}

double xm(double x0, double x1) {
	double num = _function(x0) * (x0 - x1);
	double den = _function(x0) - _function(x1);
	double ret = num / den;
	return ((-1.0 * ret) + x0);
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

	freopen("out22.csv", "w", stdout);

	double prevx, lo, hi, accpErr;
	double inix0, inix1;
	int cnt, caseno = 1;

	cin>>lo>>hi>>accpErr;
	cnt = 3;
    falseMethod(lo,high);
	return 0;
}
