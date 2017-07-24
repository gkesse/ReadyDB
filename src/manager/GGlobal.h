#ifndef _GGlobal_
#define _GGlobal_

#include "GTypeDef.h"
#include <QObject>
#include <QFormLayout>
#include <QWidget>
#include <QLabel>
#include <QToolButton>

class GGlobal : public QObject {
    Q_OBJECT

private:
    GGlobal();

public:
    ~GGlobal();

public:
    static GGlobal* Instance();

private:
    void createObjects();
    void createConnexions();

public:
    void hide(QWidget* widget);
    void setVisible(QFormLayout* form, QWidget* field, const bool& data);
    void showMessage(QWidget* widget, QToolButton* icon, QLabel* label, const QString& message);
    void showError(QWidget* widget, QToolButton* icon, QLabel* label, const QString& message);
    QStringList getList(const GArrayMap& data, const QString& key);

private:
    static GGlobal* m_instance;
};

#endif
