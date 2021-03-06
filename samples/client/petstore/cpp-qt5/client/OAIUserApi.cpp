/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "OAIUserApi.h"
#include "OAIHelpers.h"
#include "OAIModelFactory.h"
#include "OAIQObjectWrapper.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace OpenAPI {

OAIUserApi::OAIUserApi() {}

OAIUserApi::~OAIUserApi() {}

OAIUserApi::OAIUserApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
OAIUserApi::createUser(OAIUser& oai_user) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user");



    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "POST");


    
    QString output = oai_user.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::createUserCallback);

    worker->execute(&input);
}

void
OAIUserApi::createUserCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit createUserSignal();
    } else {
        emit createUserSignalE(error_type, error_str);
        emit createUserSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::createUsersWithArrayInput(QList<OAIUser*>*& oai_user) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/createWithArray");



    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "POST");


    QJsonObject oai_user_jobj;
    toJsonArray((QList<void*>*)oai_user, oai_user_jobj, QString("body"), QString("OAIUser*"));

    QJsonDocument doc(oai_user_jobj);
    QByteArray bytes = doc.toJson();

    input.request_body.append(bytes);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::createUsersWithArrayInputCallback);

    worker->execute(&input);
}

void
OAIUserApi::createUsersWithArrayInputCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit createUsersWithArrayInputSignal();
    } else {
        emit createUsersWithArrayInputSignalE(error_type, error_str);
        emit createUsersWithArrayInputSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::createUsersWithListInput(QList<OAIUser*>*& oai_user) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/createWithList");



    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "POST");


    QJsonObject oai_user_jobj;
    toJsonArray((QList<void*>*)oai_user, oai_user_jobj, QString("body"), QString("OAIUser*"));

    QJsonDocument doc(oai_user_jobj);
    QByteArray bytes = doc.toJson();

    input.request_body.append(bytes);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::createUsersWithListInputCallback);

    worker->execute(&input);
}

void
OAIUserApi::createUsersWithListInputCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit createUsersWithListInputSignal();
    } else {
        emit createUsersWithListInputSignalE(error_type, error_str);
        emit createUsersWithListInputSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::deleteUser(QString* username) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/{username}");

    QString usernamePathParam("{"); usernamePathParam.append("username").append("}");
    fullPath.replace(usernamePathParam, stringValue(username));


    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "DELETE");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::deleteUserCallback);

    worker->execute(&input);
}

void
OAIUserApi::deleteUserCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit deleteUserSignal();
    } else {
        emit deleteUserSignalE(error_type, error_str);
        emit deleteUserSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::getUserByName(QString* username) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/{username}");

    QString usernamePathParam("{"); usernamePathParam.append("username").append("}");
    fullPath.replace(usernamePathParam, stringValue(username));


    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::getUserByNameCallback);

    worker->execute(&input);
}

void
OAIUserApi::getUserByNameCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    QString json(worker->response);
    OAIUser* output = static_cast<OAIUser*>(create(json, QString("OAIUser")));
    auto wrapper = new OAIQObjectWrapper<OAIUser*> (output);
    wrapper->deleteLater();
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit getUserByNameSignal(output);
    } else {
        emit getUserByNameSignalE(output, error_type, error_str);
        emit getUserByNameSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::loginUser(QString* username, QString* password) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/login");


    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("username"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(username)));

    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("password"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(password)));


    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::loginUserCallback);

    worker->execute(&input);
}

void
OAIUserApi::loginUserCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    QString json(worker->response);
    QString* output = static_cast<QString*>(create(json, QString("QString")));
    auto wrapper = new OAIQObjectWrapper<QString*> (output);
    wrapper->deleteLater();
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit loginUserSignal(output);
    } else {
        emit loginUserSignalE(output, error_type, error_str);
        emit loginUserSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::logoutUser() {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/logout");



    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "GET");





    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::logoutUserCallback);

    worker->execute(&input);
}

void
OAIUserApi::logoutUserCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit logoutUserSignal();
    } else {
        emit logoutUserSignalE(error_type, error_str);
        emit logoutUserSignalEFull(worker, error_type, error_str);
    }
}

void
OAIUserApi::updateUser(QString* username, OAIUser& oai_user) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/user/{username}");

    QString usernamePathParam("{"); usernamePathParam.append("username").append("}");
    fullPath.replace(usernamePathParam, stringValue(username));


    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    OAIHttpRequestInput input(fullPath, "PUT");


    
    QString output = oai_user.asJson();
    input.request_body.append(output);
    


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIUserApi::updateUserCallback);

    worker->execute(&input);
}

void
OAIUserApi::updateUserCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit updateUserSignal();
    } else {
        emit updateUserSignalE(error_type, error_str);
        emit updateUserSignalEFull(worker, error_type, error_str);
    }
}


}
