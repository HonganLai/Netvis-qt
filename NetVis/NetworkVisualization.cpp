#include "NetworkVisualization.h"
#include "VisualizationLib.h"
#include "InterActionLib.h"

NetworkVisualization::~NetworkVisualization()
{}


////////////////////////////////////////////////////////////////////


NetworkVisualization::NetworkVisualization(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	InitUI();//菜单布局
	InitResource();//可视化结果
}




void NetworkVisualization::InitUI()
{

	QMenuBar* menubar = menuBar();
	QMenu* File_menu = new QMenu("File");
	QMenu* Option_menu = new QMenu("Option");
	QMenu* Layout_menu = new QMenu("LayOut");
	menubar->addMenu(File_menu);
	menubar->addMenu(Option_menu);
	menubar->addMenu(Layout_menu);

	//文件传输菜单
	QAction* OpenAction = new QAction("Load Data File", this);
	File_menu->addAction(OpenAction);
	connect(OpenAction, SIGNAL(triggered()), this, SLOT(LoadDataFile()));

	//布局算法菜单
	QMenu* type_menu = new QMenu("LayOutType");
	Layout_menu->addMenu(type_menu);
	QAction* randomAction = new QAction("random", this);
	type_menu->addAction(randomAction);
	connect(randomAction, SIGNAL(triggered()), this, SLOT(Layout1()));
	QAction* forceAction = new QAction("force_directed", this);
	type_menu->addAction(forceAction);
	connect(forceAction, SIGNAL(triggered()), this, SLOT(Layout2()));
	QAction* basicAction = new QAction("circleforce", this);
	type_menu->addAction(basicAction);
	connect(basicAction, SIGNAL(triggered()), this, SLOT(Layout3()));

	//用户选择菜单
	QAction* DenseEmphasizeAction = new QAction("DenseEmphasize", this);
	Option_menu->addAction(DenseEmphasizeAction);
	connect(DenseEmphasizeAction, SIGNAL(triggered()), this, SLOT(DenseEmphasize()));
}



void NetworkVisualization::InitResource()
{
	m_datamanagelib = new DataManaLib;

	m_visualizationlib = new VisualizationLib;

	setCentralWidget(m_visualizationlib->GetWidget());
	m_interactionlib = new InterActionLib(m_datamanagelib, m_visualizationlib);
}
void NetworkVisualization::LoadDataFile()
{

	QString fname;
	fname = QFileDialog::QFileDialog::getOpenFileName(this, tr("Open File"),
		"", tr("Text files (*.txt)"));

	m_interactionlib->LoadDataFile(fname);

}


void NetworkVisualization::Layout1()
{

	m_interactionlib->Layout(1,0);
}
void NetworkVisualization::Layout2()
{

	m_interactionlib->Layout(2,0);
}
void NetworkVisualization::Layout3()
{

	m_interactionlib->Layout(3,0);
}

void NetworkVisualization::DenseEmphasize()
{

	m_interactionlib->Layout(NULL,1);
}


