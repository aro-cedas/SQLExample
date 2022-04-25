#ifndef MONITORINGDATASETCONTROLLER_H
#define MONITORINGDATASETCONTROLLER_H

#include <QObject>
#include "httprequest.h"
#include "httpresponse.h"
#include "httprequesthandler.h"
#include "dbconnection.h"
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace cedaspro;

class MonitoringDataSetController : public HttpRequestHandler
{
    Q_OBJECT
        Q_DISABLE_COPY(MonitoringDataSetController)
        public:
                 MonitoringDataSetController();
    void service(HttpRequest& request, HttpResponse& response);

private:
    DBConnection *conn;
    QSqlDatabase *db;
    QString getMonitoringListByContextID = "SELECT MDS.ID, MDS.MonitoringStartedUTC, "
                                           "MonitoringStoppedUTC, "
                                           "HDS.Name as HistoricalDataSetName,"
                                           "(select convert(varchar, MonitoringStoppedUTC - MonitoringStartedUTC, 108)) as Duration "
                                           "FROM MonitoringDataSet MDS "
                                           "INNER JOIN HistoricalDataSet HDS ON HDS.ID = MDS.HistoricalDataSetID "
                                           "INNER JOIN Context C ON C.ID = HDS.ContextID "
                                           "WHERE C.ID =";
    QString endedAndOrdered = "AND MDS.HasEnded = 1 ORDER BY MDS.ID DESC";
};

#endif // MONITORINGDATASETCONTROLLER_H
