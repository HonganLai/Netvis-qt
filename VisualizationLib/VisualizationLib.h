#pragma once

#include "visualizationlib_global.h"
#include "Viswidgettry.h"
class VISUALIZATIONLIB_EXPORT VisualizationLib
{
public:
    VisualizationLib();
private:
	QWidget* m_viswidget;
public:
	void SetData(vector<SNodeVisInfo>& vNode);
	QWidget* GetWidget();
};
