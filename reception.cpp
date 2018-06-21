#include "stdafx.h"
#include "room.h"
#include "reception.h"
#include <random>
#include <iostream>

using namespace std;

void putGuestReception(guest ** head, reception &reception) {
	
	guest * temp = *head;
	for (int i = 0; i < reception.family.size(); i++) {
		reception.family[i] = temp->familyName;
	}
}; 