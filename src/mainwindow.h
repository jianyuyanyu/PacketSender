/*
 * This file is part of Packet Sender
 *
 * Licensed GPL v2
 * http://PacketSender.com/
 *
 * Copyright NagleCode, LLC
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QSettings>
#include <QModelIndex>
#include <QTimer>
#include <QItemSelection>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QListWidget>
#include <QSortFilterProxyModel>
#include "globals.h"
#include "packet.h"
#include "packetnetwork.h"
#include "threadedtcpserver.h"
#include "multicastsetup.h"
#include "packetlogmodel.h"


namespace Ui
{
class MainWindow;
}

class PreviewFilter : public QObject
{
    Q_OBJECT

public:


    explicit PreviewFilter(QObject * parent, QLineEdit * asciiEdit, QLineEdit * hexEdit)
        : QObject{parent}, asciiEdit{asciiEdit}, hexEdit{hexEdit}
    {
        addTo(parent);
    }

    void addTo(QObject * obj)
    {
        if (obj)
        {
            obj->installEventFilter(this);
        }
    }

signals:
    void asciiUpdated();
    void hexUpdated();

private:
    bool eventFilter(QObject *watched, QEvent *event);
    QLineEdit * asciiEdit;
    QLineEdit * hexEdit;
};

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        PacketNetwork packetNetwork;
        QString ASCIITohex(QString &ascii);
        QString hexToASCII(QString &hex);
        void loadPacketsTable();       
        QPushButton *generatePSLink();
        QPushButton *generateDNLink();
        void populateTableRow(int rowCounter, Packet tempPacket);
        void removePacketfromMemory(Packet thepacket);
        void DTLSServerStatus();
        void UDPServerStatus();
        void TCPServerStatus();
        int findColumnIndex(QListWidget *lw, QString search);
        void packetTable_checkMultiSelected();
        void generateConnectionMenu();
        void updateManager(QByteArray response);

        QComboBox* cipherCb;
        static int isSessionOpen;

    signals:
        void sendPacket(Packet sendpacket);

    public slots:
        void on_hostName_editingFinished();
        //void on_twoVerify_StateChanged();
        void on_sendSimpleAck_StateChanged();
        void on_leaveSessionOpen_StateChanged();
        void toTrafficLog(Packet logPacket);
        void cancelResends();
        void applyNetworkSettings();
        void toggleDTLSServer();
        void toggleUDPServer();
        void toggleTCPServer();
        void toggleSSLServer();
        void SSLServerStatus();

        //shortcut keys... would be better if used lambda
        void poodlepic();
        void puppypic();
        void shortcutkey1();
        void shortcutkey2();
        void shortcutkey3();
        void shortcutkey4();
        void shortcutkey5();
        void shortcutkey6();
        void shortcutkey7();


    private slots:
        void on_packetHexEdit_lostFocus();
        void on_packetASCIIEdit_lostFocus();
        void on_requestPathEdit_lostFocus();

        void sendClick(QString packetName);

        void statusBarMessage(const QString & msg, int timeout, bool override);

        void on_savePacketButton_clicked();

        void on_testPacketButton_clicked();

        void on_deletePacketButton_clicked();

        void on_packetIPEdit_lostFocus();

        void on_packetPortEdit_lostFocus();

        void httpFinished(QNetworkReply* pReply);

        void on_packetsTable_itemChanged(QTableWidgetItem *item);

        void on_packetsTable_itemClicked(QTableWidgetItem *item);
        void refreshTimerTimeout();
        void slowRefreshTimerTimeout();

        void on_trafficLogClearButton_clicked();

        void on_saveTrafficPacket_clicked();


        void on_packetASCIIEdit_editingFinished();

        void on_packetHexEdit_editingFinished();

        void on_packetASCIIEdit_textEdited(const QString &arg1);

        void on_packetIPEdit_editingFinished();

        void on_searchLineEdit_textEdited(const QString &arg1);


        void on_toClipboardButton_clicked();

        void on_packetsTable_itemSelectionChanged();

        void on_bugsLinkButton_clicked();

        void on_forumsPacketSenderButton_clicked();

        void on_saveLogButton_clicked();

        void on_actionAbout_triggered();

        void on_actionAndroid_App_triggered();
        void on_actioniOS_App_triggered();
        void on_actionForums_triggered();
        void on_actionFollow_NagleCode_triggered();
        void on_actionConnect_on_LinkedIn_triggered();

        void toggleIPv4_IPv6();



        void on_actionJoin_IPv4_triggered(QString address = "");

        void on_actionHelp_triggered();

        void on_actionSettings_triggered();

        void on_actionExit_triggered();

        void on_actionImport_Packets_triggered();
        void on_actionExport_Packets_triggered();

        void on_actionImport_Packets_JSON_triggered();
        void on_actionExport_Packets_JSON_triggered();


        void on_actionCloud_triggered();


        void on_persistentTCPCheck_clicked(bool checked);


        void on_actionSubnet_Calculator_triggered();

        void on_actionIntense_Traffic_Generator_triggered();

        void on_resendEdit_editingFinished();

        void on_loadFileButton_clicked();


        void on_actionDonate_Thank_You_triggered();


        void on_udptcpComboBox_currentIndexChanged(const QString &arg1);

        void on_cipherCb_currentIndexChanged();

        void on_requestPathEdit_editingFinished();

        void on_genPostDataButton_clicked();

        void on_generatePanelButton_clicked();

        void on_actionPanel_Generator_triggered();

        void on_actionNew_Panel_triggered();

        void on_testPacketButton_pressed();

        void on_udptcpComboBox_currentIndexChanged(int index);

        void on_actionWake_On_LAN_Magic_Packet_triggered();

    private:
        Ui::MainWindow *ui;
        QSortFilterProxyModel *proxyModel;
        PacketLogModel packetsLogged;
        QList<Packet> packetsSaved;
        QList<Packet> packetsRepeat;
        int stopResending;
        QNetworkAccessManager  * http;
        QTimer refreshTimer;
        QTimer slowRefreshTimer;
        bool tableActive;
        QPushButton * dtlsServerStatus;
        QPushButton * udpServerStatus;
        QPushButton * tcpServerStatus;
        QPushButton * sslServerStatus;
        QPushButton * stopResendingButton;
        QPushButton * IPmodeButton;
        PreviewFilter* asciiPreviewFilter;
        PreviewFilter* hexPreviewFilter;        

        QStringList packetTableHeaders;
        QStringList packetSavedTableHeaders;

        Packet lastSendPacket;

        bool darkMode;

        int maxLogSize;

        float multiSendDelay;
        int cancelResendNum;
        int resendCounter;

        void setIPMode();
        void saveSession(Packet sessionPacket);

        void packetsImported(QList<Packet> packetSet);
};

#endif // MAINWINDOW_H
