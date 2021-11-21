# include <stdio.h>

double abstand(double a1, double a2){
    if(a1 > a2){
        return (a1 - a2);
    }else {return (a2 - a1);
    };
}

double wurzel(double x){
    double w1, w2;
    w2 = (1+x)/2;
    do{
        w1 = w2;    
        w2 = (w1 + x/w1)/2;
        
    }while(abstand(w1, w2) > (1e-7));

    return w2;
}

int main(void){
    double a, erg;
    char ausgabe[80];
    printf("gebe eine zahl ein, durch die du Teilen willst:\n");
    scanf("%lf",&a);
    erg = wurzel(a);
    sprintf(ausgabe, "Wurzel von %4.0f = %10.4f",a, erg);
    puts(ausgabe);
    return 0;
}
