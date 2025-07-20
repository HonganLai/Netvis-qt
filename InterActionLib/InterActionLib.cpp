#include "InterActionLib.h"
#include "DataDrvLib.h"
#include "AlgorithmLib.h"
#include "VisualizationLib.h"
using namespace std;
InterActionLib::InterActionLib(DataManaLib* datalib, VisualizationLib* vislib)
{
	m_datamanagelib = datalib;
	m_visuallib = vislib;
}
void InterActionLib::LoadDataFile(QString fname)
{
	vector<pair<int, int> > vLink;
	DataDrvLib DDlib;
	DDlib.ReadDataFile(fname, vLink);
	int PntNum = 0;
	for (int i = 0; i < vLink.size(); i++)
	{
		PntNum = max(PntNum, vLink[i].first);
		PntNum = max(PntNum, vLink[i].second);
	}


	vector<SNodeDMInfo> vNode;
	vNode.resize(PntNum);

	for (int i = 0; i < vLink.size(); i++)
	{

		int a = vLink[i].first;
		int b = vLink[i].second;

		vNode[a - 1].vNeibor.push_back(b - 1);
		vNode[b - 1].vNeibor.push_back(a - 1);
	}
	m_datamanagelib->SetData(vNode);

	vector<SNodeVisInfo> vNodevis;
	vNodevis.resize(vNode.size());

	for (int i = 0; i < vNode.size(); i++)
	{
		SNodeDMInfo& tp = vNode[i];

		SNodeVisInfo& sp = vNodevis[i];

		sp.x = tp.x;
		sp.y = tp.y;
		sp.vNeibor = tp.vNeibor;
		
	}

	m_visuallib->SetData(vNodevis);


}

void InterActionLib::Layout(int a,int choose)
{
	vector<SNodeDMInfo> vNode = m_datamanagelib->GetData();

	vector<SNodeALInfo> vNodeAl;

	for (int i = 0; i < vNode.size(); i++)
	{
		SNodeDMInfo& sp = vNode[i];

		SNodeALInfo tp;

		tp.x = sp.x;
		tp.y = sp.y;
		tp.vneighbor = sp.vNeibor;
		tp.color = sp.color;

		vNodeAl.push_back(tp);
	}
	AlgorithmLib ALlib;
	if (a == 1)
	{
		ALlib.randomAL(vNodeAl);
	}
	else if (a == 2)
	{
		ALlib.forceDirectedLayout(vNodeAl);
	}
	else if (a == 3)
	{
		ALlib.circleforce(vNodeAl);
	}
	if (choose==1)
	{
		ALlib.Changeecolor(vNodeAl,1);
	}

	for (int i = 0; i < vNode.size(); i++)
	{
		SNodeDMInfo& sp = vNode[i];

		SNodeALInfo& tp = vNodeAl[i];

		sp.x = tp.x;
		sp.y = tp.y;
		sp.color = tp.color;
	}

	m_datamanagelib->SetData(vNode);

	vector<SNodeVisInfo> vNodevis;
	vNodevis.resize(vNode.size());

	for (int i = 0; i < vNode.size(); i++)
	{
		SNodeDMInfo& tp = vNode[i];

		SNodeVisInfo& sp = vNodevis[i];

		sp.x = tp.x;
		sp.y = tp.y;
		sp.vNeibor = tp.vNeibor;
		sp.color = tp.color;
	}

	m_visuallib->SetData(vNodevis);
	choose = 0;
}
