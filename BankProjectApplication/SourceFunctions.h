#pragma once

#ifndef SOURCEFUNCTIONS_H
#define SOURCEFUNCTIONS_H

#include <sstream>
#include <iostream>

void showOptions();

std::string CurrencyDblToStr(long double givenDbl, int precision);
std::string CurrencyDblToStr(long double givenDbl); // Automatic determination of precision

#endif