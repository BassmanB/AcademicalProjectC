#include "stdafx.h"
#include "room.h"
#include <random>
#include <iostream>

using namespace std;

//struct room*head;

void putToRoom(room ** headRm, reception &receptions) {

	room*tempRm = *headRm;
	
	for (int j = 0; j < receptions.family.size(); j++) {
		for (int i = 0; i <receptions.family.size(); i++) {
			if (tempRm->familyName.size() <= tempRm->capacity  && tempRm->familyName[i] == "empty") {
				tempRm->familyName[i] = receptions.family[i];
				receptions.family.erase(receptions.family.begin() + i);
			}
		}
		tempRm = tempRm->next;
	}
};

int make_rooms(room**head) {

	int sumOfRooms = 0;

	for (int i = 0; i<15; i++) {
		room*temp1 = new room();
		temp1->number = i;
		temp1->capacity = rand() % 5 + 1;
		temp1->next = *head;
		sumOfRooms = sumOfRooms + temp1->capacity;
		*head = temp1;
	}
 	return sumOfRooms;
};

void removeFromRoom(room**head, guest**headG){
	
	room*temp1 = *head;
	guest*temp = *headG;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < temp1->familyName.size(); j++) {
			temp1->familyName[i] = "empty";
			temp1 = temp1->next;
		}
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < temp1->familyName.size(); j++) {
			temp1->familyName[i] = temp->familyName;
			temp1 = temp1->next;
		}
	}
	
};


void removePeoplefromRoom(room ** head) {
	
	room * temp = *head;
	int n;
	bool check = false;
	cout << "Choose from which room you want to removePeople " << endl;
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

	for (int i = 0; i < temp->familyName.size(); i++) {
		temp->familyName[i] = "empty";
	}
};

