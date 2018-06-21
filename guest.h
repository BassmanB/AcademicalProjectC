#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#include "stdafx.h"
#ifndef GUEST_H
#define GUEST_H

using namespace std;

struct guest {

	string name;
	int reservation_ID;
	string nationality;
	int duration;
	string familyName;
	int day;
	
};


void random_names(ifstream &FileNam, vector<guest> &guest1, int size);
void random_fullnames(ifstream &FileFam, vector<guest> &guest1, int size);
void random_nationalities(ifstream &FileNat, vector<guest> &guest1, int size);
void random_duration(vector<guest> &guest1);
void random_reservation_id_dur(vector<guest> &guest1, vector<int>&tab, int &j);
void genSixDigVec(vector<int>&tab);
void guest_day(vector<guest> &guest1, int day);
void copy_guest (vector<guest> &guest1, vector<guest>& guest2);
void remove_guest(vector<guest> &guest1);
vector<string> check_duration(vector<guest>&guest1, int day);
void searchForForeigns(vector<guest>&guest1);
void searchForSouthAfrica(vector<guest>&guest1);

#endif