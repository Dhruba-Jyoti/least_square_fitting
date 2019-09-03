#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
//#include "param.h"
#include "plotter_comp.h"
#include "dhruba_color.h"
#define clear() printf("\033[H\033[J")


int fitting();
int error();
double plot_header(int, int, int);
using namespace std;

int main()
{ 

	clear();
       cout<<"    |-----------------------------------------------------|"<<endl;
       cout<<"    |                                                     |"<<endl;
       cout<<"    |"<<BOLD(FBLU("     A PROGRAM TO IMPLEMENT SQUARE FITTING METHOD    "))<<"|"<<endl;
       cout<<"    |"<<BOLD(FBLU("                 AND ERROR ESTIMATION                "))<<"|"<<endl;
       cout<<"    |                                                     |"<<endl;
       cout<<"    |                              VERSION 1.00           |"<<endl;
       cout<<"    |                              DATE: 01/02/2019       |"<<endl;
       cout<<"    |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
       cout<<"    |                      WRITTEN BY "FRED("D. J. GOGOI")"         |"<<endl;
       cout<<"    |                              Department of Physics  |"<<endl;
       cout<<"    |                              D. University          |"<<endl;
       cout<<"    |                       Email: moloydhruba@gmail.com  |"<<endl;
       cout<<"    |                       Mob. : 0000000000000          |"<<endl;
       cout<<"    |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
       cout<<""<<endl;

	cout<<"                  >>>>>>"FBLU("TO CONTINUE PRESS ENTER")"<<<<<<"<<endl;
	getchar();
	clear();
	int i,j=0, plot=0;
	int choice = 1;

 menu:
	cout<<"     _____________________________________________________"<<endl;
       cout<<"    |                                                     |"<<endl;
       cout<<"    |    OPTIONS AVAILABLE:                               |"<<endl;
       cout<<"    |                                                     |"<<endl;
       cout<<"    |      1. "UNDL(FGRN("SQUARE FITTING"))"     **PRESS 1 TO SELECT**    |"<<endl;
       cout<<"    |      2. "UNDL(FRED("STATISTICAL ERROR"))"  **PRESS 2 TO SELECT**    |"<<endl;
       cout<<"    |      3. "UNDL(FCYN("BOTH"))"               **PRESS 3 TO SELECT**    |"<<endl;
       cout<<"    |      4. "UNDL(FMAG("HELP"))"               **PRESS 4 TO SELECT**    |"<<endl;
       cout<<"    |=====================================================|"<<endl;
	cin>>choice;

	if(choice==4) 
	{
	clear();
	cout<<""<<endl;
	cout << BOLD(FMAG("            ~~~~~~~~~~~~~~~~~~~HELP PAGE~~~~~~~~~~~~~~~~~~~~")) << endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"   This program allows users to calculate statistical error and implement"<<endl;
	cout<<" Least Square Fitting algorithm to data points provided. The input values"<<endl;
	cout<<" for error calculation should be written in file  "FGRN("input_values_for_error")"."<<endl;
	cout<<" The input values for Least Square Fitting should be written in the file -"<<endl;
	cout<<" "FGRN("input_values_for_fitting")". The output data will be available on the screen."<<endl;
	cout<<" However, fitted data are also available in file "FMAG("least_square_fitted_data")"."<<endl;
	cout<<""<<endl;
	cout<<"   To compile, type make and press enter."<<endl;
	cout<<""<<endl;
	cout<<"   To run, type ./run and press enter."<<endl;
	cout<<""<<endl;
	cout<<"   To to change the axes titles in the graph edit "FRED("plotter_comp.h")"."<<endl;
	cout<<""<<endl;
	cout<<"                  >>>>>>"FBLU("TO CONTINUE PRESS ENTER")"<<<<<<"<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"                                                      (c)"FYEL("D J Gogoi")""<<endl;
	
	getchar();
	getchar();
	clear();
	goto menu;
	}

	if(choice !=1 && choice !=2 && choice !=3 && choice !=4)
		{
			cout<<endl;
			cout<<"    Invalid input ......!!!"<<endl;
			cout<<"    Default option selected."<<endl;
			choice=3;
		}


clear();
	cout<<""<<endl;
	cout<<"   Press 1 if you want to generate graph"<<endl;
	cin>>plot;
	int plot_prog=2, logscale_x =0, logscale_y=0;

	if(plot==1)
	{
	 cout<<"   PLOTTING PROGRAM==> GNUPLOT"<<endl;
	 cout<<""<<endl;
	}

clear();
	if(plot==1&& plot_prog==2)
	{
	cout<<""<<endl;
	cout<<"   For logscale (x,y) press 1  1 else 0  0"<<endl;

	cin>> logscale_x;
	cin>> logscale_y;
	}
	if((logscale_x*logscale_y)!=1 && (logscale_x*logscale_y)!=0)
		{
			cout<<"    Invalid input...!!!"<<endl;
			cout<<"    Default scale set."<<endl;
			logscale_x = 0;
			logscale_y = 0;
		}

clear();
cout<<""<<endl;



if(choice ==3)
{
fitting();
if(plot==1)
{
plot_header(plot, logscale_x,logscale_y);
}
error();
}

if(choice==1){fitting();
if(plot==1)
{
plot_header(plot, logscale_x,logscale_y);
}
}
if(choice==2){error();}

cout<<""<<endl;
cout<<"    PROGRAM SUCCESSFULLY EXECUTED."<<endl;
cout<<"              GOOD BYE"<<endl;

return 0;
}



