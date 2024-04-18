#include "dynamic.h"
#include <iostream>

using namespace std;

Dynamic::Dynamic(const string& n) : name(n) { cout << n <<" object created!" << endl; }

Dynamic::~Dynamic() { cout << name << " object destroyed!" << endl; }