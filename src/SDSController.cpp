#include "SDSController.h"

SDSController::SDSController(void)
{
    //MyWorker* workerThread = new MyWorker();
    ///workerThread = new MyWorker();
    //connect(&_worker, &MyWorker::error, this, &SDSController::_workerError);
    ///workerThread->start();
}

SDSController::~SDSController(void)
{

}

void SDSController::_workerError(QString errorMessage)
{
    _errorMessage = errorMessage;
}

void MyWorker::run(void)
{
    //Setting Flag File Path
    _myPathToFlagFile = "/home/kasper/Repos/SDS_Flag.cfg";
    QFile _myFile(_myPathToFlagFile);
    *_data_out = '0';

    while (true)
    {
       // Reading Flag File
       if(_myFile.canReadLine())
       {
          _myFile.readLine(_data, 2);

          // While Flag value is set to 1
          if(*_data == '1')
          {
              SDS_GLOBAL_CLASS::sds_flag = true;
              _myFile.write(_data_out);
          }
       }
       else
       {
          emit error(tr("Cannot read the SDS flag file!"));
           return;
       }
    }
}
