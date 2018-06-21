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
	vector<string> familyName;
	struct room * next;
};

int make_rooms(room ** head);

//void putToRoom(reception &receptions, room rooms[]);
void putToRoom(room ** headRm, reception &receptions);

//void removeFromRoom(room rooms[], vector<string> family);
void removePeoplefromRoom(room ** head);
void removeFromRoom(room**head, guest**headG);

#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      