#include<bits/stdc++.h>
using namespace std;
double funca(double x)
{
double r= -x*x + 1.8*x +2.5;
return r;
}
double func1b(double x)
{
double r= -2*x +1.8;
return r;
}
void print(double v1, double v2, double v3, double v4, double v5)
{
cout<< setw(15) << v1 << setw(15) << v2 << setw(15) << v3 << setw(15) << v4
<< setw(15) << v5 <<endl;
}
void print(string v1, string v2, string v3, string v4, string v5)
{
cout<< setw(15) << v1 << setw(15) << v2 << setw(15) << v3 << setw(15) << v4
<< setw(15) << v5 << endl;
}

double func2a(double x)
{
double r= exp(-0.5*x) * (4-x) -2;
return r;
}
double func2b(double x)
{
double r= -exp(-0.5*x) - 0.5 * exp(-0.5*x) * (4-x);
return r;
}
void Newton_Raphson(double initGuess, double input_tolerance, int cs)
{
double x0, tolerance;;
x0=initGuess;
tolerance=input_tolerance;
double x1=x0,rError=1000;
print("iteration", "xi", "f(xi)", "f'(xi)", "Relative error");
int cnt=0;
while(rError>=tolerance)
{
x0=x1;
double r0,r1;
if(cs==1)
{
r0=funca(x0);
r1=func1b(x0);
}
else
{
r0=func2a(x0);
r1=func2b(x0);
}
//printf("iteration=%d xi=%.6f f(xi)=%.6f f'(xi)=%.6f rError=%.6f\n",+
+cnt,x0,f0(x0), f1(x0),rError);
print(++cnt,x0,r0, r1,rError);
if(r1==0)
{
printf("Causing division by zero hence terminating\n");
return ;
}
x1= x0 - r0/r1;
rError=fabs((x1-x0)/x1);
}

printf("the root is=%.6f\n",x1);

}
int main()
{
cout<<"Newton-Raphson:"<<endl;
cout<<"1st equation"<<endl;
printf("Input tolerance:");
double tol;
cin>>tol;
printf("Initial root: 5 tolerance:%.6f\n\n",tol);
Newton_Raphson (5,tol,1);
cout<<endl;
cout<<"2nd equation"<<endl;
tol=0.0001;
printf("Initial root: 2 tolerance:%.6f\n\n",tol);
Newton_Raphson (2,tol,2);
cout<<endl;
printf("Initial root: 6 tolerance:%.6f\n\n",tol);
Newton_Raphson (6,tol,2);
cout<<endl;
printf("Initial root: 8 tolerance:%.6f\n\n",tol);
Newton_Raphson (8,tol,2);
cout<<endl;

}
