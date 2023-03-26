#include <iostream>
#include <string>

#include "wirelessXbee.h"

float temp_ext;
float hum_ext;
float temp_int;


int main() {
    temp_ext = 25.6;
    hum_ext = 50;
    temp_int = 22;

    std::string msg="Claudio";
    stream2hex(msg, msg, false);
    std::cout << "hex format: " << msg << '\n';
    hex2stream(msg, msg);
    std::cout << "original one: " << msg << '\n';

    //writeXbee(msg);
    return 0;
}




