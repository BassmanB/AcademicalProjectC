#pragma once
#include <string>
#include <fstream>
#include "stdafx.h"
#include "guest.h"
#include "reception.h"

#ifndef ROOM_H
#define ROOM_H

using namespace std;

struct room {
	int number;
	int capacity;
	vector <string> familyName;
};

int make_rooms(room rooms[]);

void putToRoom(reception &receptions, room rooms[]);

void removeFromRoom(room rooms[], vector<string> family);

void killPeopleInRoom(room rooms[]);

#endif