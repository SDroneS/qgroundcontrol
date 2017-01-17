#include "SDSController.h"

void MyWorker::run(void)
{
    // Setting Flag File path
    _myPathToFlagFile = "/home/kasper/Repos/SDS_Flag.cfg";
    QFile _myFile(_myPathToFlagFile);
    if(!_myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       emit showMyMsg(tr("Cannot open the SDS flag file!"));
       emit workerResult(false);
        return;
    }

    // Setting Flight Paln File path
    _myPathToWPTsFile = "/home/kasper/Repos/PathPlanWaypoints.txt";
    QFile _myWPTsFile(_myPathToWPTsFile);

    // Default value for flag file which is set after flag reading
    _data_out = "0";

    QTextStream in(&_myFile);
    QTextStream out(&_myFile);

    // Reading SDS flag file thread loop
    while (true)       //(!in.atEnd())
    {
       // While Flag value is set to 1
       if(in.readLine(1) == "1")
       {
           // While WPTs file doesn't exist
           if(!_myWPTsFile.exists())
           {
                emit showMyMsg(tr("Cannot open the SDS WPTs file!"));
                emit workerResult(false);
                 return;
           }

           // Setting SDS flag file value to default
           _myFile.resize(0);
           out << _data_out;

           // Loading the SDS WPTs file to autopilot
           emit loadWPTs(_myPathToWPTsFile);
       }
       usleep(100000);
    }
}
