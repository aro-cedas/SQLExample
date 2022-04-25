#include "monitoringdatasetcontroller.h"
#include "httpsessionstore.h"
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlRecord>

MonitoringDataSetController::MonitoringDataSetController()
{
    conn = new DBConnection;
    db = conn->getDB();
}

void MonitoringDataSetController::service(HttpRequest &request, HttpResponse &response)
{
    response.setHeader("Content-Type", "application/json");
    if (request.getMethod() == "GET" && request.getParameterMap().contains("contextId"))
    {
        qDebug() << "GET ALL-------------";

        if(!db->isValid())
        {
            conn->initDB();
            if(db->isValid())
            {
                db->open();
                QMultiMap<QByteArray, QByteArray> params = request.getParameterMap();
                if(db->isOpen()) {
                    QJsonDocument json;
                    QJsonArray recordsArray;
                    QSqlQuery query(*db);
                    query.prepare(getMonitoringListByContextID + params.value("contextId") + endedAndOrdered);
                    qDebug() <<query.exec();
                    while(query.next())
                    {
                        QJsonObject recordObject;
                        for(int i=0; i < query.record().count(); i++)
                        {
                            recordObject.insert(query.record().fieldName(i),QJsonValue::fromVariant(query.value(i)));
                        }
                        recordsArray.push_back(recordObject);
                    }
                    query.finish();
                    json.setArray(recordsArray);
                    response.setStatus(200);
                    response.write(json.toJson());
                }else{
                    response.write(db->lastError().text().toLatin1());
                    response.setStatus(500);
                }
            }
        }
        conn->closeDB();
    }
    else{
        response.setStatus(500);
        response.write("Method not allowed");
    }
}
