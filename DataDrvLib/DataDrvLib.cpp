#include "DataDrvLib.h"

DataDrvLib::DataDrvLib()
{
}
int DataDrvLib::ReadDataFile(QString fname, vector<pair<int, int>>& vLink)
{
	QFile t_file(fname);
	QTextStream t_stream(&t_file);
	t_file.open(QIODevice::ReadOnly);
	while (!t_stream.atEnd())
	{
		QString strLine = t_stream.readLine();
		QStringList t_list = strLine.split(" ");

		int first = t_list.at(0).toInt();
		int second = t_list.at(1).toInt();
		vLink.push_back(make_pair(first, second));
	}
	t_file.close();

	return 0;
}