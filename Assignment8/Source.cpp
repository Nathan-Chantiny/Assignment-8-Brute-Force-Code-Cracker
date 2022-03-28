#include <iostream>
#include <string>

using namespace std;

void outputS(string str, int line) {
	for (int j = 0; j < str.size(); j++) {
		char x = str[j];

		if ((x >= 0 && x < 65) || (x > 90 && x < 97) || (x > 122 && x <= 127)) {}
		else if (x >= 65 && x <= 90) {
			if ((x + line) > 90) {
				x = 65 + (((x - 65) + line) % 26);
			}
			else {
				x += line;
			}
		}
		else if (x >= 97 && x <= 122) {
			if ((x + line) > 122) {
				x = 97 + (((x - 97) + line) % 26);
			}
			else {
				x += line;
			}
		}

		str[j] = x;
	}
	cout << "#  solution : " << str << "  #\n";
}

void output(int probNum, string str, int sLine) {
	for (int z = 0; z < (str.size() + 17); z++) {
		cout << "#";
	}
	cout << "\n";

	cout << "#  cipher  " << probNum << ": " << str << "  #\n";
	if (sLine > 0) {
		outputS(str, sLine);
	}
	
	cout << "#";
	for (int z = 0; z < (str.size() + 15); z++) {
		cout << "~";
	}
	cout << "#\n";

	for (int i = 1; i <= 26; i++) {
		for (int j = 0; j < str.size(); j++) {
			char x = str[j];

			if ((x >= 0 && x < 65) || (x > 90 && x < 97) || (x > 122 && x <= 127)) {}
			else if (x >= 65 && x <= 90) {
				if ((x + 1) > 90) {
					x = 65 + (((x - 65) + 1) % 26);
				}
				else {
					x += 1;
				}
			}
			else if (x >= 97 && x <= 122) {
				if ((x + 1) > 122) {
					x = 97 + (((x - 97) + 1) % 26);
				}
				else {
					x += 1;
				}
			}

			str[j] = x;
		}
		if (i < 10) {
			cout << "#  result  " << i << ": " << str << "  #\n";
		}
		else {
			cout << "#  result " << i << ": " << str << "  #\n";
		}
	}
	
	for (int z = 0; z < (str.size() + 17); z++) {
		cout << "#";
	}
	cout << "\n\n";
}

int main() {
	string str1 = "Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs";
	output(1, str1, 23);

	string str2 = "F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd";
	output(2, str2, 21);

	string str3 = "Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo";
	output(3, str3, 16);

	string str4 = "Epht bsf opu bmmpxfe jo uif eph qbsl";
	output(4, str4, 25);

	string str5 = "Jrypbzr gb Avtug Inyr";
	output(5, str5, 13);

	
	// For ciphers more than 0 characters long and less than or equal to 1024 characters long
	string cipher = "Y";
	while (cipher == "Y" || cipher == "y") {
		cout << "\nenter a shift cipher: ";
		char c[1024];
		cin.getline(c, 1024);
		
		cipher = c;
		output(0, cipher, 0);

		cout << "would you like to go again? ";
		cin >> cipher;
		cin.ignore(1, '\n');
	}
	
}