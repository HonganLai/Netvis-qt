#pragma once

#include "datadrvlib_global.h"
#include<qstring.h>
#include<vector>
#include<qfile.h>
#include<QTextStream>
using namespace std;
class DATADRVLIB_EXPORT DataDrvLib
{
public:
    int ReadDataFile(QString fname, vector<pair<int, int>>& vlink);
public:
    DataDrvLib();
};