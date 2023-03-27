#ifndef wirelessXbee_h
#define wirelessXbee_h

#include <iostream>
#include <string>


void writeXbee(char msg[]);
void stream2hex(std::string str, std::string& hexstr, bool capital = false);
void hex2stream(std::string hexstr, std::string& str);



#endif