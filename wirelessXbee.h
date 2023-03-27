#ifndef wirelessXbee_h
#define wirelessXbee_h

#include <iostream>
#include <string>


void writeXbee(std::string str, std::string& , std::string addresslow);
void stream2hex(std::string str, std::string& hexstr, bool capital = false);
void hex2stream(std::string hexstr, std::string& str);



#endif