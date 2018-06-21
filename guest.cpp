#include "stdafx.h"
#include <fstream>
#include "guest.h"
#include <vector>
#include <iostream>

using namespace std;


int guest_size(guest** head) {
	guest * temp = *head;
	int i = 1;

	while (temp->next != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}

void Insert_data(string name, string fullName, string nationality, guest ** head ) {

	guest*temp1 = new guest();
	temp1->name = name;
	temp1->familyName = fullName;
	temp1->nationality = nationality;
	temp1->next = *head;
 	*head = temp1;
};

void addGuests(guest**head, int num) {
	

}

void sPrint(guest ** head){

	guest * temp = *head;
	while (temp != NULL) {
		cout << temp->name << " " << temp->familyName << " " << temp->nationality << "  Reservation ID " <<  temp->reservation_ID << " Duration  " << temp->duration<< endl;
		temp = temp->next;
	}
	cout << "__________ " << endl;
};

void random_data(ifstream &FileNam, ifstream &FileFamily, ifstream &FileNat, int size, guest**head) {

	int lineNum;
	long randomN;
	long randomF;
	long randomNat;
	int i = 0;
	string line;
	string line2;
	string line3;
	int j = 1;

	while (i< size) {
		randomF = rand() % 60 + 1;
		lineNum = 0;
		FileNam.open("names.txt");
		FileNat.open("nationalities.txt");
		FileFamily.open("family.txt");
 
		while (getline(FileNam, line) && getline(FileNat, line2) && getline(FileFamily, line3)) {
			if (lineNum == randomF) {
				Insert_data(line, line2, line3, head);	
				cout << "count    " << i << endl;
			}
			lineNum++;
		}
		FileNam.close();
		FileNat.close();
		FileFamily.close();
		i++;
	}
};

void random_fullnames(ifstream &FileFam, int size) {

	long random;
	int lineNum;
	int i = 0;
	string line;

	while (i<size) {

		random = rand() % 100 + 1;

		lineNum = 0;

		FileFam.open("family.txt");
		while (getline(FileFam, line)) {

			if (lineNum == random) {
//				 Insert_fullname(line);
			}
			lineNum++;
		}
		FileFam.close();
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

/*void random_duration(vector<guest>& guest1) {

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

*/
void random_reservation_id_dur(int size, vector<int>&tab, int &j, guest**head) {

	cout << " importante " << size << endl;
	guest * temp = *head;
	int i = 0;
	int k = 0;
	long duration = rand() % 7 + 1;
	int orderNum = rand() % 5 + 1;

	while (i<size ) {
		
		//if (temp[i].reservation_ID == 0) {
		temp->reservation_ID = tab[j];
		temp->duration = duration;
		temp = temp->next;
	//	}
		if (k==orderNum) {
			j++;
			orderNum = rand() % 5 + 1;
			duration = rand() % 7 + 1;
			k = 0;
		}
		k++;
		i++;
	}
//	sPrint();
};

void guest_day(guest ** head, int day, int size) {

	guest*temp = *head;

	for (int i = 0; i < size; i++) {
		temp->day = day;
		temp = temp->next;
	}
};

void genSixDigVec(vector<int>&tab) {

	for (int i = 100000; i <999999; i++) {
		tab.push_back(i);
	}

};

/*void copy_guest(vector<guest>& guest1, vector<guest>& guest2) {
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

};*/

void check_duration(guest**head, int day) {
	

	guest * temp1 = *head;


	for (int i = 0; i < guest_size(*(&head)); i++) {

		if (temp1->duration + temp1->day == day) {
//			remove_guest(*(&head), i);

		}
		temp1 = temp1->next;
	}
}

void remove_guest(guest**head ,int n) {
	guest* temp1 = *head;

	if (n == 1) {
		*head = temp1->next;
		delete(temp1);
		return;
	}

	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
	}
	guest* temp2 = temp1->next;
	temp1->next = temp2->next;

	delete temp2;
};

 
 void searchForForeigns(guest**head) {
	 guest * temp = *head;
	 vector<string> names;
	 string min;

	 for (int i = 0; i < guest_size(&(*head)); i++) {
		 if (temp->nationality != "South Africa") {
			 names.push_back(temp->name + " " + temp->familyName + "(" + to_string(temp->reservation_ID) + ")");
			 temp = temp->next;
		 }
	 }
	 sort(names.begin(), names.end());

	 for (int i = 0; i < names.size(); i++) {
		 cout << names[i] << endl;
	 }
 }

 
 void searchForSouthAfrica(guest ** head) {
	 guest * temp = *head;
	 vector<string> names;
	 string min;

	 for (int i = 0; i < guest_size(&(*head)); i++) {
		 if (temp->nationality == "South Africa" ) {
			 names.push_back(temp->name + " " + temp->familyName + "(" + to_string(temp->reservation_ID) + ")");
			 temp = temp->next;
		 }
	 }
	 sort(names.begin(), names.end());

	 for (int i = 0; i < names.size(); i++) {
		 cout << names[i] << endl;
	 }
 }

 void change_name(guest**head) {
	 int n;
	 string newName;
	 guest*temp = *head;
	 cout << "We have " << guest_size(&(*head)) << " guest choose number of which one you want to change " << endl;

	 cin >> n;
	 while(n > guest_size(&(*head)) && n < 0) {
		 cout << "Insert number again " << endl;
	 }
		
	 for (int i = 0; i < n; i++) {
		 temp = temp->next;
	 }
	 cout << "Insert new name " << endl;
	 cin >> newName;
	 temp->name = newName;
 }

 void change_duration(guest**head) {
	 int n;
	 int newDuration;
	 int tempNum;
	 guest*temp = *head;
	 cout << "We have " << guest_size(&(*head)) << " guest choose number of which one you want to change duration " << endl;

	 cin >> n;
	 while (n > guest_size(&(*head)) && n < 0) {
		 cout << "Insert number again " << endl;
	 }

	 for (int i = 0; i < n; i++) {
		 temp = temp->next;
	 }
	 cout << "Insert new duration " << endl;
	 tempNum = temp->reservation_ID;
	 cin >> newDuration;

	 temp = *head;
	 for (int i = 0; i < guest_size(&(*head))-1; i++) {
		 if (tempNum == temp->reservation_ID) {
			 temp->duration = newDuration;
			 cout << "guest with new duration " << temp->name << " " << temp->duration << endl;
		 }
		 temp = temp->next;
	 }

 }

 void change_nationality(guest**head) {

	 int n;
	 string newNationality;
	 guest*temp = *head;
	 cout << "We have " << guest_size(&(*head)) << " guest choose number of which one Nationality you want to change " << endl;

	 cin >> n;
	 while (n > guest_size(&(*head)) && n < 0) {
		 cout << "Insert number again " << endl;
	 }

	 for (int i = 0; i < n; i++) {
		 temp = temp->next;
	 }
	 cout << "Insert new nationality " << endl;
	 cin >> newNationality;
	 temp->name = newNationality;
 }

 void africa_guest_search(guest**head) {
	 guest * temp = *head;
	 string sName;

	 cout << "write a name of guest from South Africa that you want to find" << endl;
	 cin >> sName;

	 for (int i = 0; i < guest_size(&(*head)); i++) {
		 if (temp->name == sName && temp->nationality == "South Africa") {
			 cout << "Yes we found " << sName << " from " << temp->nationality << endl;
		 }
		 temp = temp->next;
	 }

 }
 void foreigners_guest_search(guest**head) {
	 guest * temp = *head;
	 string sName;

	 cout << "write a name of guest from South Africa that you want to find" << endl;
	 cin >> sName;

	 for (int i = 0; i < guest_size(&(*head)); i++) {
		 if (temp->name == sName && temp->nationality != "South Africa") {
			 cout << "Yes we found " << sName  <<" from " << temp->nationality << endl;
		 }
		 temp = temp->next;
	 }

 }
