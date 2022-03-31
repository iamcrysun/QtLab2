#ifndef RUNLINE_H
#define RUNLINE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>

class RunLine: public QLabel {
    Q_OBJECT
  public:
    RunLine(QWidget *parent = 0);
  public slots:
    void setString(const QString string);
    void setSpeed(const int speed);
  protected:
    virtual void timerEvent(QTimerEvent*);

    int m_shift, m_timerId;
    QString m_string;
  };

  #endif // RUNLINE_H
