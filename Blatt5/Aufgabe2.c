#include <stdio.h>
#include <math.h>
double f1(double x){
    return ((x*x) - 9);
}
double g1(double x){
    return (4*x-5)*x;
}


double regular(double x1, double x2, double (*f)(double)){
    double xs = 0;

    if(x1 == x2){
        return 42069;
    }
    if(f(x1) * f(x2) > 0 ){
        return 69420;
    }

    xs = x1 - (f(x1)*(x2-x1)/(f(x2)-f(x1)));
    if(fabs(f(xs)) < 1E-6){
       return xs; 
    }
    else{
       if((f(xs) * f(x1)) > 0){
            return regular(xs, x2, f); 
       }else{
            return regular(x1, xs, f);
       }
    }

}

int main(void){
    
    double ns = regular(-4, 1, &f1);
    printf("resault: %f \n ", ns);

    return 0;
}
