#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include <httprequesthandler.h>

using namespace cedaspro;

class RequestMapper : public HttpRequestHandler{
    Q_OBJECT
        Q_DISABLE_COPY(RequestMapper)
        public:
                 RequestMapper(QObject* parent=0);

    ~RequestMapper();

    void service(HttpRequest& request, HttpResponse& response);

};

#endif // REQUESTMAPPER_H
