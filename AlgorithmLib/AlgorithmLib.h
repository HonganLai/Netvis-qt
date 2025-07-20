#pragma once

#include "algorithmlib_global.h"
#include<vector>
#include <iostream>
#include <cmath>
#include <QColor>
using namespace std;

typedef struct _tagNodeALInfo
{
    float x;
    float y;//在画布上的相对位置
    QColor color;
   

    vector<int> vneighbor;

}SNodeALInfo;


class ALGORITHMLIB_EXPORT AlgorithmLib
{

public:
    AlgorithmLib();
public:
    void randomAL(vector<SNodeALInfo>& vNode);
    void forceDirectedLayout(vector<SNodeALInfo>& vNode);
    void circleforce(vector<SNodeALInfo>& vNode);

    //vector<int> MaxDense(const vector<SNodeALInfo>& vNode);
    int* MaxDense(vector<SNodeALInfo>& vNode);
    void NodeColor(vector<SNodeALInfo>& vNode, int* maxpoint);
    void Changeecolor(vector<SNodeALInfo>& vNode,int choose); 

};