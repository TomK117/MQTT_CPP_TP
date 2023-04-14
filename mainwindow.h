// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtMqtt/QMqttClient>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setClientPort(int p);

private slots:
    void OnButtonConnectClicked();
    void OnButtonQuitClicked();
    void updateLogStateChange();

    void brokerDisconnected();

    void OnButtonPublishClicked();

    void OnButtonSubscribeClicked();

private:
    Ui::MainWindow *ui;
    QMqttClient *m_client;
};

#endif // MAINWINDOW_H
