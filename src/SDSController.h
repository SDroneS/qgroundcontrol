#ifndef SDSCONTROLLER_H
#define SDSCONTROLLER_H

#include <QThread>

#include "SDS_global_class.h"

#include <fstream>
#include "QFile"

class MyWorker : public QThread
{
    Q_OBJECT

public:
    //MyWorker(void);

    void    run(void)   final;

signals:
    void    error       (QString errorMsg);

private:
    char*               _data;
    char*               _data_out;
    //QFile               _myFile;
    QString             _myPathToFlagFile;
};

// Controller for our thread for flag reading
class SDSController : public QObject
{
    Q_OBJECT

public:
    SDSController(void);
    ~SDSController();
    MyWorker* workerThread;

private:
    MyWorker            _worker;
    QString             _errorMessage;

private slots:
    void _workerError(QString errorMsg);
};

#endif // SDSCONTROLLER_H
