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
	QPoint m_lastPos; // ������һ�����λ��
	int m_clickedNode; // ���汻����Ľڵ���
	int m_clickedEdge; // ���汻����ıߵ���ʼ�ڵ���

private:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

private:
	Ui::ViswidgettryClass ui;

};
