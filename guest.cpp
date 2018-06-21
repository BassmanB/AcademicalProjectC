#include "stdafx.h"
#include <fstream>
#include "guest.h"
#include <vector>
#include <iostream>

using namespace std;

void random_names(ifstream &FileNam, vector<guest> &guest1, int size) {

	int lineNum;
	long random;
	int i = 0;
	string line;

	while (i< size) {


		random = rand() % 150 + 1;
		lineNum = 0;

		FileNam.open("names.txt");
		while (getline(FileNam, line)) {

			if (lineNum == random &&  guest1[i].name == "") {
				guest1[i].name = line;
			}

			lineNum++;
		}
		FileNam.close();

		i++;
	}
};

void random_nationalities(ifstream &FileNat, vector<guest> &guest1, int size) {

	long random;
	int i = 0;
	int lineNum;
	string line;

	while (i<size) {
		random = rand() % 200 + 1;

		lineNum = 0;

		FileNat.open("nationalities.txt");
		
		while (getline(FileNat, line)) {

			if (lineNum == random && guest1[i].nationality == "") {
				guest1[i].nationality = line;

			}

			lineNum++;

		}
		FileNat.close();

		i++;
	}
};

void random_fullnames(ifstream &FileFam, vector<guest>& guest1, int size) {

	long random;
	int lineNum;
	int i = 0;
	string line;

	while (i<size) {

		random = rand() % 100 + 1;

		lineNum = 0;

		FileFam.open("family.txt");
		while (getline(FileFam, line)) {

			if (lineNum == random && guest1[i].familyName == "") {
				guest1[i].familyName = line;
			}

			lineNum++;

		}
		FileFam.close();

		i++;
	}
};

void random_duration(vector<guest>& guest1) {

	int i = 0;
	long duration;

	while (i < guest1.size()) {
		duration = rand() % 7 + 1;
		if (guest1[i].duration == 0) {
			guest1[i].duration = duration;
			i++;
		}
	}
}

void random_reservation_id_dur(vector<guest>& guest1, vector<int>&tab, int &j) {

	int i = 0;
	int k = 0;
	long duration = rand() % 7 + 1;
	int orderNum = rand() % 5 + 1;

	while (i<guest1.size() ) {
		
		if (guest1[i].reservation_ID == 0) {
			guest1[i].reservation_ID = tab[j];
			guest1[i].duration = duration;
		}
		if (k==orderNum) {
			j++;
			orderNum = rand() % 5 + 1;
			duration = rand() % 7 + 1;
			k = 0;
		}
		k++;
		i++;
	}
};

void guest_day(vector<guest>& guest1, int day) {

	for (int i = 0; i < guest1.size(); i++) {
		guest1[i].day = day;
	}
};

void genSixDigVec(vector<int>&tab) {

	for (int i = 1000000; i <9999999; i++) {
		tab.push_back(i);
	}

};

void copy_guest(vector<guest>& guest1, vector<guest>& guest2) {
	

	cout << "size of guest 1  = " << sizeof(guest1) << endl;
	for (int i = 0; i < sizeof(guest1); i++) {
		if(guest1[i].name != "deleted" ){
		guest2[i].name = guest1[i].name;
		guest2[i].familyName = guest1[i].familyName;
		guest2[i].nationality = guest1[i].nationality;
		guest2[i].reservation_ID = guest1[i].reservation_ID;
		guest2[i].day = guest1[i].day;
		guest2[i].duration = guest1[i].duration;
		}
	}

};

vector<string> check_duration(vector<guest>&guest1, int day) {
	vector<string> temp;
	for (int i = 0; i < guest1.size(); i++) {
		if (guest1[i].duration + guest1[i].day == day) {
			temp.push_back(guest1[i].familyName);
			guest1[i].name = "deleted";
		}
	
	}

	return temp;
}

 void remove_guest(vector<guest> &guest1) {
	
	for (int i = 0; i < guest1.size() ; i++) {
		if (guest1[i].name != "deleted") {
			guest1.erase(guest1.begin()+i);
		}
	}

}

 void searchForForeigns(vector<guest>&guest1) {
	 vector<string> names;
	 string min;

	 for (int i = 0; i < guest1.size(); i++) {
		 if (guest1[i].nationality != "Portuguese" || guest1[i].nationality != "South African") {
			 names.push_back(guest1[i].name + " " + guest1[i].familyName + "(" + to_string(guest1[i].reservation_ID) + ")");

		 }
	 }

		 sort(names.begin(), names.end());

		 for (int i = 0; i < names.size(); i++) {
			 cout << names[i] << endl;
		 }
 }

 void searchForSouthAfrica(vector<guest> &guest1) {
	 vector<string> names;
	 string min;

	 for (int i = 0; i < guest1.size(); i++) {
		 if (guest1[i].nationality == "South Africa" ) {
			 names.push_back(guest1[i].name + " " + guest1[i].familyName + "(" + to_string(guest1[i].reservation_ID) + ")");
		 }
	 }
	 sort(names.begin(), names.end());

	 for (int i = 0; i < names.size(); i++) {
		 cout << names[i] << endl;
	 }
 }
