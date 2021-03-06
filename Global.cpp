﻿#include "Global.h"

#include <QCoreApplication>
#include <QApplication>
#include <QFileInfo>
#include <QDir>

QString Global::Authority = "2";
QString Global::DisplayName = QString();

QString Global::Database = "bookdata";
QString Global::Hostname = "localhost";
QString Global::Username = "root";
QString Global::Passwd   = "";

QString Global::PathImage = QString();
QString Global::PathMask = QString();
QString Global::PathResult = QString();
QString Global::ExtMask = QString();
QString Global::ExtResult = QString();

QString Global::NewName = QString();
QString Global::MoliId = QString();

QtAwesome* Global::Awesome = 0;

QColor Global::LabelledColor = QColor(0, 150, 0);
QColor Global::UnLabelledColor = QColor(125, 125, 125);

QSettings* Global::settings = 0;
bool Global::Init = false;

void Global::initialize()
{
    if(Global::Init) return;

    QCoreApplication* app = QApplication::instance();

    QString strConfigFile = QFileInfo(app->applicationFilePath()).baseName() + ".ini";
    if(!QFile::exists(strConfigFile))
    {
        qFatal("配置文件不存在:\r\n%s", qPrintable(strConfigFile));
    }

    Global::Awesome = new QtAwesome();
    Global::Awesome->initFontAwesome();

    Global::settings = new QSettings(strConfigFile, QSettings::IniFormat);
    settings->setIniCodec("UTF8");

    Global::Database = Global::settings->value("MYSQL/databasename", Global::Database).toString();
    Global::Hostname = Global::settings->value("MYSQL/hostname", Global::Hostname).toString();
    Global::Username = Global::settings->value("MYSQL/username", Global::Username).toString();
    Global::Passwd   = Global::settings->value("MYSQL/passwd", Global::Passwd).toString();

    Global::PathImage = Global::settings->value("IMAGE/pathImage",Global::PathImage).toString();
    Global::PathMask = Global::settings->value("IMAGE/pathMask", Global::PathMask).toString();
    Global::PathResult = Global::settings->value("IMAGE/pathResult", Global::PathResult).toString();

    QDir dirMask(Global::PathMask);
    QDir dirResult(Global::PathResult);
    if(!dirMask.exists()) dirMask.mkdir(Global::PathMask);
    if(!dirResult.exists()) dirResult.mkdir(Global::PathResult);

    Global::ExtMask = Global::settings->value("IMAGE/extMask", Global::ExtMask).toString();
    Global::ExtResult = Global::settings->value("IMAGE/extResult", Global::ExtResult).toString();

    Global::Init = true;
}

bool Global::createConnection(QSqlDatabase &db)
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName(Global::Hostname);
    db.setDatabaseName(Global::Database);
    db.setUserName(Global::Username);
    db.setPassword(Global::Passwd);

    if(!db.open())
    {
        return false;
    }

    return true;
}

