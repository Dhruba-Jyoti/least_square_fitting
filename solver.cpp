#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include "dhruba_color.h"
#define clear() printf("\033[H\033[J")


using namespace std;


void pBar(double);
int msleep(unsigned long);


int fitting(){
int n=0;
double x_mean=0, y_mean=0, x_square_mean=0, y_square_mean=0, m=0, c=0, XX=0, XY=0;
double x_sum=0, y_sum=0, x_square_sum=0, y_square_sum=0;
double x[100], y[100], x_square[100], y_square[100], y_modified[100];
for(int i=0; i<100; ++i)
{
x[i]=0;
y[i]=0;
x_square[i]=0;
y_square[i]=0;
y_modified[i]=0;
}
int i_1=0;
int i_0=0;

std::string line0;
	ifstream datafile0("input_values_for_fitting");
	while(getline(datafile0,line0))
	{ i_0++;
	}

std::string line;
	ifstream datafile("input_values_for_fitting");
	if(!datafile.is_open())
	{
		cout<<"ERROR, file is not found"<<endl;
		getchar();
		exit(0);

	}
else 
{
	cout<<" Data file input_values_for_fitting found."<<endl;
	cout<<""<<endl;
	cout<<" Initializing data file read..."<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
}

//clear();

	cout<<""<<endl;
	cout<<"                 PLEASE WAIT A FEW SECONDS..."<<endl;
	msleep(2000);
	while(getline(datafile,line))
	{

		std::istringstream ss(line);
		ss >>x[i_1]>>y[i_1];
		x_square[i_1]=x[i_1]*x[i_1];
		y_square[i_1]=y[i_1]*y[i_1];
		x_square_sum+=x_square[i_1];
		y_square_sum+=y_square[i_1];
		x_sum+=x[i_1];
		y_sum+=y[i_1];
		i_1++;

		pBar(100.0*i_1/i_0);
		msleep(500);
	}

	datafile.close();
clear();

  	ofstream fitted;
       fitted.open ("least_square_fitted_data");
	n=i_1;
	x_mean=x_sum/n;
	y_mean=y_sum/n;
	x_square_mean=x_square_sum/n;
	y_square_mean=y_square_sum/n;
	for(int i=0; i<n; ++i)
	{
	XY+=(x_mean-x[i])*(y_mean-y[i]);
	XX+=(x_mean-x[i])*(x_mean-x[i]);
	}
	m=XY/XX;
	c=y_mean-m*x_mean;

	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"                  >>>>>>"UNDL(FBLU("RESULTS"))"<<<<<<"<<endl;

	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"       "FRED("LEAST SQUARE FITTING")"   "<<endl;
	cout<<""<<endl;
	cout<<"    Slope (m) is ==> "<<m<<endl;
	cout<<"    Intercept (c) is ==> "<<c<<endl;
	cout<<""<<endl;
	cout<<"    Modified data points are (x,y):"<<endl;
	cout<<"   ---------------------------------------"<<endl;
	cout<<"   |       X         |          Y        |"<<endl;
	cout<<"   ---------------------------------------"<<endl;
	for(int i=0; i<n; ++i)
	{
	y_modified[i]=m*x[i]+c;
	fitted<<x[i]<<"	"<<y_modified[i]<<endl;
	cout<<"   	  "<<x[i]<<"		    "<<y_modified[i]<<endl;
	}
	cout<<"   ---------------------------------------"<<endl;
	fitted.close();
  return(0);
}

int error(){
double x[100], y[100], x_sq[100];
double x_mean=0, error=0, x_sq_mean=0, x_sum=0, x_sq_sum=0;

int i_1=0, n=0;
for(int i=0; i<100; ++i)
{
x[i]=0;
y[i]=0;
x_sq[i]=0;
}


int i_01=0;

/*std::string line0;
	ifstream datafile0("input_values_for_error");
	while(getline(datafile0,line0))
	{ i_01++;
	} 
*/

std::string line;
	ifstream datafile("input_values_for_error");
	if(!datafile.is_open())
	{
		cout<<"ERROR, file is not found"<<endl;
		getchar();
		exit(0);

	}
	while(getline(datafile,line))
	{
		std::istringstream ss(line);
		ss >>x[i_1];
		x_sq_sum+=x[i_1]*x[i_1];
		x_sum+=x[i_1];
		i_1++;

		//pBar(100.0*i_1/i_01);
		//msleep(500);
	}

	datafile.close();
	n=i_1;
	x_mean=x_sum/n;
	x_sq_mean=x_sq_sum/n;

	error = pow(x_sq_mean-x_mean*x_mean, 0.5);
	cout<<""<<endl;
	cout<<"          "FRED("STATISTICAL ERROR")"            "<<endl;
	cout<<""<<endl;
	cout<<"   ---------------------------------------"<<endl;
	cout<<"   |       X       |         X^2         |"<<endl;
	cout<<"   ---------------------------------------"<<endl;
for(int i=0; i<n; i++){
	cout<<"   	"<<x[i]<<"		"<<x[i]*x[i]<<endl;}
	cout<<"   ---------------------------------------"<<endl;
	cout<<"     X_sum = "<<x_sum<<"	 X*X_sum = "<<x_sq_sum<<endl;
	cout<<"    Sigma^2 =  "<<x_sq_mean-x_mean*x_mean<<endl;

	cout<<"   Error (Sigma) is ==> "<<error<<endl;
	cout<<""<<endl;
	cout<<"   Result is ==>  "<<x_mean <<" +/- "<<error<<endl;

  return(0);
}
