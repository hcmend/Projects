#include <iostream>
float cubic_meters_per_day;
float gallons_to_barrels;
float day_to_hours;

int main(){
cubic_meters_to_gallons(8400);
}

float cubic_meters_to_gallons (float x){
    return(x*264.2);
}

float gallons_to_barrels (float x){
    return(x/42);
}

float day_to_hours (float x){
    return(x/24);    
}
