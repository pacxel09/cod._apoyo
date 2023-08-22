#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
# define PI 3.141592653589793238

using namespace std;


double EPS = 1e-10 ;
const int rep = 3000000 ;
double ans ;
int y ;

double rad (double x){
    return ((x*PI)/180.0);
}
double deg (double x){
    return ((x*180)/PI);
}
double abs (double x){
    return x<0? x*(-1) : x ;
}
double sin(double x){
    double tmp = x, val;
    ans = x ;
    for (int i = 0 ; ; ++i)
    {
        val = ((-1)*x*x / ((2*i+2)*(2*i+3)));
        tmp = tmp * val ;
        if (abs(val) <= EPS) break ;
        ans+=tmp;
    }
    return ans ;
}
double cos (double x){
    ans = 1 ;
    double tmp = 1, val;
    for (int i = 1 ;  ; i+=2)
    {
        val = (-1) * x *x / (i*(i+1));
        tmp = tmp * val;
        if (abs(val)<=EPS) break ;
        ans += tmp;
    }
    return ans ;
}
double tan (double x){
    return (!(y%90 && y-x<=EPS)) ? (1.0/0): sin(x)/cos(x);
}
double sec (double x){

    return 1/cos(x);
}
double cosec (double x){

    return 1/sin(x);
}
double cot (double x){

    return cos(x)/sin(x);
}
double arctan (double x){
    double  tmp = x, val;
    ans = x ;
    for (int i = 3 ;  ; i+=2)
    {
        val = (-1) * (x * x) / i ;
        if (abs(val) <= EPS) break ;
        tmp *= (i-2) ;
        tmp *= val ;
        ans += tmp ;
    }
    return ans ;
}
double exponent (double x){
    ans = 1 ;
    double tmp = 1;
    for (int i = 1 ; i<=rep ; ++i)
    {
        tmp = (tmp*x) / i ;
        ans +=tmp;
    }
    return ans;
}
double ln (double x){
    x = x-1 ;
    ans = x ;
    double tmp = x ,val;
     for (int i = 2 ;  ; ++i)
    {
        val = (-1) * x/i ;
        if (abs(val) <= EPS) break ;
        tmp *= (i-1) ;
        tmp *= val ;
        ans += tmp ;
    }
    return ans;

}



int main()
{
i:
    ans = 0 ;
    double x = 0 ;
    int c, flag = 0 ;
    cout << "Enter the Function\n\n1-sin(x)\n2-cos(x)\n3-tan(x)\n4-sec(x)\n5-cosec(x)\n6-cot(x)\n7-arctan(x)\n8-ln(x)\n9-e^(x)\n10-Exit.\n" ;
    cin >> c ;
    if (c!=8 && c!=9 && c!=10)    {
        cout << "Radian (0) or degree (1)?\n" ;
        cin >> flag ;
    }
    if (c!=10){cout << "Enter x : " ;
    cin >> x ;
    y = x;
    }
    cout << "Enter your accuracy : " ;
    cin >> EPS ;
    if (flag) x = rad(x) ;
    cout << endl ;
    if (c == 1) cout<<fixed<<setprecision(5) << sin(x) << endl;
    else if (c == 2) cout<<fixed<<setprecision(5) <<cos(x) << endl ;
    else if (c == 3) cout<<fixed<<setprecision(5) << tan(x) << endl ;
    else if (c == 4) cout<<fixed<<setprecision(5) << sec(x) << endl ;
    else if (c == 5) cout<<fixed<<setprecision(5) << cosec(x) << endl ;
    else if (c == 6) cout<<fixed<<setprecision(5) << cot(x) << endl ;
    else if (c == 7 && x>=-1 && x<=1) cout<<"Rad : "<<fixed<<setprecision(5) << arctan(x) << endl , cout <<"Degree : "<<fixed<<setprecision(5) << deg(ans) << endl ;
    else if (c == 8 && x>0 && x<=2) cout<<fixed<<setprecision(5) << ln(x) << endl ;
    else if (c == 9) cout<<fixed<<setprecision(5) << exponent(x) << endl ;
    else if (c == 10) return 0 ;
    else cout << "X cannot be calculated by Maclaurin series expansion or there's an error in input data\n" ;

    cout << "\n\nDo you want to repeat yes (1)   NO (0)\n" ;
    cin >> flag ;
    if (flag) goto i ;


    return 0 ;
}
