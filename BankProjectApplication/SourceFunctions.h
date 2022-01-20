#pragma once

#ifndef SOURCEFUNCTIONS_H
#define SOURCEFUNCTIONS_H

#include <sstream>
#include <iostream>

void showOptions();

std::string CurrencyDblToStr(long double givenDbl, int precision); // Allow a specific level of precision, most commonly 0 or 2 decimal places
std::string CurrencyDblToStr(long double givenDbl); // Automatic determination of precision

#endif