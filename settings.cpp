#include "settings.h"
#include <QSettings>
#include <QHash>
#include <QDebug>

settings::settings()
{

}

QHash<QString, bool> settings::Load() {
    QHash<QString, bool> hashSettings;

    QSettings mySettings("EnPause", "LogParser");;
    mySettings.beginGroup("Actions");

//    qDebug() << "In LOAD : before processing : " <<  mySettings.value("action_err404");

    hashSettings["action_err404"] =     mySettings.value("action_err404").toBool();
    hashSettings["action_googlebot"] =  mySettings.value("action_googlebot").toBool();
    hashSettings["action_allbots"] =    mySettings.value("action_allbots").toBool();

    mySettings.endGroup();
//    qDebug() << "loaded settings // 404 : " << hashSettings["action_err404"];

    return hashSettings;
}

void settings::Save(QHash<QString, bool> toSave) {

//    QString val;
//    if (toSave.value("action_err404") == true) {
//        qDebug() << "OK true";
//        val = "true";
//    } else {
//        qDebug() << "KO false";
//        val = "false";
//    }

//    qDebug() << "Saved 404 : " << toSave.value("action_err404");

    QSettings settings("EnPause", "LogParser");
    settings.beginGroup("Actions");
    settings.setValue("action_err404",      toSave.value("action_err404"));
    settings.setValue("action_googlebot",   toSave.value("action_googlebot"));
    settings.setValue("action_allbots",     toSave.value("action_allbots"));
    settings.endGroup();
}
