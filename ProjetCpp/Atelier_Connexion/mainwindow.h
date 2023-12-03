#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"colis.h"
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QPushButton>
#include"clients.h"
#include"mainclients.h"
#include"arduino.h"
#include<QVariant>
#include<QtCore>
#include<QtGui>
#include<QtQuick>
#include <QVariant>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B_ajouter_clicked();



    void on_supp_clicked();

//    void on_mod_clicked();

    void on_aff_clicked();

    void on_tri_clicked();

    void on_Rech_clicked();

    void on_mod1_clicked();

    void on_tri_p_clicked();

    void on_tri_volume_clicked();

    void on_tri_b_clicked();

    void on_Rech_3_textChanged(const QString &arg1);

    void on_pdf_clicked();

    void on_stat_clicked();

    void on_stat_2_clicked();

    void on_stat_3_clicked();

    void on_location_clicked();

    void on_add_clicked();

    void on_location_3_clicked();

void afficherPosition(QString latitude, QString longitude);
void afficherInformations(QString adresse, QString coordonnee);


void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_pushButton_3_clicked();

void on_pushButton_4_clicked();
 void update_label();
 void on_tmp_clicked();

 void on_aff_tmp_clicked();

 void on_B_ajouter_2_clicked();

 void on_clients_clicked();

 void on_ajout_clients_clicked();

 void on_pb_Update_clicked();

 void on_x_chercher_textChanged(const QString &arg1);

 void on_comboBox_tri_zii_activated(const QString &arg1);

 void on_pb_pdf_clicked();

 void on_pb_supprimer_clicked();

 void on_statistique_tabBarClicked(int index);
     void update_Clients_StatisticsChart();

         void clearClients_StatisticsChart();
private:
    Ui::MainWindow *ui;
    Colis Ctmp;
    QByteArray data;
    Arduino A;
     QChartView *ClientsStatisticsChartView;
 signals:
   void setCenterPosition(QVariant,QVariant);
    void setLocationMarking(QVariant,QVariant);
};


#endif // MAINWINDOW_H
