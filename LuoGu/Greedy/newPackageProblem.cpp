#include <iostream>
#include <algorithm>
using namespace std;
float maxValue=0;
struct Money{
    float value=0;
    float weight=0;
    float percentage=0;
    Money(float val,float wei): value(val),weight(wei){
        percentage=val/wei;
    }
    bool operator<(const Money &object) const {
        return object.percentage<percentage;
    }
};
struct Money wealth[100];
void findMaxValue(float load,int i){
    if(wealth[i].weight<load){
        maxValue=maxValue+wealth[i].value;
        findMaxValue(load-maxValue,i+1);
    }
    else{
        maxValue=maxValue+load;
        return;
    }
}
int main(){
    float number;
    float load;
    scanf("%f %f",&number,&load);
    for(int i=0;i<number;i++){
        scanf("%f %f",&wealth[i].value,&wealth[i].weight);
        wealth[i].percentage=wealth[i].value/wealth[i].weight;
    }
    sort(wealth,wealth+99);
    findMaxValue(load,0);
    cout<<maxValue;
}
