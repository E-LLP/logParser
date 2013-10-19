#include "settings.h"
#include <QSettings>
#include <QHash>

settings::settings()
{

}

QHash<QString, bool> settings::Load() {
    QHash<QString, bool> hashSettings;

    QSettings mySettings("EnPause", "LogParser");;
    mySettings.beginGroup("Actions");
    hashSettings["action_err404"] =     mySettings.value("action_err404").toBool();
    hashSettings["action_googlebot"] =  mySettings.value("action_googlebot").toBool();
    hashSettings["action_allbots"] =    mySettings.value("action_allbots").toBool();
    mySettings.endGroup();

    return hashSettings;
}

void settings::Save(QHash<QString, bool> toSave) {
    QSettings settings("EnPause", "LogParser");
    settings.beginGroup("Actions");
    settings.setValue("action_err404",      toSave.value("action_err404"));
    settings.setValue("action_googlebot",   toSave.value("action_googlebot"));
    settings.setValue("action_allbots",     toSave.value("action_allbots"));
    settings.endGroup();
}
