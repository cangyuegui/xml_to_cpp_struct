#include "widget.h"
#include "ui_widget.h"

#include "OTHER.h" // 增加这个头文件引用
#include "ShareTools.h"
#include "OTHER.h"
#include <QDomDocument>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



enum TYPENAME
{
    OBJECT,
    INT,
    DOUBLE,
    STRING
};

struct XmlStruct
{
    QString Name;
    TYPENAME typeName;//Object // int // double // std::string ||// std::vector
    int count{0};
    QList<XmlStruct> nextNodes;

    XmlStruct* search(const QString& key)
    {
        for (int i = 0; i < nextNodes.size(); ++i)
        {
            if (nextNodes[i].Name == key)
            {
                XmlStruct* res;
                XmlStruct& dres = nextNodes[i];
                res = &dres;
                return res;
            }
        }
        return nullptr;
    }
};

QString typeNameToString(const XmlStruct& p, QStringList& nmList)
{
    QString sp;
    switch (p.typeName)
    {
    case INT:
        sp = "int";
        break;
    case DOUBLE:
        sp = "double";
        break;
    case STRING:
        sp = "std::string";
        break;
    default:
    {
        QString struP = p.Name;
        QChar upS = struP[0].toUpper();
        struP.remove(0, 1);
        struP.prepend(upS);
        struP.prepend("Stru");

        while(nmList.contains(struP))
        {
            struP += "_";
        }

        nmList.append(struP);
        sp = struP;
    }
        break;
    }


    return sp;
}



TYPENAME judgetType(const QString& value)
{
    QString numbers(".0123456789");

    bool isNumber = true;
    for (int i = 0; i < value.size(); ++i)
    {
        if (!numbers.contains(value[i]))
        {
            isNumber = false;
            break;
        }
    }

    if (isNumber)
    {
        if (value.count(".") == 1)
        {
            return DOUBLE;
        }
        if (value.count(".") == 0)
        {
            return INT;
        }

        return STRING;
    }

    return STRING;
}

void parseXml(QDomElement& node, XmlStruct& parent)
{
    QString name = node.tagName();
    QString value = node.text();

    if (parent.search(name) != nullptr)
    {
        parent.search(name)->count += 1;
        return;
    }

    XmlStruct thisSreuct;
    thisSreuct.Name = name;
    parent.nextNodes.append(thisSreuct);

    if (node.hasChildNodes())
    {
        QDomNodeList nList = node.childNodes();
        if (nList.size() >= 1)
        {
            if (nList.size() == 1)
            {
                QDomNode firstNode = nList.at(0);
                if (firstNode.toElement().tagName().isEmpty())
                {
                    parent.search(name)->typeName = judgetType(value);
                    parent.search(name)->Name = name;
                    return;
                }
            }

            parent.search(name)->typeName = OBJECT;
            parent.search(name)->Name = name;

            for (int i = 0; i < nList.size(); ++i)
            {
                QDomNode vNode = nList.at(i);
                QDomElement evNode = vNode.toElement();
                parseXml(evNode, *parent.search(name));
            }
        }

    }

    else
    {
        parent.search(name)->typeName = judgetType(value);
    }
}


QString xmlToStruct(const XmlStruct& nodeXml, QStringList& allNm)
{
    if (nodeXml.Name.isEmpty())
    {
        return "";
    }
    QString nodeName;
    QString typeString = typeNameToString(nodeXml, allNm);
    QString structString =
            ShareTools::decodeFromSytemEncode(
                ShareTools::getFileContent(":/RES/struct.cpp"),
                "UTF-8")
            ;
    QString argname = nodeXml.Name;

    switch (nodeXml.typeName)
    {
    case INT:
        argname += "{ 0 }";
        break;
    case DOUBLE:
        argname += "{ 0 }";
        break;
    default:
        break;
    }

    if (nodeXml.count > 0)
    {
        nodeName = QString("std::vector<%1> %2;").arg(typeString, argname);
    }
    else
    {
        nodeName = QString("%1 %2;").arg(typeString, argname);
    }

    QStringList paramString;
    QStringList modeString;

    for (int i = 0; i < nodeXml.nextNodes.size(); ++i)
    {
        QString cell = xmlToStruct(nodeXml.nextNodes[i], allNm);
        QStringList cellList = cell.split("\n");
        QStringList resCellList;
        foreach(QString var, cellList)
        {
            var.prepend("     ");
            resCellList.append(var);
        }
        paramString.append(resCellList.join("\n"));

        modeString.append(nodeXml.nextNodes[i].Name);
    }

    if (nodeXml.typeName != OBJECT)
    {
        return nodeName  + "\n";
    }
    else
    {
        structString = structString.arg(typeString, paramString.join("\n"), modeString.join(","));
        return structString + "\n" + nodeName + "\n";
    }
    return "";
}

void Widget::on_to_textChanged()
{
    ui->from->blockSignals(true);

    QString srcText = ui->to->toPlainText();
    QDomDocument doc("xml_doc");
    XmlStruct topXmlStruct;
    if (!doc.setContent(srcText))
    {
        //
    }
    else
    {
        QDomElement docElem = doc.documentElement();
        QString tagName = docElem.tagName();
        QString value = docElem.text();

        QDomNode topNode = docElem;


        parseXml(docElem, topXmlStruct);

        if (topXmlStruct.nextNodes.size() == 1)
        {
            QStringList allNm;
            QString resString = xmlToStruct(topXmlStruct.nextNodes.first(), allNm);

            QStringList ln;
            QString pStruct = typeNameToString(topXmlStruct.nextNodes.first(), ln);

            resString += "\n";
            resString += pStruct;
            resString += " ";
            resString += "obStructObject;\n";

            ui->from->setPlainText(resString);
        }

    }

    ui->from->blockSignals(false);
}

QString srcToJson(const QString& srcString)
{
    QString res;
    QDomDocument doc("xml_doc");
    if (!doc.setContent(srcString))
    {
        return res;
    }

    QDomElement docElem = doc.documentElement();
    QString tagName = docElem.tagName();
    QString value = docElem.text();

    QDomNode topNode = docElem;


    XmlStruct topXmlStruct;
    parseXml(docElem, topXmlStruct);

    topXmlStruct = topXmlStruct.nextNodes.first();

    QStringList resStringList;
    for (int i = 0; i < topXmlStruct.nextNodes.size(); ++i)
    {
        QString name = topXmlStruct.nextNodes[i].Name;
        if (name.isEmpty())
        {
            continue;
        }
        QString tp = "\"%1\":%2";
        QString value;
        XmlStruct* cP = topXmlStruct.search(name);
        if (cP->typeName == OBJECT)
        {
            continue;
        }
        switch (cP->typeName) {
        case INT:
            value = "0";
            break;
        case DOUBLE:
            value = "0.1";
            break;
        default:
            value = "\"xxx\"";
            break;
        }
        resStringList.append(tp.arg(name, value));
    }

    res = resStringList.join(",\n");
    return res;
}

void Widget::on_from_textChanged()
{
    ui->to->blockSignals(true);
    QString srcText = ui->from->toPlainText();

    QString res = srcToJson(srcText);
    ui->to->setPlainText(res);

    /*
    if (!srcText.isEmpty())
    {
        std::string xmlString = srcText.toStdString();
        x2struct::X::loadxml(xmlString, obStructObject, false);
        std::string resString = x2struct::X::toxml(obStructObject, "Params");
        QString res = QString::fromStdString(resString);
        ui->to->setPlainText(res);
    }
    else
    {
        std::string resString = x2struct::X::toxml(x, "Params");
        QString res = QString::fromStdString(resString);
        ui->to->setPlainText(res);
    }
    */

    ui->to->blockSignals(false);
}
