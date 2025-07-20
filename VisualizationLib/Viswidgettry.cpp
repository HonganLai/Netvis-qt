#include "Viswidgettry.h"
#include <qpainter.h>
#include <qpen.h>
#include<QMouseEvent>
#include <QColor> 
#include <QStylePainter>

Viswidgettry::Viswidgettry(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Viswidgettry::~Viswidgettry()
{}
/*void Viswidgettry::paintEvent(QPaintEvent* e)
{
	int w = width();
	int h = height();
	QPainter t_painter(this);

	QPen t_pen;

	t_pen.setColor(QColor(0x66, 0x66, 0x66));
	t_painter.setPen(t_pen);

	for (int i = 0; i < m_vNode.size(); i++)
	{
		float x = m_vNode[i].x * w;
		float y = m_vNode[i].y * h;

		t_painter.drawEllipse(x, y, 3, 3);

		for (int j = 0; j < m_vNode[i].vNeibor.size(); j++)
		{
			float tx = m_vNode[m_vNode[i].vNeibor[j]].x * w;
			float ty = m_vNode[m_vNode[i].vNeibor[j]].y * h;

			t_painter.drawLine(x, y, tx, ty);
		}
	}

}*/
/*void Viswidgettry::paintEvent(QPaintEvent* e)
{
    int w = width();
    int h = height();

    QPainter t_painter(this);
    QPen t_pen;
    t_pen.setColor(QColor(0x66, 0x66, 0x66));

    QPen green_pen;
    green_pen.setColor(Qt::green);

    for (int i = 0; i < m_vNode.size(); i++)
    {
        float x = m_vNode[i].x * w;
        float y = m_vNode[i].y * h;

        if (m_vNode[i].color == QColor(Qt::green))
        {
            t_painter.setPen(green_pen);
            t_painter.setBrush(QBrush(Qt::green));
        }
        else
        {
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush());
        }

        t_painter.drawEllipse(x, y, 3, 3);

        for (int j = 0; j < m_vNode[i].vNeibor.size(); j++)
        {
            float tx = m_vNode[m_vNode[i].vNeibor[j]].x * w;
            float ty = m_vNode[m_vNode[i].vNeibor[j]].y * h;

            if (m_vNode[i].color == QColor(Qt::green) || m_vNode[m_vNode[i].vNeibor[j]].color == QColor(Qt::green))
            {
                // ������һ���ڵ�����ɫ������ɫ��
                t_painter.setPen(green_pen);
            }
            else
            {
                // �����������ɫ��
                t_painter.setPen(t_pen);
            }

            t_painter.drawLine(x, y, tx, ty);
        }
    }
}*/
void Viswidgettry::paintEvent(QPaintEvent* e)
{
    int w = width();
    int h = height();

    QPainter t_painter(this);
    QPen t_pen;
    // ���ó�ʼ��ɫ
    QColor gray_color = QColor(0x66, 0x66, 0x66);

    for (int i = 0; i < m_vNode.size(); i++)
    {
        float x = m_vNode[i].x * w;
        float y = m_vNode[i].y * h;
        if (i == m_clickedNode)
        {
            // ѡ�еĽڵ����ɫ
            t_pen.setColor(QColor(255, 0, 255));
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush(QColor(255, 0, 255)));
        }
        else if (m_vNode[i].color == Qt::red)
        {
            // QColorΪred�ĵ��Ǻ�ɫ
            t_pen.setColor(Qt::red);
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush(Qt::red));
        }
        else if (m_vNode[i].color == QColor(255, 140, 0))
        {
            // ��ɫ
            t_pen.setColor(QColor(255, 140, 0));
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush(QColor(255, 140, 0)));
        }
        else if (m_vNode[i].color == Qt::yellow)
        {
            // ��ɫ
            t_pen.setColor(Qt::yellow);
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush(Qt::yellow));
        }
        else if (m_vNode[i].color == Qt::green)
        {
            // ��ɫ
            t_pen.setColor(Qt::green);
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush(Qt::green));
        }
        else
        {
            // �����Ϊ��ɫ
            t_pen.setColor(gray_color);
            t_painter.setPen(t_pen);
            t_painter.setBrush(QBrush());
        }

        t_painter.drawEllipse(x, y, 3, 3);

        for (int j = 0; j < m_vNode[i].vNeibor.size(); j++)
        {
            float tx = m_vNode[m_vNode[i].vNeibor[j]].x * w;
            float ty = m_vNode[m_vNode[i].vNeibor[j]].y * h;

            if (i == m_clickedEdge || m_vNode[i].vNeibor[j] == m_clickedEdge)
            {
                // ѡ�еı߱���ɫ
                t_pen.setColor(QColor(255, 0, 255));
                t_painter.setPen(t_pen);
            }

            else if (m_vNode[i].color == Qt::red || m_vNode[m_vNode[i].vNeibor[j]].color == Qt::red)
            {
                // ��ɫ�ı�
                t_pen.setColor(Qt::red);
                t_painter.setPen(t_pen);
            }
            else if (m_vNode[i].color == QColor(255, 140, 0) || m_vNode[m_vNode[i].vNeibor[j]].color == QColor(255, 140, 0))
            {
                // ��ɫ�ı�
                t_pen.setColor(QColor(255, 140, 0));
                t_painter.setPen(t_pen);
            }
            else if (m_vNode[i].color == Qt::yellow || m_vNode[m_vNode[i].vNeibor[j]].color == Qt::yellow)
            {
                // ��ɫ�ı�
                t_pen.setColor(Qt::yellow);
                t_painter.setPen(t_pen);
            }
            else if (m_vNode[i].color == Qt::green || m_vNode[m_vNode[i].vNeibor[j]].color == Qt::green)
            {
                // ��ɫ�ı�
                t_pen.setColor(Qt::green);
                t_painter.setPen(t_pen);
            }
            else
            {
                // �������Ϊ��ɫ
                t_pen.setColor(gray_color);
                t_painter.setPen(t_pen);
            }

            t_painter.drawLine(x, y, tx, ty);
        }
    }
}


void Viswidgettry::SetData(vector<SNodeVisInfo>& vNode)//m_node����allib�����vnode
{
	m_vNode = vNode;

	update();
}

void Viswidgettry::wheelEvent(QWheelEvent* event)
{
    int numDegrees = event->delta() / -8;//��ȡ�����ֵĹ���ֵ��һ���̶ȴ�������ľ���Ϊ8������
    int numSteps = numDegrees / 15;//�������Ŀ̶�ת��Ϊ������һ����������1������

    //���������λ��Ϊ�������ŵı�������
    float centerX = event->pos().x();
    float centerY = event->pos().y();
    float w = width();
    float h = height();
    float scale = pow(0.9, numSteps);//ÿ������ϵ��Ϊ0.9

    for (int i = 0; i < m_vNode.size(); i++)
    {
        //���Žڵ�λ��
        m_vNode[i].x = (m_vNode[i].x - centerX / w) * scale + centerX / w;
        m_vNode[i].y = (m_vNode[i].y - centerY / h) * scale + centerY / h;

        //���Žڵ��С
        m_vNode[i].size *= scale;
    }

    update();//ˢ�½���
}

void Viswidgettry::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPos = event->pos();

        float w = width();
        float h = height();
        QPointF ptF = event->pos();

        // ���ҵ�ǰ�Ƿ�ѡ����һ���ڵ㣬������򽫽ڵ���
        for (int i = 0; i < m_vNode.size(); i++)
        {
            float x = m_vNode[i].x * w;
            float y = m_vNode[i].y * h;
            QRectF rect(x - 5, y - 5, 10, 10);
            if (rect.contains(ptF))
            {
                m_clickedNode = i;
                m_vNode[i].size = 7;
                update();
                return;
            }
        }

        // ���ҵ�ǰ�Ƿ�ѡ����һ���ߣ�������򽫱ߺ������ӵ������ڵ���
        for (int i = 0; i < m_vNode.size(); i++)
        {
            float x1 = m_vNode[i].x * w;
            float y1 = m_vNode[i].y * h;

            for (int j = 0; j < m_vNode[i].vNeibor.size(); j++)
            {
                float x2 = m_vNode[m_vNode[i].vNeibor[j]].x * w;
                float y2 = m_vNode[m_vNode[i].vNeibor[j]].y * h;

                QLineF line(x1, y1, x2, y2);
                if (line.length() < 1e-4)
                    continue;
                QPolygonF poly;
                poly << QPointF(x1 - 3, y1 - 3) << QPointF(x1 + 3, y1 + 3) << QPointF(x2 + 3, y2 + 3) << QPointF(x2 - 3, y2 - 3);

                if (poly.containsPoint(ptF, Qt::OddEvenFill))
                {
                    m_clickedEdge = i;
                    m_vNode[i].size = 7;
                    m_vNode[m_vNode[i].vNeibor[j]].size = 7;
                    update();
                    return;
                }
            }
        }
    }
}
void Viswidgettry::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (m_clickedNode >= 0)
        {
            m_vNode[m_clickedNode].size = 5;
            m_clickedNode = -1;
        }

        if (m_clickedEdge >= 0)
        {
            m_vNode[m_clickedEdge].size = 5;
            int endNode = m_vNode[m_clickedEdge].vNeibor[0];
            if (endNode == m_clickedEdge) endNode = m_vNode[m_clickedEdge].vNeibor[1];
            m_vNode[endNode].size = 5;
            m_clickedEdge = -1;
        }

        m_lastPos = event->pos();
        update();
    }
}
void Viswidgettry::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) && (m_clickedNode < 0 && m_clickedEdge < 0))
    {
        QPoint delta = event->pos() - m_lastPos;

        for (int i = 0; i < m_vNode.size(); i++)
        {
            m_vNode[i].x += delta.x() / (float)width();
            m_vNode[i].y += delta.y() / (float)height();
        }
        m_lastPos = event->pos();
        update();
    }
}