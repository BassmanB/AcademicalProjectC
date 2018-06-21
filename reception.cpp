#include "stdafx.h"
#include "room.h"
#include "reception.h"
#include <random>
#include <iostream>

using namespace std;

void putGuestReception(vector<guest> &guest1, reception &reception) {
	
	for (int i = 0; i < reception.family.size(); i++) {
		reception.family[i] = guest1[i].familyName;
	}
};