  
double plot_header(int plot, int x, int y){

    FILE *gnuplot = popen("/usr/bin/gnuplot -persist","w");
    //fprintf(gnuplot,"set title \"Least square fitted graph \n");
    fprintf(gnuplot,"set multiplot\n");
    fprintf(gnuplot,"set origin 0.0,0.0\n");
    fprintf(gnuplot,"set size 1.0,0.5\n");
//    fprintf(gnuplot,"set size 0.50,0.5\n");
if(x==1)
    {
    fprintf(gnuplot,"set logscale x\n");
    }
if(y==1)
    {
    fprintf(gnuplot,"set logscale y\n");
    }
    fprintf(gnuplot,"set ylabel \"y\"\n");
    fprintf(gnuplot,"set key left top\n");
   // fprintf(gnuplot,"set yrange [0: 2.5]\n");
    fprintf(gnuplot,"set xlabel \"x\"\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"plot \"./least_square_fitted_data\" using 1:2 with linespoints lt 7 pt 7 title 'Fitted data',\"./input_values_for_fitting\" using 1:2 with linespoints lt 8 pt 8 title 'Raw data'\n");
    //fprintf(gnuplot,"plot \"./input_values_for_fitting\" using 1:2 with linespoints lt 8 pt 8 title 'Raw data'\n");

    fprintf(gnuplot,"set key left top\n");
    fprintf(gnuplot,"set origin 0.00,0.50\n");
    fprintf(gnuplot,"set size 1.0,0.5\n");
    fprintf(gnuplot,"set ylabel \"y\"\n");  //Give y label here
    fprintf(gnuplot,"set xlabel \"x\"\n");  //Give x label here
    fprintf(gnuplot,"plot \"./least_square_fitted_data\" using 1:2 with linespoints lt 7 pt 7 title 'Fitted data'\n");

    fprintf(gnuplot,"exit \n");
    pclose(gnuplot);
return 0;
}


