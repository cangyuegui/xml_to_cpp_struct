#include <QtCore>

namespace ShareTools
{
QString decodeFromSytemEncode(const QByteArray &srcString, const char* codecName)
{
    QTextCodec* pTextCodec = QTextCodec::codecForName(codecName);
    if (NULL == pTextCodec)
    {
        return "";
    }
    return pTextCodec->toUnicode(srcString);
}

QByteArray getFileContent(const QString &file)
{
    if (!QFile::exists(file))
    {
        return QByteArray(NULL);
    }

    QFile dstFile(file);

    if (!dstFile.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        return QByteArray(NULL);
    }

    QByteArray res = dstFile.readAll();
    dstFile.close();
    return res;
}
}
