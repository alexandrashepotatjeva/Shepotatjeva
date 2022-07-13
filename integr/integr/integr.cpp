// integr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
double rectangle_integral(double a, double b);
double trap_integral(double a, double b);
double simpson_integral(double a, double b);
double newt_integral(double a, double b);
const double eps = 1.e-6;

double func(double x)
{
    return (10. - x);    
}
 
int main()
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
    double a, b;
	cout << "Пределы интегрирования: ";
    cin >> a >> b;
    
	std::cout << "Метод прямоугольников: " << rectangle_integral(a,b) << std::endl;
	std::cout << "Метод трапеций: " << trap_integral(a,b) << std::endl;
	std::cout << "Метод Симпсона: " << simpson_integral(a,b) << std::endl;

	system("pause");
    return 0;
}

double rectangle_integral(double a, double b)
{
  double integr = eps+1., integr1 = 0.;
  for (int n=2; (n<=4)||(fabs(integr-integr1)>eps); n*=2)
  {
	  double x, h;
	  double sum = 0.0;
	  double fx;
	  h = (b - a) / n;
      for (int i=0; i<=n; i++)
      {   
		  x = a + i*h;
		  fx = func(x);
		  sum += fx;
      }
	  integr = integr1;
	  integr1 = (sum * h);
  }
  return integr1;
}

double trap_integral(double a, double b)
{
  double integr = eps+1., integr1 = 0.;
  for (int n=2; (n<=4)||(fabs(integr-integr1)>eps); n*=2)
  {
	  double x1, x2, h;
	  double sum = 0.0;
	  double fx;
	  h = (b - a) / n;
      for (int i=0; i < n; i++)
      {   
		  x1 = a + i*h;
          x2 = a + (i+1)*h;
		  fx = 0.5*(x2-x1)*(func(x1) + func(x2));;
		  sum += fx;
      }
	  integr = integr1;
	  integr1 = sum;
  }
  return integr1;
}

double simpson_integral(double a, double b)
{
	double integr=eps+1, integr1=0;
    for (int n=2; (n<=4)||(fabs(integr1-integr)>eps); n*=2)
    {
        double h, sum2=0, sum4=0, sum=0;
        h=(b-a)/(2*n);
        for (int i=1; i<=2*n-1; i+=2)
        {   
            sum4+=func(a+h*i);
            sum2+=func(a+h*(i+1));
        }
        sum=func(a)+4*sum4+2*sum2-func(b);
        integr=integr1;
        integr1=(h/3)*sum;
    }
	return integr1;
}


