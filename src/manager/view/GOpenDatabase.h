#ifndef _GOpenDatabase_
#define _GOpenDatabase_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GOpenDatabase;
}

class GOpenDatabase : public QFrame {
    Q_OBJECT

public:
    GOpenDatabase(QWidget* parent = 0);
    ~GOpenDatabase();

private:
    void createObjects();
    void createConnexions();

private:
    void setFieldVisible(const bool& data);

public slots:
    void slotDbmsChanged(const QString& data);
    void slotOpenDatabase();

private:
    Ui::GOpenDatabase* ui;
};

#endif
