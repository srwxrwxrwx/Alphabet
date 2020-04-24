﻿/*
Заголовочный файл functions.h содержит объявления функций,
используемых в программе "Алфавит".
*/

#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

char determine_way(int, char* []);
void finish();
void read_console(int, char* [], std::vector<std::string>*);
bool read_file(int, char* [], std::vector<std::string>*);

#endif