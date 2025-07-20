#include "AlgorithmLib.h"
#include <iostream>
#include <cmath>
#include <qbrush.h>

AlgorithmLib::AlgorithmLib()
{
}

void AlgorithmLib::forceDirectedLayout(vector<SNodeALInfo>& vNode)//ŷ�������㷨�������򲼾�
{
    // ��ʼ������
    float k = 0.1f;   // ����
    float temperature = 1000.0f;  // ��ʼ�¶�
    float minTemperature = 1.0f;  // ��С�¶�
    float coolingRate = 0.99f;    // ��ȴ����

    // ��ʼ���ڵ�����
    for (int i = 0; i < vNode.size(); ++i) {
        vNode[i].x = ((float)rand() / RAND_MAX) * 100.0f;   // x������[0,100]����ֲ�
        vNode[i].y = ((float)rand() / RAND_MAX) * 100.0f;   // y������[0,100]����ֲ�
        vNode[i].color = QColor(Qt::darkGray);
    }

    while (temperature > minTemperature) {
        // ����ڵ��ĳ���
        for (int i = 0; i < vNode.size(); ++i) {
            for (int j = i + 1; j < vNode.size(); ++j) {
                float dx = vNode[i].x - vNode[j].x;
                float dy = vNode[i].y - vNode[j].y;
                float d = sqrt(dx * dx + dy * dy);   // ��������

                if (d != 0.0f) {   // �������0
                    float repulsion = k * k / d;
                    vNode[i].x += dx / d * repulsion;
                    vNode[i].y += dy / d * repulsion;
                    vNode[j].x -= dx / d * repulsion;
                    vNode[j].y -= dy / d * repulsion;
                }
            }
        }

        // ����ڵ����ھӽڵ�֮�������
        for (int i = 0; i < vNode.size(); ++i) {
            for (int j = 0; j < vNode[i].vneighbor.size(); ++j) {
                int neighborIdx = vNode[i].vneighbor[j];
                float dx = vNode[i].x - vNode[neighborIdx].x;
                float dy = vNode[i].y - vNode[neighborIdx].y;

                float attraction = dx * dx + dy * dy;
                if (attraction != 0.0f) {   // �������0
                    attraction = attraction / k;
                    vNode[i].x = vNode[i].x - dx / attraction;
                    vNode[i].y = vNode[i].y - dy / attraction;
                    vNode[neighborIdx].x = vNode[neighborIdx].x + dx / attraction;
                    vNode[neighborIdx].y = vNode[neighborIdx].y + dy / attraction;
                }
            }
        }

        // ��ȴ
        temperature = temperature * coolingRate;
    }

    // ��һ������
    float minX = FLT_MAX, minY = FLT_MAX, maxX = FLT_MIN, maxY = FLT_MIN;
    for (int i = 0; i < vNode.size(); ++i) {
        if (vNode[i].x < minX) minX = vNode[i].x;
        if (vNode[i].y < minY) minY = vNode[i].y;
        if (vNode[i].x > maxX) maxX = vNode[i].x;
        if (vNode[i].y > maxY) maxY = vNode[i].y;
    }
    float scaleX = 1.0f / (maxX - minX), scaleY = 1.0f / (maxY - minY);
    for (int i = 0; i < vNode.size(); ++i) {
        vNode[i].x = (vNode[i].x - minX) * scaleX;
        vNode[i].y = (vNode[i].y - minY) * scaleY;
    }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AlgorithmLib::randomAL(vector<SNodeALInfo>& vNode)//����+�ṹ��洢node
{
    for (int i = 0; i < vNode.size(); i++)
    {
        SNodeALInfo& tp = vNode[i];
        tp.x = qrand() * 1.0 / RAND_MAX;
        tp.y = qrand() * 1.0 / RAND_MAX;
        tp.color= QColor(Qt::darkGray);
    }//���������
    

    
   // Changeecolor(vNode);
}

int* AlgorithmLib::MaxDense(vector<SNodeALInfo>& vNode)
{
    int maxpoint[4] = { 0,0,0,0 };
    for (int i = 0; i < vNode.size(); i++) // ����ÿ���ڵ�
    {
        if (vNode[i].vneighbor.size() > vNode[maxpoint[0]].vneighbor.size())
        {
            maxpoint[3] = maxpoint[2];
            maxpoint[2] = maxpoint[1];
            maxpoint[1] = maxpoint[0];
            maxpoint[0] = i; // �������ĵ�
        }
        else if (vNode[i].vneighbor.size() > vNode[maxpoint[1]].vneighbor.size())
        {
            maxpoint[3] = maxpoint[2];
            maxpoint[2] = maxpoint[1];
            maxpoint[1] = i; // ���µڶ���ĵ�
        }
        else if (vNode[i].vneighbor.size() > vNode[maxpoint[2]].vneighbor.size())
        {
            maxpoint[3] = maxpoint[2];
            maxpoint[2] = i; // ���µ�����ĵ�
        }
        else if (vNode[i].vneighbor.size() > vNode[maxpoint[3]].vneighbor.size())
        {
            maxpoint[3] = i; // ���µ��Ĵ�ĵ�
        }
    }
    int* ptr = new int[4];
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = maxpoint[i];
    }
    return ptr;
}





void AlgorithmLib::NodeColor(vector<SNodeALInfo>& vNode, int* maxpoint)
{
 
    vNode[maxpoint[0]].color = QColor(Qt::red);
    vNode[maxpoint[1]].color = QColor(255,140,0);
    vNode[maxpoint[2]].color = QColor(Qt::yellow);
    vNode[maxpoint[3]].color = QColor(Qt::green);
}

void AlgorithmLib::Changeecolor(vector<SNodeALInfo>& vNode,int choose)
{
    if (choose == 1)
    {
        NodeColor(vNode, MaxDense(vNode));
    }

}




void AlgorithmLib::circleforce(vector<SNodeALInfo>& vNode)//Բ�β����㷨ʵ��
{
    //����ڵ�����
    int node_count = vNode.size();

    //ȷ��Բ��
    float cx = 50;
    float cy = 50;
    float r = 48;


    //���ݽڵ�������Բ�ֳ����ɵȷ�
    float drad = 2 * 3.1415926 / node_count;
    float angle = 0;
    float nx;
    float ny;
    //���ݵȷ����ͽڵ�ı�ż���ÿ���ڵ��λ��
    for (int i = 0; i < node_count; i++)
    {
        angle = angle + drad;
        nx = cx + r * cos(angle);
        ny = cy + r * sin(angle);

        //���½ڵ������
        vNode[i].x = nx / (100);
        vNode[i].y = ny / (100);
        vNode[i].color = QColor(Qt::darkGray);
    }

}