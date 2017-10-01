#include <iostream>
#include <fstream>
#include <cstdio>
#include "Windows.h"
#include <string>
#include <Lmcons.h>
#include "Header.h"
#include <ctime>

using namespace std;

string in, in2;
bool open_var = false;
bool passcheck = true;
char Calc[MAX_PATH] = "calc.exe";
char Explorer[MAX_PATH] = "iexplore.exe";
char Chrome[MAX_PATH] = "chrome.exe";
string admstring;

void AIIR();
void open();
void pass_check();
void Exit();
void calc();

int main() {

	if (passcheck = true) {
		pass_check();
	}

		cout << "HELLO, I AM AWORKS VIRTUAL INTELLIGENT, HOW CAN I HELP YOU?\n";
		while (1) {
			while (1) {
				test_var_1 = 0;
				getline(cin, in);
				ofstream activity_log("activity log.txt", ios::app);
				activity_log << in << "\n";
				activity_log.close();
				if (in == "OPEN" || in == "RUN" || in == "LAUNCH" || in == "EXECUTE") {
					open();
					break;
				}
				else
				if (in == "CALC" || in == "CALCULATE") {
					calc();
					getline(cin, in);
					ofstream activity_log("activity log.txt", ios::app);
					activity_log << in << "\n";
					activity_log.close();
					break;
				}
				else
				if (in == "EXIT" || in == "BYE" || in == "GOOD BYE" || in == "SEE YOU") {
					Exit();
					getline(cin, in);
					ofstream activity_log("activity log.txt", ios::app);
					activity_log << in << "\n";
					activity_log.close();
					break;
				}
				else
				if (in == "SHUT DOWN" || in == "REBOOT" || in == "LOGOFF" || in == "SHUTDOWN") { 
					reboot(); 
					getline(cin, in);
					ofstream activity_log("activity log.txt", ios::app);
					activity_log << in << "\n";
					activity_log.close();
					break;
				}
				else
				if (in == "HELP") {
					help();
					getline(cin, in);
					ofstream activity_log("activity log.txt", ios::app);
					activity_log << in << "\n";
					activity_log.close();
					break;
				}
				if (in == "UPDATE LOG" || in == "SHOW ME THE UPADTE LOG" || in == "RECENT UPDATES" || in == "WHAT'S NEW" || in == "WHAT'S NEW?") {
					updatelog();
					getline(cin, in);
					ofstream activity_log("activity log.txt", ios::app);
					activity_log << in << "\n";
					activity_log.close();
					break;
				}
				if (in == "CHANGE MY PASSWORD" || in == "I WANT TO CHANGE MY PASSWORD" || in == "PASSWORD CHANGE" || in == "RESET MY PASSWORD") {
					passchange();
					getline(cin, in);
					ofstream activity_log("activity log.txt", ios::app);
					activity_log << in << "\n";
					activity_log.close();
					break;
				}
				else AIIR();
			}
			if (test_var_1 == 1) return 0;
		}
	return 0;
}

void AIIR() {
	in += ' ';
	for (int i = 0; i <= in.size(); i++) {
		if (in[i] != ' ') {
			in2 += in[i];
		}
		if (in[i] == ' ') {
			if (in2 == "CALCULATE" || in2 == "CALC") {
				calc();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "ADMINMODE") {
				admin();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "RUN" || in2 == "OPEN" || in2 == "EXECUTE") {
				open_var = true;
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "UPDATES" || in2 == "UPDATE" || in2 == "NEW") {
				updatelog();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "CHANGE" || in2 == "PASSWORD" || in2 == "PASS") {
				passchange();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "LOGOFF" || in2 == "SHUT" || in2 == "OFF") {
				reboot();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "BYE" || in2 == "EXIT") {
				Exit();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "HELP") {
				help();
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "HI" || in2 == "HELLO") {
				cout << "HI, HOW ARE YOU?\n";
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "HOW" || in2 == "YOU?") {
				cout << "I AM ALWAYS GOOD WHEN I AM TALKING WITH YOU\n";
				in2.erase(in2.begin(), in2.end());
			}
			if (in2 == "GOOD" || in2 == "NICE" || in2 == "SUPER" || in2 == "AWESOME" || in2 == "GOOD," || in2 == "NICE," || in2 == "SUPER," || in2 == "AWESOME,") {
				cout << "THAT'S AWESOME!\n";
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "OK" || in2 == "NORM") {
				cout << "DON'T WORRY, BE HAPPY!\n";
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "AWFUL" || in2 == "NORM" || in2 == "NOT") {
				cout << "I AM REALLY SORRY FOR YOU...\n";
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "RequestPassword") {
				admstring = in2;
				cout << "ReqPas\n";
				in2.erase(in2.begin(), in2.end());
				return;
			}
			if (in2 == "false") {
				if (admstring == "RequestPassword") {
					passcheck = false;
					cout << "I will not request password anymore\n";

				}
			}

			in2.erase(in2.begin(), in2.end());
		}
	}
}

void open() {
	cout << "WHAT DO YOU WANT TO OPEN?\n";
	getline(cin, in);
	ofstream activity_log("activity log.txt", ios::app);
	activity_log << in << "\n";
	activity_log.close();
	if (in == "CALCULATOR" || in == "CALC") {
		cout << "OPENING CACLULATOR...\n";
		ShellExecute(NULL, "open", Calc, NULL, NULL, NULL);
		cout << "WELCOME BACK!\n";
		return;
	}
	if (in == "INTERNET" || in == "INTERNET EXPLORER") {
		cout << "OPENING INTERNET EXLPORER...\n";
		ShellExecute(NULL, "open", Explorer, NULL, NULL, NULL);
		cout << "I RARELY SEE PEOPLE USING INTERNET EXPLORER AS A BROWSER\n";
		return;
	}
	if (in == "GOOGLE CHROME" || in == "CHROME") {
		cout << "OPENING GOOGLE CHROME...\n";
		ShellExecute(NULL, "open", Chrome, NULL, NULL, NULL);
		cout << "CHROME OPENED (PROBABLY) \n";
		return;
	}
	return;
}

void calc() {
	int a, b, res;
	char ch;
	cout << "ENTER AN EQUATION, USE +, -, *, (YOU WILL BE ABLE TO DEVIDE IN NEXT UPDATES)\n";
	cout << "FIRST ENTER THE SIGN (+, -, *)\n";
	ofstream activity_log("activity log.txt", ios::app);
	cin >> ch;
	activity_log << ch << "\n";
	cout << "NOW ENTER TWO NUMBERS\n";
	cin >> a >> b;
	activity_log << a << " " << b;
	activity_log.close();
	if (ch == '+') {
		res = a + b;
		cout << "THE RESULT IS: " << res << "\n";
		cout << "GOING TO MENU..\n";
		return;
	}
	if (ch == '-') {
		res = a - b;
		cout << "THE RESULT IS: " << res << "\n";
		cout << "I THINK YOU GOT THE RESULT YOU WANTED\n";
		return;
	}
	if (ch == '*') {
		res = a * b;
		cout << "THE RESULT IS: " << res << "\n";
		cout << "MENU. WHAT DO YOU WANT?\n";
		return;
	}
	if (ch == ':' || ch == '/') {
		cout << "YOU WILL BE ABLE TO DEVIDE (I PROMISE) BUT IN THE NEXT UPDATES\n";
		cout << "WELCOME TO THE CONTROL CENTER (IT'S ALSO CALLED MENU)\n";
		return;
	}
	else
	{
		cout << "WHAT KIND OF A SIGN IS THAT?\n";
		return;
	}
	return;
}












