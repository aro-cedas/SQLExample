#include "dbconnection.h"
#include <QDebug>
#include <QSqlError>
#include <QRandomGenerator>

DBConnection::DBConnection()
{

}

DBConnection::~DBConnection()
{
    db.~QSqlDatabase();
}

void DBConnection::initDB()
{
    db = QSqlDatabase::addDatabase("QODBC3", randomString());
    db.setDatabaseName(connectionString);
    qDebug() << "connection"<<db.connectionName() << " in use";
}

void DBConnection::closeDB()
{
    qDebug() << "closing connection: " << db.connectionName();

    db.close();
    //    db = QSqlDatabase();
    db.removeDatabase(db.connectionName());
    qDebug() << db.connectionNames();
}

QSqlDatabase* DBConnection::getDB()
{
    return &db;
}

QString DBConnection::randomString()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 24;

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = QRandomGenerator::global()->generate() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}
