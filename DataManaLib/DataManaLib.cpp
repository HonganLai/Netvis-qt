#include "DataManaLib.h"

DataManaLib::DataManaLib()
{
}

DataManaLib::~DataManaLib()
{
}

void DataManaLib::SetData(vector<SNodeDMInfo>& vNode)
{
	m_vNode = vNode;
}
vector<SNodeDMInfo>& DataManaLib::GetData()
{
	return m_vNode;

}