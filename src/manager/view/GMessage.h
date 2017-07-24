#ifndef _GMessage_
#define _GMessage_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GMessage;
}

class GMessage : public QFrame {
    Q_OBJECT

public:
    GMessage(QWidget* parent = 0);
    ~GMessage();

private:
    void createObjects();
    void createConnexions();

public:
    void showMessage(const QString& message);
    void showMessage(const QString& message, const int& msec);
    void showError(const QString& message);
    void showError(const QString& message, const int& msec);

private:
    Ui::GMessage* ui;
};

#endif
