#include <iostream>
#include <vector>
#include <string>

using namespace std;

string timeConversion(string s) {
	// Complete this function
	int hh = (s[0] - '0') * 10 + s[1] - '0';
	int mm = (s[3] - '0') * 10 + s[4] - '0';
	int ss = (s[6] - '0') * 10 + s[7] - '0';
	if (hh == 12) {
		if (s[8] == 'A') hh = 0;
		else hh = 12;
	}
	else {
		if (s[8] == 'P') hh += 12;
	}
	string ret = "";
	if (hh<10) ret.append("0");
	ret.append(to_string(hh));
	ret.append(":");
	if (mm<10) ret.append("0");
	ret.append(to_string(mm));
	ret.append(":");
	if (ss<10) ret.append("0");
	ret.append(to_string(ss));
	return ret;
}

int main() {
	string s;
	cin >> s;
	string result = timeConversion(s);
	cout << result << endl;
	return 0;
}
