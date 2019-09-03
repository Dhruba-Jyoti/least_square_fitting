#include "progress.h"

void pBar(double percent_value)   //percent_value is a percentage from 0 to 100
{
    normalize(percent_value);     //normalize the percentage from 0 to 1
    int barWidth = 70;
    std::cout << "[";
    int pos = barWidth * percent_value;
    for (int idx = 0; idx < barWidth; ++idx)
    {
        if(idx <= pos)
            std::cout << "|";
        //else if(idx == pos)
        //    std::cout << ">";
        else
        	std::cout << " ";
    }
    std::cout << "] " << int(percent_value * 100.0) << " %\r";
    std::cout.flush();
}

double normalize(double &percent_value)
{
    return percent_value /= 100;
}
