#ifndef _ShareTools_H__
#define _ShareTools_H__

#include <QByteArray>
#include <QString>

namespace ShareTools
{
    QString decodeFromSytemEncode(const QByteArray &srcString, const char* codecName);
    QByteArray getFileContent(const QString &file);
}

#endif //_ShareTools_H__
