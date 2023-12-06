#include <iostream>


    float cubic_meters_to_gallons (float a){
        return(a*264.2);
    }

    float gallons_to_barrels (float b){
        return(b/42);
    }   

    float day_to_hours (float c){
        return(c/24);        
    }

    int main(){
        float cubic_meters_per_day = 0;
        std::cout << "Please enter your cubic meters per day as a float: ";
        std::cin >> cubic_meters_per_day;
        float x = cubic_meters_to_gallons(cubic_meters_per_day);
        float y = gallons_to_barrels(x);
        float z = day_to_hours(y);
        std::cout << z << std::endl;
        return 0;
    }

