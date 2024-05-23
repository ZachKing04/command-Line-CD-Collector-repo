#include <iostream>
#include <vector>
#include "cdcase.hpp"
#pragma once
using std::string;

bool number(string stringstring);

string getMenuInput(std::vector<string> availableOptions);

void getCDInput(string &addArtist, string &addTitle, string &addYear, string &addCountry);

void getSearchInfo(string &addArtist, string &addTitle);

void wishlistMenu(CDCase &collec, string &WishlistSortingComparator, string &addArtist, string &addTitle, string &addYear, string &addCountry);


void initialize();