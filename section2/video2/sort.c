#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

void insertion(float *x, int n)
{
    int i,j;
    float swp;
    for(i=1;i<n;i++)
    {
        j=i;
        // Swap all elements up to i until they are sorted.
        while(j>0 && x[j-1] > x[j])
        {
            swp = x[j];
            x[j] = x[j-1];
            x[j-1] = swp;
            j--;
        }
    }
}

void quicksort(float *x, int n)
{
    if(n > 1) {
        float swp, pivot=x[0];
        int l = 1; // left index
        int r = n-1; // right index
        while(l < r) // work l and r towards each other
        {
            if(x[l] <= pivot) l++;
            else if(x[r] >= pivot) r--;
            else // if the left element is above pivot and the right is below, swap them
            {
                swp = x[l];
                x[l] = x[r];
                x[r] = swp;
            }
        }
        l -= 1;
        swp = x[0];
        x[0] = x[l];
        x[l] = swp;
        quicksort(x, l); // recurse on the elements to the left of l
        quicksort(x+r, n-r); // recurse on the elements to the right of r
    }
}

int main()
{
    int i;
    float *sort = malloc(N*sizeof(float));
    float *unsort = malloc(N*sizeof(float));

    srand(time(NULL));
    for(i=0;i<N;i++)
    {
        sort[i] = (float) rand()/RAND_MAX;
        unsort[i] = sort[i];
    }

    insertion(sort, N);
    for(i=0; i<N; i++)
    {
        printf("%5e %5e\n", unsort[i], sort[i]);
    }
}
