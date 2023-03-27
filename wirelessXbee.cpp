#include "wirelessXbee.h"

void writeXbee(std::string str, std::string& msg_out, std::string addresslow){
    //std::cout << str<<'\n';
    //std::cout << str.length()<< '\n';
    //hexstr = str + "_OUT";

    std::string checksum;
    int l;

    //0 byte
    msg_out = msg_out + '7'; // Start Delimeter
    msg_out = msg_out + 'E'; // Start Delimeter
    //1 byte
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    //2 byte placeholder - at the end will be calculated the lenght in hex
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    //3 byte
    msg_out = msg_out + '1'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    //4 byte
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '1'; // Start Delimeter
    //5 byte
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    //6 byte
    msg_out = msg_out + '1'; // Start Delimeter
    msg_out = msg_out + '3'; // Start Delimeter
    //7 byte
    msg_out = msg_out + 'A'; // Start Delimeter
    msg_out = msg_out + '2'; // Start Delimeter
    //8 byte
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    
    //from 9 to 12 byte
    for(int i = 0; i<addresslow.length(); i++){
        msg_out = msg_out + addresslow[i];
    }

    //13 byte
    msg_out = msg_out + 'F'; // Start Delimeter
    msg_out = msg_out + 'F'; // Start Delimeter
    //14 byte
    msg_out = msg_out + 'F'; // Start Delimeter
    msg_out = msg_out + 'E'; // Start Delimeter
    //15 byte
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    //16 byte
    msg_out = msg_out + '0'; // Start Delimeter
    msg_out = msg_out + '0'; // Start Delimeter
    
   //message byte
    msg_out = msg_out + str; // Start Delimeter
    
    //Checksum Calculation
    for(int i = 6; i<34 + str.length() ; i+=2 ){
        checksum = hexadd(checksum,msg_out.substr(i, 2));//checksum        
    }
    checksum = checksum.substr(1,2); 
    checksum = hexmin("FF" , checksum);

    msg_out = msg_out + checksum;
    
    //Length calculation
    l = (msg_out.length()-8)/2;
    //std::cout << typeid(l).name()<<'\n';
    std::stringstream stream;
    stream << std::uppercase << std::hex << l;
    std::string result( stream.str() );
    //std::cout << result <<'\n';

    msg_out[4] = result[0];
    msg_out[5] = result[1];

    
    
    /*
    hexstr[16+_j+1] = 0xFF - (_msg[16+_j+1]&0xFF);
    */
    /*
    //Set transmission length
    _msg[2] = 16+_j+1-3;
    for(int i=0; i<_msg[2]+4; i++){
        message[i] += _msg[i];
    }
    *n_message = _msg[2]+4;
    for(int i=0;i<_msg[2]+4;i++){
        //Serial.print(_msg[i],HEX);
    }
    */
}


// Convert string of chars to its representative string of hex numbers
void stream2hex(const std::string str, std::string& hexstr, bool capital)
{
    hexstr.resize(str.size() * 2);
    const size_t a = capital ? 'A' - 1 : 'a' - 1;

    for (size_t i = 0, c = str[0] & 0xFF; i < hexstr.size(); c = str[i / 2] & 0xFF)
    {

        hexstr[i++] = c > 0x9F ? (c / 16 - 9) | a : c / 16 | '0';
        hexstr[i++] = (c & 0xF) > 9 ? (c % 16 - 9) | a : c % 16 | '0';
    }
}


// Convert string of hex numbers to its equivalent char-stream
void hex2stream(const std::string hexstr, std::string& str)
{
    str.resize((hexstr.size() + 1) / 2);

    for (size_t i = 0, j = 0; i < str.size(); i++, j++)
    {
        str[i] = (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) << 4, j++;
        str[i] |= (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) & 0xF;
    }
}


std::string hexadd(const std::string & hex1, const std::string & hex2)
{
	long n1, n2;
	n1 = hex2dec(hex1);
	n2 = hex2dec(hex2);
	return dec2hex(n1+n2);
}

std::string hexmin(const std::string & hex1, const std::string & hex2)
{
	long n1, n2;
	n1 = hex2dec(hex1);
	n2 = hex2dec(hex2);
	return dec2hex(n1-n2);
}

std::string dec2hex(long i)
{
	std::stringstream ss;
	std::string s;
	hex(ss);
	uppercase(ss);
	ss << i;
	ss >> s;
	return s;
}

long hex2dec(const std::string & hexstr)
{
	std::stringstream ss;
	long i = 0;
	hex(ss);
	ss << hexstr;
	ss.clear();
	ss >> i;
	return i;
}
