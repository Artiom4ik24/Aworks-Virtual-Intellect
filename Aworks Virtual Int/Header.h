#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <Windows.h>
#include <string>
#include <Lmcons.h>

using namespace std;

int test_var_1 = 0;
bool adminvar = false;

void passchange() {
	string newpass;
	ofstream ps2("pass.txt");
	if (!ps2) {
		cout << "ERROR CHANGING PASSWORD: THE CURRENT PASSWORD FILE WAS MOVED OR DELETED\n";
		return;
	}
	cout << "PLEASE ENTER YOUR NEW PASSWORD\n";
	getline(cin, newpass);
	ps2 << newpass;
	ps2.close();
	cout << "PASSWORD CHANGED SUCCESFULLY\n";
	return;
}

void reboot() {
	char ch;
	cout << "ARE YOU SURE Y/N?\n";
	cin >> ch;
	ofstream activity_log("activity log.txt", ios::app);
	activity_log << ch << "\n";
	activity_log.close();
	if (ch == 'Y') ExitWindowsEx(EWX_LOGOFF, 0);
	if (ch == 'N') {
		cout << "THEN.. LET'S CONTINUE!\n";
		return;
	}
	else {
		cout << "I WILL MARK THIS AS NO\n";
		return;
	}
	return;
}

void help() {
	cout << "HI!\n";
	cout << "THESE ARE SOME COMMANDS I CAN DO FOR YOU:\n";
	cout << "    CALC - CALCULATE TWO NUMBERS\n";
	cout << "    RUN - RUN A PROGRAM\n";
	cout << "    LOGOFF - I WILL LOG YOU OFF YOUR COMPUTER\n";
	cout << "    UPDATELOG - SHOW THE RECENT UPDATES\n";
	cout << "    CHANGE MY PASSWORD - RESET YOUR CURRENT PASSWORD\n";
	return;
}

void updatelog() {
	cout << "THIS IS THE EVOLUTION OF ME:\n";
	cout << "v 1.0.0  -  FIRST VERSION OF THE PROGRAM, RESPONDED TO COMMANDS OPEN, CALCULATE, REBOOT, EXIT\n";
	cout << "v 1.0.5  -  ADDED THE REPONSE TO COMMANDS THAT AREN'T IN DATABASE\n";
	cout << "v 1.1.0  -  ADDED 'HELP' AND 'UPDATE LOG' COMMANDS, SMALL UPDATE OF CALCULATOR, ABILITY TO RUN MORE PROGRAMMS\n";
	cout << "v 1.1.5  -  ADDED PASSWORD CHANGE FUNCTION, PROGRAMM NEEDS TO BE LOCATED IN A FOLDER\n";
	cout << "v 1.2.0  -  NEW WORDS AND PHRAZES ADDED\n";
	cout << "v 1.2.5  -  SOME ADDITIONAL FEAUTURES ADDED\n";
	cout << "v 1.3.0  -  ADDED AWORKS INTELLIGENT INPUT RECODNIZER (AIIR)\n";
	cout << "v 1.3.5  -  PROGRAM RESPONDS TO 'HELLO' AND SOME ANOTHER BASIC WORDS\n";
}

void pass_check() {
	string pass, newpass, passtxt;
	ifstream ps("pass.txt");
	getline(ps, passtxt);
	if (!ps) {
		ofstream ps2("pass.txt");
		cout << "PLEASE ENTER YOUR NEW PASSWORD\n";
		getline(cin, newpass);
		ps2 << newpass;
		ps2.close();
		return;
	}
	ps.close();
	cout << "PLEASE ENTER YOUR PASSWORD\n";
	while (1) {
		getline(cin, pass);
		if (pass == passtxt) return;
		else
			cout << "WRONG PASSWORD, TRY AGAIN\n";
	}
}

void Exit() {
	char ch;
	cout << "ARE YOU SURE Y/N?\n";
	cin >> ch;
	ofstream activity_log("activity log.txt", ios::app);
	activity_log << ch << "\n";
	activity_log.close();
	if (ch == 'Y') {
		test_var_1 = 1;
		cout << "AUF WIEDERSEHEN!\n";
		exit();
		return;
	}
	if (ch == 'N') {
		cout << "IT'S COOL THAT YOU LIKE WORKING WITH ME\n";
		return;
	}
	else {
		cout << "YOU PROBABLY WANTED TO SAY NO...\n";
		cout << "(I AM GOING TO MENU)\n";
	}
	return;
}

void admin() {
	string str;
	cin >> str;
	if (str == "PasiaMasia00110011") {
		cout << "Welcome back, boss.\n";
		cout << "What do you want to change?\n";
		adminvar = true;
		return;
	}
	else
	return;
}