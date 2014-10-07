#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "bank.h"

using namespace std;

bank::bank() {
	vault = 100000; 
} 

int bank::givemoney(int n) {
	vault = vault - n;
	return vault;
}

int bank::takemoney(int n) {
	vault = vault + n;
	return vault;
}

int bank::get_Amount()
{
	return vault;
}

bank::~bank() {}