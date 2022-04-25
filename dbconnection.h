#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QSqlDatabase>

class DBConnection : public QObject
{
    Q_OBJECT
        public:
                 DBConnection();
    ~DBConnection();
    void initDB();
    void closeDB();
    QSqlDatabase db;
    QSqlDatabase *getDB();
private:
    QString randomString();
    const QString connectionString = "DRIVER={SQL Server};SERVER=192.168.17.201;Database=HDCAdev1;UID=sa;Pwd=ZoHv3mUoJMKDV5MBaAmC"; //windows with main DB
//    const QString connectionStringLinux = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=172.16.100.67;Database=HDCAdev1_ARO;UID=aleks;Pwd=cedas2020"; //linux with test DB
//    const QString defaultDBConnectionString = "Provider=MSDASQL;Initial Catalog=HDCA;DSN=192.168.16.101;Database=HDCAdev1;UID=sa;Pwd=ZoHv3mUoJMKDV5MBaAmC"; // from main server (not working)

signals:

};

#endif // DBCONNECTION_H
