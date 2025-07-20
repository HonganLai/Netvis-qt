#include "VisualizationLib.h"


VisualizationLib::VisualizationLib()
{
	m_viswidget = new Viswidgettry;
}
void VisualizationLib::SetData(vector<SNodeVisInfo>& vNode)
{
	((Viswidgettry*)m_viswidget)->SetData(vNode);


}

QWidget* VisualizationLib::GetWidget()
{
	return m_viswidget;
}
