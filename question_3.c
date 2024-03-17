#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct arrFeatures{
    double min, max, avg;
    double *evenNum;
    int newsize;

};

struct arrFeatures arrCalc(double array[], int n){

    struct arrFeatures s;

    // min, max, avg
    double sum = 0;
    double max = array[0];
    double min = array[0];
    int evens = 0; // # of even numbers
    int i;
    for(i = 0; i < n; i++){
        sum = sum + array[i];
        if(max < array[i]){
            max = array[i];
        }
        if(min > array[i]){
            min = array[i];
        }
        if(remainder(array[i],2) == 0){
            evens++;
        }
    }
    s.avg = sum / n;
    s.max = max;
    s.min = min;
    s.evenNum = malloc(sizeof(double)*evens);
    s.newsize = evens;

    // populating the even array
    int j = 0;
    for(i = 0; i < n; i++){
        if(remainder(array[i],2) == 0){
            s.evenNum[j] = array[i];
            j++;
        }
    }

    return s;
};

int main()
{
    double v[] = {1, 2, 3, -4, 0, 8.5}; // example
    struct arrFeatures t = arrCalc(v, sizeof(v)/sizeof(v[0]));
    printf("%f\n",t.max);
    printf("%f\n",t.min);
    printf("%f\n",t.avg);
    printf("%d\n",t.newsize);
    int idx;
    for(idx = 0; idx < t.newsize; idx++){
        printf("%f ", t.evenNum[idx]);
    }
    return 0;
}
