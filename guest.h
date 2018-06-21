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
	struct guest* next;
};

//void random_names(ifstream &FileNam, int size);
void random_fullnames(ifstream &FileNam, int size);
void random_data(ifstream &FileNam, ifstream &FileFamily, ifstream &FileNat, int size, guest**head);
void sPrint(guest ** head);
void Insert_data(string name, string fullName, string nationality, guest ** head);

void random_reservation_id_dur(int size, vector<int>&tab, int &j, guest ** head);
void genSixDigVec(vector<int>&tab);
void guest_day(guest ** head, int day, int size);
void check_duration(guest**head, int day);
void searchForForeigns(guest**head);
void searchForSouthAfrica(guest ** head);
void change_name(guest**head);
void change_nationality(guest**head);
int guest_size(guest**headG);
void africa_guest_search(guest**head);
void foreigners_guest_search(guest**head);
void change_duration(guest**head);

#endif