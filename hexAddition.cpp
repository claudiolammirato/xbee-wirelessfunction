#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string dec2hex(long a);
long hex2dec(const string & hexstr);
string hexadd(const string & hex1, const string & hex2);

int main()
{
	string hex1, hex2;
	cout << endl << "Type two hex numbers: " << endl << endl;
	cout << "> First hex number: _______________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cin >> hex1;
	cout << "> First hex number: _______________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cin >> hex2;
	cout << endl << endl << "Sum of the two hex numbers: " << hexadd(hex1,hex2) << endl;
	return 0;
}

string hexadd(const string & hex1, const string & hex2)
{
	long n1, n2;
	n1 = hex2dec(hex1);
	n2 = hex2dec(hex2);
	return dec2hex(n1+n2);
}

string dec2hex(long i)
{
	stringstream ss;
	string s;
	hex(ss);
	uppercase(ss);
	ss << i;
	ss >> s;
	return s;
}

long hex2dec(const string & hexstr)
{
	stringstream ss;
	long i = 0;
	hex(ss);
	ss << hexstr;
	ss.clear();
	ss >> i;
	return i;
}