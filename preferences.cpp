#include "preferences.h"
#include "ui_preferences.h"
#include <QSettings>
#include <QDebug>

#include <settings.h>

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);

    settings mySettings;
    QHash<QString, bool> appSettings = mySettings.Load();

    ui->checkBox_err404->setChecked(appSettings.value("action_err404"));
    ui->checkBox_GBot->setChecked(appSettings.value("action_googlebot"));
    ui->checkBox_Bots->setChecked(appSettings.value("action_allbots"));

    ui->checkBox_Bots->setDisabled(true);
}

Preferences::~Preferences()
{
    delete ui;
}

void Preferences::on_pushButton_closePrefs_clicked()
{
    this->hide();
}

void Preferences::on_pushButton_savePreferences_clicked()
{
    settings mySettings;
    QHash<QString, bool> toSave;
    toSave["action_err404"] = ui->checkBox_err404->isChecked();
    toSave["action_googlebot"] = ui->checkBox_GBot->isChecked();
    toSave["action_allbots"] = ui->checkBox_Bots->isChecked();

    mySettings.Save(toSave);
    this->hide();
}

