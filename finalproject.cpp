#include <iostream>

float computeProfit(float days, float KWHG, float $KWH, float cost){
 return ((days*KWHG*$KWH) - cost);
}

void investmentReturnTime(float days, float KWHG, float $KWH, float cost){
    float x = computeProfit(days, KWHG, $KWH, cost);
   
    while (x < 0) {
        days++;
        x = computeProfit(days, KWHG, $KWH, cost);
    }
   
    std::cout << "The current profit is: $" << x << " after " << days << " days " << std::endl;
}

int main () {
        while(true) {           
            int input;
            std::cout << "Enter '1' to use the function. Enter '2' to end the program." << std::endl;
            std::cout << "Input 1 or 2: ";
            std::cin >> input;
           
            if(input==1){    
               
                float KWHU_per_day;
                float KWHG_per_day;
                float $_per_KWH;
                float cost;
                float days;

                std::cout << "Input # of days run: ";
                std::cin >> days;
                if(days > 0){
                    // std::cout << days << std::endl;
                } else {
                    return 0;
                }

                std::cout << "Input KiloWatt hours generated per day: ";
                std::cin >> KWHG_per_day;
                if(KWHG_per_day > 0){
                    // std::cout << KWHG_per_day << std::endl;
                } else {
                    return 0;
                }

                std::cout << "Input the cost($) per kilowatt hour: ";
                std::cin >> $_per_KWH;
                if($_per_KWH > 0){
                    // std::cout << $_per_KWH << std::endl;
                } else {
                    return 0;
                }

                std::cout << "Input the cost($) of the solar panel: ";
                std::cin >> cost;
                if(cost > 0){
                    // std::cout << cost << std::endl;
                } else {
                    return 0;
                }

                investmentReturnTime(days, KWHG_per_day, $_per_KWH, cost);

            } else {
                break;
            }
            break;
        }
    return 0;
}