#ifndef SUMMARYVIEWPAGE_H
#define SUMMARYVIEWPAGE_H

#include <QWidget>
#include <QModelIndex>
#include <QMap>

class SetupWidget;

namespace Ui {
class SummaryViewPage;
}

class SummaryViewPage : public QWidget
{
    Q_OBJECT

public:
    explicit SummaryViewPage(SetupWidget *calWidget, QWidget *parent = 0);
    ~SummaryViewPage();

signals:
    void showPanel(QString compName);

public slots:
    void _setupCompleteChange(bool setupComplete);
    void _setupCompleteStatus(QStringList incomplete);
    void _showPanel(QModelIndex);

private:
    Ui::SummaryViewPage *ui;
    const QString setupCompleteText = "Below you'll find a summary of the settings for your vehicle."
                                      "To the left are the setup menus for each component";
    const QString needSetupText = "WARNING: Your vehicle requires setup prior to flight.Please resolve"
                                  " the items marked in red using the menu on the left.";

    QStringList _incompleteComps;
    QMap<QString,QString> _components;
};

#endif // SUMMARYVIEWPAGE_H
