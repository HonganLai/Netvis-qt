#pragma once

#include"DataManaLib.h"
#include "VisualizationLib.h"
#include "interactionlib_global.h"  
#include<QString>
#include<vector>
class INTERACTIONLIB_EXPORT InterActionLib
{
private:
    DataManaLib* m_datamanagelib;
    VisualizationLib* m_visuallib;
public:
    InterActionLib(DataManaLib* datalib, VisualizationLib* vislib);


public:

    void LoadDataFile(QString fname);

    void Layout(int a,int choose);

    void maxcolor(int choose);

};
