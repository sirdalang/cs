#ifndef GLOBAL_H__
#define GLOBAL_H__

#include <string>
#include <iostream>
#include <string.h>
#include <assert.h>

typedef int ElemType, &ElemTypeR, *ElemTypeP;
typedef int const& ElemTypeCR;
typedef int const* ElemTypeCP;

typedef std::string ElemValue, &ElemValueR, *ElemValueP;
typedef std::string const& ElemValueCR;
typedef std::string const* ElemValueCP;

#endif // GLOBAL_H__