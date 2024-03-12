#ifndef LABA4_FILE_H
#define LABA4_FILE_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include "struct.h"

using namespace std;

extern struct japanise *japan;
extern int i, isave;

void new_DB();
void remove_DB();
void clear();
void save_DB();
void load_DB();

#endif //LABA4_FILE_H
