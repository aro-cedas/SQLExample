#include <QCoreApplication>
#include "requestmapper.h"
#include "global.h"
#include "controllers/monitoringdatasetcontroller.h"

RequestMapper::RequestMapper(QObject *parent) :HttpRequestHandler(parent)
{
    qInfo( "Request mapper created");
}
RequestMapper::~RequestMapper()
{
    qInfo( "Request mapper deleted");
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();
    qInfo("Request mapper path =%s", path.data());

    if(path.startsWith("/MonitoringDataSets"))
    {
        MonitoringDataSetController().service(request, response);
    }
}
