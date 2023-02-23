#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float year;
    double profit;
    scanf("%f %lf",&year,&profit);
    double sum=0;
    for(int i=0;i<=year;i++){
        double x;
        cin>>x;
        x=pow(1+profit,-i)*x;
        sum=sum+x;
    }
    printf("%.3lf",sum);
}