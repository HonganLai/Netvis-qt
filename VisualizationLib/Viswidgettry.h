#pragma once

#include <QWidget>
#include "ui_Viswidgettry.h"
#include<vector>
#include "visualizationlib_global.h"

using namespace std;

typedef struct _tagSNodeVisInfo
{
	float     x;
	float     y;
	QColor    color;
	float     size;

	QString name;

	vector<int>   vNeibor;
}SNodeVisInfo;

class VISUALIZATIONLIB_EXPORT Viswidgettry : public QWidget
{
	Q_OBJECT
private:
	vector<SNodeVisInfo>     m_vNode;

public:
	void SetData(vector<SNodeVisInfo>& vNode);
	void paintEvent(QPaintEvent* e);
	
	
public:
	Viswidgettry(QWidget *parent = nullptr);
	~Viswidgettry();

	void Viswidgettry::wheelEvent(QWheelEvent* event);
private:
	QPoint m_lastPos; // 保存上一个鼠标位置
	int m_clickedNode; // 保存被点击的节点编号
	int m_clickedEdge; // 保存被点击的边的起始节点编号

private:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

private:
	Ui::ViswidgettryClass ui;

};
