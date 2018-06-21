#include "stdafx.h"
#include "room.h"
#include <random>
#include <iostream>

using namespace std;

void putToRoom(reception &receptions, room rooms[]) {
	for (int j = 0; j < receptions.family.size(); j++) {
		for (int i = 0; i < receptions.family.size(); i++) {
			if (rooms[j].familyName.size() <= rooms[j].capacity  && rooms[j].familyName[i] == "empty") {
				rooms[j].familyName[i] = receptions.family[i];
				receptions.family.erase(receptions.family.begin() + i);
			}
		}
	}
};

int make_rooms(room rooms[]) {

	int sumOfRooms = 0;

	for (int i = 0; i<15; i++) {
		rooms[i].number = i;
		rooms[i].capacity = rand() % 5 + 1;
	}

	for (int i = 0; i<15; i++) {
		sumOfRooms = sumOfRooms + rooms[i].capacity;
	}

 	return sumOfRooms;
};



void removeFromRoom(room rooms[], vector<string> family){	
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j <rooms[i].familyName.size(); j++) {
			if (rooms[i].familyName[j] ==family[j]){
				rooms[i].familyName[j] = "empty";
			}
		}
	}

};

void killPeopleInRoom(room rooms[]) {
	int n;
	bool check = false;
	cout << "Choose from which room you want to kill People " << endl;
	cin >> n;
	if (n > 0 || n <= 15) {
		check = true;
	}

	while (check == false) {
		cout << "Write n again " << endl;
		cin >> n;
		if (n > 0 || n <= 15) {
			check = true;
		}
	}

	for (int i = 0; i < rooms[n].familyName.size(); i++) {
		rooms[n].familyName[i] = "empty";
	}
};


