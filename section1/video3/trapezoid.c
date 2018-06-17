#include "math.h"
#include "stdio.h"
#include "stdlib.h"


// Take in an array of n points x, and a function evaluated on those points, y,
// and return the integral of y covering the range of x, using the trapezoid rule
float integrate(float* x, float* y, int n)
{
    float delta, y_int=0;
    for(int i=0;i<n-1;i++)
    {
        delta = x[i+1]-x[i];
        y_int += 0.5*delta*(y[i+1]+y[i]);
    }
    return y_int;
}

int main(int argc, char *argv[])
{
    //The program takes one argument, just the number of points to integrate over
    if(argc != 2) {
        printf("Please input number of data points!\n");
        return -1;
    }
    int n_points = atoi(argv[1]);
    // generate our input data (a simple sine curve)
    float xs[n_points];
    float ys[n_points];
    for(int i=0;i<=n_points;i++)
    {
        xs[i] = 2.*M_PI*((float) i)/n_points;
        ys[i] = sin(xs[i]);
    }
    // Print out the integral of sin from 0 to 2pi
    printf("%e\n", integrate(xs, ys, n_points));
    return 0;
}
