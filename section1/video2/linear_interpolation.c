#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#define BASE_RES 10


typedef struct result
{
    float *xs;
    float *ys;
} result;

float interp(float y0, float y1, float x0, float x1, float x)
{
    return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}

result interpolate(float *xs, float *ys, int n)
{
    float delta;
    result res;
    res.xs = malloc(10*(n-1)*sizeof(float));
    res.ys = malloc(10*(n-1)*sizeof(float));
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<10;j++)
        {
            delta = xs[i+1]-xs[i];
            res.xs[10*i+j] = xs[i]+0.1*((float) j)*delta;
            res.ys[10*i+j] = interp(ys[i], ys[i+1], xs[i], xs[i+1], res.xs[10*i+j]);
        }
    }
    return res;
}

int main()
{
    float xs[BASE_RES];
    float ys[BASE_RES];
    for(int i=0;i<BASE_RES;i++)
    {
        xs[i] = 4.*M_PI*((float) i)/BASE_RES;
        ys[i] = sin(xs[i]);
    }
    result res = interpolate(xs, ys, BASE_RES);
    for(int i=0;i<10*(BASE_RES-1);i++)
    {
        printf("%e %e\n", res.xs[i], res.ys[i]);
    }
    return 0;
}
