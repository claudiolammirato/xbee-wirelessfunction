#include <iostream>
#include <string>

#include "wirelessXbee.h"


float temp_ext;
float hum_ext;
float temp_int;
std::string addresslow = "407C6019";



int main() {
    temp_ext = 25.6;
    hum_ext = 50;
    temp_int = 22;
    //Prepare the String to convert
    std::string msg_string="Claudio_" + std::to_string(temp_ext);
    std::string msg_hex;
    std::string msg_out;

    //Convert to HEX
    stream2hex(msg_string, msg_hex, true);
    std::cout << "hex format: " << msg_hex << '\n';
    /*
    //Convert to String
    hex2stream(msg_hex, msg_string);
    std::cout << "original one: " << msg_string << '\n';
    */

    writeXbee(msg_hex,msg_out, addresslow);
    std::cout << "XBEE: " << msg_out << '\n';


    return 0;
}




