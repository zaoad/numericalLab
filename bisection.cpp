#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=1;i<=n;i++)
double fact[33];
void facto() {
	fact[0] = 1.0;
	loop(i,32) {
		fact[i] = fact[i-1] * (i*1.0);
	}
}
double doublepower(double base, int x) {
	double ret = 1.0;
	loop(i,x) ret *= base;
	return ret;
}
void setup()
{
    for(int i=0;i<33;i++)
    {
        fact[0]=0;
    }
}
double func(int n, double x) {
	double temp1= 0.0,
    sum = 0.0,
    temp = doublepower(x/2.0, n);
	loop(k,10) {
		temp1= doublepower(-1.0, k);
		temp1*= doublepower((x*x)/4.0, k);
		temp1/= (fact[k] * fact[n + k]);
		sum += temp1;
	}
	return temp*sum;
}
void bisection(int n,double a,double b)
{
    if(func(n,a)*func(n,b)>=0)
    {
        cout<<"you have to assumed right a and b"<<endl;
    }
    double c;
    int it=1;
    while((b-a)>=0.0001)
    {
        c=(a+b)/2;
        if(func(n,c)==0.0)
            break;
        else if(func(n,c)*func(n,a)<0)
            b=c;
        else
            a=c;
        cout<<"iteration "<<it<<" a "<<a<<" b "<<b<<endl;
        it++;
    }
    cout<<"the value of root is : "<<c<<endl;
}
void bisect(double lo ,double hi)
{   double px,acceptederror;
    int cnt, iteration = 0;
    while(true) {
		double mid = (hi + lo) / 2.0;
		double relativeerror = 0.0;

		if(iteration>1) {
			relativeerror = fabs(mid - px) / mid;
			if(relativeerror <= acceptederror) break;
		}
		cout<<fixed<<setprecision(6)<<iteration<<", "<<hi<<", "<<lo<<", "<<mid<<", "<<func(0,mid)<<", "<<relativeerror<<endl;
		if(func(0,mid) > 0.0) lo = mid;
		else hi = mid;
		px = mid;
		iteration++;
	}
}
int main() {
	facto();
	double px, lo, hi, acceptederror;
	int cnt, iteration = 0;

	cin>>lo>>hi>>acceptederror;

    freopen("bisection.csv", "w", stdout);
    bisect(lo,hi);
	return 0;
}
