#include <iostream>

#include "wirelessXbee.h"


float temp_ext;
float hum_ext;
float temp_int;

int main() {
    temp_ext = 25.6;
    hum_ext = 50;
    temp_int = 22;

    writeXbee();
    std::cout<<"Hello World";
    return 0;
}
