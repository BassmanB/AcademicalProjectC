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

struct guest*headG;
//struct reception*headR;
struct room*headRm;


int main()
{
	auto rng = default_random_engine{};

	vector<string> tempVect;
	int dayN = 1;
	bool flag;
	int l = 0;
	char a;
	//room*room1 = new room[15];
	reception reception1;

	cout << "System of Hotel EDA is starting..." << endl;
	vector<int>tab;

	genSixDigVec(tab); //generation of vector with 6 - digit numbers;
	shuffle(tab.begin(), tab.end(), rng); //shuffle vector with 6 - digit numbers 

	srand(time(NULL));

	ifstream FileNam;
	ifstream FileNat;
	ifstream FileFam;

	int nOfPl = make_rooms(&headRm); //number of places in a the rooms
	int numberGuestsToAdd;

	//cout << " TO know " << nOfPl << endl;
	//vector <guest> guest1(nOfPl);
	//guest * guest1 = new guest[nOfPl];//first cycle, we are making that much guest to fulfill all rooms with them 
		//we are fullfiling object guest with data.
	
	
	/*for (int i = 0; i < nOfPl; i++) {
		guest1.push_back(guest1);
	}*/

	cout << " hmmm: " << nOfPl<<endl;
	
	random_data(FileNam, FileFam, FileNat ,nOfPl, &headG);
	random_reservation_id_dur(nOfPl, tab, l, &headG);
	sPrint(&headG);

	guest_day(&headG, dayN, nOfPl);
	putGuestReception(&headG, reception1);
	putToRoom(&headRm, reception1);
	

	cout << "Hello in hotel system, press right key to go to the next day, press 's' to save data  press 'p' to print guest" << endl;

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
			//guestNum = guest_size(&headG) + int(floor(sizeof(room1) / 2));
			if (a == KEY_RIGHT) {

				check_duration(&headG, dayN); //checking and removing guest with complete staying
				removeFromRoom(&headRm, &headG);
				numberGuestsToAdd = int(floor(15 / 2));   //check how much more instances needs vector 
				//guest1.resize(guestNum); //resizing the vector guest1

				putGuestReception(&headG, reception1);//put guest waiting at the reception 
				random_reservation_id_dur(nOfPl, tab, l, &headG);

				putToRoom(&headRm, reception1);  //move guest from reception to the rooms
				
				cout << "deleting guest from rooms, adding new guest to reception and to the rooms are done for today" << endl;
				flag = true;
			}
			else if (a == 's') {
				cout << "Saving guest to the files" << endl; //save guest information
			}
			else if (a == 'p') {
				cout << "Guests from Hotel " << endl; //save guest information
				sPrint(&headG);
			}
			if (a == 'o') {

				fflush(stdin);
				cout << "Choose which manual operation you want to do " << endl;
				a = _getch();
				
				if (a == '1') {
					removePeoplefromRoom(&headRm);
				}
				if (a == '2') {
					change_duration(&headG);
				}

				if (a == '4') {
					change_nationality(&headG);
				}
				if (a == '5') {
					change_name(&headG);
				}

				if (a == '6') {
					cout << "Press 1 to search for foreign guests " << endl;
					cout << "Press 2 to search for South African guests " << endl;
					fflush(stdin);
					a = _getch();

					if (a == '1') {
						//presentation of foreign guests
						foreigners_guest_search(&headG);
					}
					if (a == '2') {
						africa_guest_search(&headG);
					}
				}

				if (a == '7') {
					cout << "Press 1 to present foreign guests " << endl;
					cout << "Press 2 to present South African guests" << endl;
					fflush(stdin);
					a = _getch();
		

					if (a == '1') {
						//presentation of foreign guests
						searchForForeigns(&headG);

					}

					if (a == '2') {
						searchForSouthAfrica(&headG);
					}
				}
				}	
			}
		dayN++;
		}

	//delete room1;
	return 0;
}