// HotelUMA.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "guest.h"
#include "room.h"
#include "reception.h"
#include <string>
#include <stdlib.h>
#include <ctime> 
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h> 
#include <random>
#include <conio.h>

#define KEY_RIGHT 77 

using namespace std;

int main()
{
	auto rng = default_random_engine{};

	vector<string> tempVect;
	int dayN = 1;
	bool flag;
	int l = 0;
	char a;
	room*room1 = new room[15];
	reception reception1;

	cout << "System of Hotel EDA is starting..." << endl;
	vector<int>tab;

	genSixDigVec(tab); //generation of vector with 6 - digit numbers;
	shuffle(tab.begin(), tab.end(), rng); //shuffle vector with 6 - digit numbers 

	srand(time(NULL));

	ifstream FileNam;
	ifstream FileNat;
	ifstream FileFam;

	int nOfPl = make_rooms(room1); //number of places in a the rooms
	int guestNum;
	vector <guest> guest1(nOfPl);
	//guest * guest1 = new guest[nOfPl];//first cycle, we are making that much guest to fulfill all rooms with them 
		//we are fullfiling object guest with data.
	
	
	/*for (int i = 0; i < nOfPl; i++) {
		guest1.push_back(guest1);
	}*/

	random_names(FileNam, guest1, nOfPl);
	random_fullnames(FileFam, guest1, nOfPl);
	random_nationalities(FileNat, guest1, nOfPl);
//	random_duration(guest1);
	random_reservation_id_dur(guest1, tab, l);
	guest_day(guest1, dayN);
	putToRoom(reception1, room1);
	

	/*for (int i = 0; i < nOfPl; i++) {

		cout << "name: " << guest1[i].name << endl;
		cout << "nationality: " << guest1[i].nationality << endl;
		cout << "Reservation ID: " << guest1[i].reservation_ID << endl;
		cout << "Family Name: " << guest1[i].familyName << endl;
		cout << "Duration: " << guest1[i].duration << endl;
		cout << "Room size: " << room1[i].capacity << endl;
		cout << endl;
	}*/

	//cout << "Hello in hotel system, press right key to go to the next day, press 's' to save data " << endl;


	cout << "---------------------" << endl;
	cout << "Hotel EDA - options " << endl;
	cout << "---------------------" << endl;
	cout << "1 - Clear Room" << endl;
	cout << "2 - change reservation duration" << endl;
	cout << "3 - clear reception" << endl;
	cout << "4 - Edit Nationality" << endl;
	cout << "5 - Edit First name" << endl;
	cout << "6 - Guest review" << endl;
	cout << "7 - Presentation" << endl;
	cout << "0 - Back" << endl;

	while(true) {

		cout << "Hello today is " << dayN << " that hotel EDA works" << endl;
		flag = false;

		while (flag == false) {
			a = _getch();
			guestNum = guest1.size() + int(floor(sizeof(room1) / 2));
			if (a == KEY_RIGHT) {

				tempVect = check_duration(guest1, dayN);
				remove_guest(guest1);			//remove guest with complete staying
				removeFromRoom(room1, tempVect);
				guestNum = guest1.size() + int(floor(sizeof(room1) / 2));   //check how much more instances needs vector 
				guest1.resize(guestNum); //resizing the vector guest1

				putGuestReception(guest1, reception1);//put guest waiting at the reception 

				random_names(FileNam, guest1, guestNum);
				random_fullnames(FileFam, guest1, guestNum);
				random_nationalities(FileNat, guest1, guestNum);
				random_reservation_id_dur(guest1, tab, l);
				putToRoom(reception1, room1);  //move guest from reception to the rooms
				
				cout << "deleting guest from rooms, adding new guest to reception and to the rooms are done for today" << endl;
				flag = true;
			}
			else if (a == 's') {
				cout << "Saving guest to the files" << endl; //save guest information
			}
			if (a == 'o') {

				fflush(stdin);

				cout << "Choose which manual operation you want to do " << endl;
				a = _getch();
				
				if (a == '1') {
					killPeopleInRoom(room1);
				}

				if (a == '7') {
					cout << "Press 1 to present foreign guests " << endl;
					cout << "Press 2 to present South African guests" << endl;
					fflush(stdin);
					a = _getch();
		

					if (a == '1') {
						//presentation of foreign guests
						searchForForeigns(guest1);

					}

					if (a == '2') {
						searchForSouthAfrica(guest1);
					}
				}
				}	
			}
		dayN++;
		}

		
	return 0;
}