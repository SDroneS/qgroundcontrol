#ifndef SDSCONTROLLER_H
#define SDSCONTROLLER_H

#include <QMessageBox>
#include <QThread>
#include <fstream>
#include <QTextStream>
#include "QFile"

class MyWorker : public QThread
{
    Q_OBJECT

public:
    void    run(void)   final;

signals:
    void    showMyMsg   (QString myMsg);
    void    loadWPTs    (QString workerPathToWPTsFile);
    void    workerResult(bool myReturn);

private:
    QString             _data;
    QString             _data_out;
    QString             _myPathToFlagFile;
    QString             _myPathToWPTsFile;
};

#endif // SDSCONTROLLER_H
