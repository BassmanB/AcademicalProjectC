#pragma once
#include <string>
#include "guest.h"
#include "stdafx.h"
#ifndef RECEPTION_H
#define RECEPTION_H

using namespace std;

struct reception {
	vector<string> family;
	int time;
	
};

void putGuestReception(guest ** head, reception &reception);


#endif