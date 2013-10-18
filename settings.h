#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QHash>

class settings
{
public:
    settings();

    QHash<QString, bool> Load();
    void Save(QHash<QString, bool>);
};

#endif // SETTINGS_H
