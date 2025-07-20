#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NetworkVisualization.h"
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QString>
#include <vector>
#include "VisualizationLib.h"
#include "DataManaLib.h"
#include "InterActionLib.h"


using namespace std;

class NetworkVisualization : public QMainWindow
{
	Q_OBJECT
private:
	DataManaLib* m_datamanagelib;
	InterActionLib* m_interactionlib;
	VisualizationLib* m_visualizationlib;
private:

	//初始化界面
	void InitUI();

	//初始化资源
	void InitResource();

public slots :
void LoadDataFile();
void Layout1();
void Layout2();
void Layout3();
void DenseEmphasize();

public:
	NetworkVisualization(QWidget* parent = nullptr);
	~NetworkVisualization();

private:
	Ui::NetworkVisualizationClass ui;
};
