#pragma once

#include "datamanalib_global.h"
#include<vector>
#include<qstring.h>
#include <QColor>

using namespace std;

typedef struct _tagNodeDMInfo
{
    int id;
    QString name;
    QColor color;
    float x;
    float y;

    vector<int> vNeibor;

}SNodeDMInfo;
class DATAMANALIB_EXPORT DataManaLib
{
private:
    vector<SNodeDMInfo>            m_vNode;
public:
    void SetData(vector<SNodeDMInfo>& vNode);
    vector <SNodeDMInfo>& GetData();
public:
    DataManaLib();
    ~DataManaLib();

};