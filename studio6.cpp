#include <iostream>

float pulse_pressure(float sp, float dp){
    return sp-dp;
}

void check_pulse_pressure(float pp){
    if (pp>80){
        std:: cout <<"You have a high pulse pressure. It is: " << pp <<std::endl;
    }
    else{
        std:: cout << "Your pulse pressure is normal. It is: " << pp <<std::endl;
    }
}

float mean_artial_pressure(float dp, float pp){
    return dp + (pp/3);
}

void check_mean_artial_pressure(float map){
    if (map<60){
        std:: cout << "You have a low mean arterial pressure. You may consider seeking medical assitance. It is: " << map <<std::endl;       
    }
    else{
        std:: cout << "Your mean arterial pressure is within acceptable limits.It is: " << map <<std::endl;
    }
}

int main(){    
    float sp;
    float dp;
    std:: cout<< "Please enter your systolic pressure: ";
    std:: cin>> sp;
    std:: cout<< "Please enter your diastolic pressure: ";
    std:: cin>> dp;
    float pp = pulse_pressure(sp,dp);
    check_pulse_pressure(pp);
    float map = mean_artial_pressure(dp,pp);
    check_mean_artial_pressure(map);
    return 0;
}