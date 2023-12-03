#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"colis.h"
#include"QString"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlQueryModel>
#include <iostream>
#include<QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QWidget>
#include<QPrinter>
#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QtSql>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QItemDelegate>
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QPushButton>
#include <QMovie>
#include"location.h"
#include"arduino.h"
#include <QTimer>
#include "clients.h"
#include "mainclients.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
setWindowTitle("New Window Title");

   /* emit setCenterPosition( 36.8065,10.1815);
     emit setLocationMarking( 36.8065,10.1815);*/
     QIcon icon("C:/Users/zied/Desktop/ProjetCpp/delete-icon.png");
      QIcon iconPdf("C:/Users/zied/Desktop/ProjetCpp/PDF-icon.png"); // Replace with the actual path to your icon file
 QMovie *image =new QMovie("C:/Users/zied/Desktop/ProjetCpp/PDF-icon.png/rendez_vous.gif");
   ui->image->setMovie(image);
    ui->stat->setIcon(icon);




 //ui->DE->setIcon(icon);
 ui->pdf->setIcon(iconPdf);
    ui->tab_c->setModel(Ctmp.afficher());
    Colis colis;

   // *************ARDUINO**********************

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
//***************************************************

     QString button1_style=
             "QPushButton {"
                "    background-color: #3498db;"  // Background color
                "    color: #ffffff;"              // Text color
                "    padding: 5px 10px;"           // Padding around text
                "    font-size: 20px;"             // Font size
                "    border: 1px solid #2980b9;"   // Border color
                "    border-radius: 5px;"          // Border radius for rounded corners
                "}"
                ""
                "QPushButton:hover {"
                "    background-color: #2980b9;"  // Background color on hover
                "    border: 1px solid #3498db;"   // Border color on hover
                "}"
                ""
                "QPushButton:pressed {"
                "    background-color: #1f618d;"  // Background color when pressed
                "    border: 1px solid #2980b9;"   // Border color when pressed
                "}";

     QString button2_style="QPushButton {"
                           "    background-color: #7D0000;"       // New background color
                           "    color: #ffffff;"                  // Text color
                           "    padding: 5px 10px;"
                           "    font-size: 20px;"
                           "    border: 1px solid #7D0000;"       // New border color
                           "    border-radius: 5px;"
                           "}"
                           ""
                           "QPushButton:hover {"
                           "    background-color: #590000;"       // New background color on hover
                           "    border: 1px solid #590000;"       // New border color on hover
                           "}"
                           ""
                           "QPushButton:pressed {"
                           "    background-color: #400000;"       // New background color when pressed
                           "    border: 1px solid #400000;"       // New border color when pressed
                           "}";
;
      ui->centralWidget->setStyleSheet(
         "QMainWindow {"
         "    background-color: #fc7d7d;"
         "}"
         ""
         "QWidget#centralWidget {"
         "    background-color: #f0f0f0;"
         "}"
     );

      QString button3_style="QPushButton {"
                            "    background-color: #E7A391;"       // New background color
                            "    color: #ffffff;"                  // Text color
                            "    padding: 5px 10px;"
                            "    font-size: 20px;"
                            "    border: 1px solid #E7A391;"       // New border color
                            "    border-radius: 5px;"
                            "}"
                            ""
                            "QPushButton:hover {"
                            "    background-color: #CC876F;"       // New background color on hover
                            "    border: 1px solid #CC876F;"       // New border color on hover
                            "}"
                            ""
                            "QPushButton:pressed {"
                            "    background-color: #B37259;"       // New background color when pressed
                            "    border: 1px solid #B37259;"       // New border color when pressed
                            "}";
;



     //combobox style
     QString combobox_style= "QComboBox {"
                             "    background-color: #ecf0f1;"  // Background color
                             "    color: #2c3e50;"              // Text color
                             "    border: 1px solid #bdc3c7;"   // Border color
                             "    border-radius: 5px;"          // Border radius for rounded corners
                             "    padding: 3px 8px;"            // Padding around text
                             "    selection-background-color: #3498db;"  // Background color when an item is selected
                             "}"
                             ""
                             "QComboBox::drop-down {"
                             "    border: none;"  // Remove the default drop-down arrow
                             "}"
                             ""
                             "QComboBox::down-arrow {"
                             "    image: url(:/path/to/down_arrow.png);"  // Replace with your own image for the drop-down arrow
                             "}";
//lineEdit style
     QString lineEdit_style= "QLineEdit {"
                             "    background-color: #ecf0f1;"
                             "    border: 1px solid #bdc3c7;"
                             "    padding: 5px;"
                             "    color: #2c3e50;"
                             "    border-radius: 10px;"
                             "}"
                             ""
                             "QLineEdit:hover {"
                             "    border: 1px solid #7f8c8d;"
                             "}"
                             ""
                             "QLineEdit:focus {"
                             "    border: 2px solid #3498db;"
                             "}"
                         ;

 //group box style
      QString group_box_style= "QGroupBox {"
                               "    border: 2px solid #3498db;"  // Border color and width
                               "    border-radius: 5px;"          // Border radius for rounded corners
                               "    margin-top: 10px;"            // Top margin
                               "}"
                               ""
                               "QGroupBox::title {"
                               "    subcontrol-origin: margin;"   // Ensure the title is inside the border
                               "    subcontrol-position: top left;"  // Position the title at the top left
                               "    padding: 5px 10px;"            // Padding around the title
                               "    color: #ffffff;"               // Text color of the title
                               "    background-color: #3498db;"    // Background color of the title
                               "    border: 1px solid #3498db;"    // Border color of the title
                               "    border-top-left-radius: 4px;"  // Border radius for the top-left corner of the title
                               "    border-top-right-radius: 4px;" // Border radius for the top-right corner of the title
                               "}";
       ui->le->setStyleSheet(lineEdit_style);
       ui->poids->setStyleSheet(lineEdit_style);
       ui->volume->setStyleSheet(lineEdit_style);
       //ui->etat->setStyleSheet(lineEdit_style);
       ui->pdf_bar->setStyleSheet(lineEdit_style);
       ui->Rech->setStyleSheet(lineEdit_style);
          ui->Rech_3->setStyleSheet(lineEdit_style);

          QString tabWidget_style ="QTabWidget::pane {"
                                   "    border: 1px solid #bdc3c7;" // Border color
                                   "}"
                                   ""
                                   "QTabBar::tab {"
                                   "    background-color: #3498db;" // Background color of tabs
                                   "    color: #ffffff;"            // Text color of tabs
                                   "      padding: 12px 18px;"
                                   " border-top-left-radius: 10px;"   // Set the radius for the top-left corner
                                           "    border-top-right-radius: 10px;"

                                           // Padding inside each tab
                                   "}"
                                   ""
                                   "QTabBar::tab:selected {"
                                   "    background-color: #2980b9;" // Background color of the selected tab
                                   "}"
                                   ""
                                   "QTabBar::tab:hover {"
                                   "    background-color: #2980b9;" // Background color when hovering over a tab
                                   "}" ;

   ui->widget_2->setStyleSheet(tabWidget_style);
     ui->client_tab->setStyleSheet(tabWidget_style);
       ui->tabWidget->setStyleSheet(tabWidget_style);
//**********************

       ui->pdf_label->setStyleSheet(
           "QLabel {"
           "    background-color: #ecf0f1;" // Background color
           "    color: #2c3e50;"
           "    padding: 12px 18px;"// Text color
                        // Padding around text
           "    border: 1px solid #bdc3c7;"  // Border color
           "    border-radius: 5px;"         // Border radius for rounded corners
           "}"
       );
//********************

      ui->combo_2->setStyleSheet(combobox_style);
          ui->combo_3->setStyleSheet(combobox_style);
        ui->combo_4->setStyleSheet(combobox_style);

        //***************
        ui->groupBox->setStyleSheet(group_box_style);
          ui->group_box_cliens->setStyleSheet(group_box_style);
              ui->groupBox_10->setStyleSheet(group_box_style);
              ui->groupBox_5->setStyleSheet(group_box_style);
    ui->groupBox_6->setStyleSheet(group_box_style);
        ui->groupBox_7->setStyleSheet(group_box_style);
            ui->groupBox_8->setStyleSheet(group_box_style);

         ui->stat->setStyleSheet(button1_style);
 ui->tri_b->setStyleSheet(button1_style);
  ui->aff->setStyleSheet(button1_style);
  ui->supp->setStyleSheet(button1_style);
  ui->supp->setStyleSheet(button1_style);
  ui->mod1->setStyleSheet(button1_style);
  ui->B_ajouter->setStyleSheet(button1_style);

  ui->B_ajouter_2->setStyleSheet(button2_style);
    ui->clients->setStyleSheet(button2_style);
          ui->commandes->setStyleSheet(button2_style);
      ui->vehicule->setStyleSheet(button2_style);
        ui->livreurs->setStyleSheet(button2_style);
  ui->tmp->setStyleSheet(button3_style);
QString tab_style= "QTableView {"
                   "    background-color: #ecf0f1;"  // Background color
                   "    border: 1px solid #bdc3c7;"   // Border color
                   "    gridline-color: #bdc3c7;"     // Color of gridlines
                   "}"
                   ""
                   "QHeaderView::section {"
                   "    background-color: #3498db;"  // Background color of header sections
                   "    color: #ffffff;"              // Text color of header sections
                   "    padding: 4px;"                // Padding in header sections
                   "    border: 1px solid #2980b9;"   // Border color of header sections
                   "}"
                   ""
                   "QTableView::item {"
                   "    padding: 5px;"                // Padding around table items
                   "    border-bottom: 1px solid #bdc3c7;"  // Border color at the bottom of each item

                   "}"
                   ""
                   "QTableView::item:selected {"
                   "    background-color: #3498db;"  // Background color of selected items
                   "    color: #ffffff;"
                            // Text color of selected items
                   "}";
QString tab_style1= "QTableView {"
                   "    background-color: #ecf0f1;"  // Background color
                   "    border: 1px solid   #bdc3c7;"   // Border color
                   "    gridline-color:   #bdc3c7;"     // Color of gridlines
                   "}"
                   ""
                   "QHeaderView::section {"
                   "    background-color: #E7A391;"  // Background color of header sections
                   "    color: #ffffff;"              // Text color of header sections
                   "    padding: 4px;"                // Padding in header sections
                   "    border: 1px solid  #bdc3c7;"   // Border color of header sections
                   "}"
                   ""
                   "QTableView::item {"
                   "    padding: 5px;"                // Padding around table items
                   "    border-bottom: 1px solid  rgba(189, 195, 199, 0);"  // Border color at the bottom of each item

                   "}"
                   ""
                   "QTableView::item:selected {"
                   "    background-color: #3498db;"  // Background color of selected items
                   "    color: #ffffff;"
                            // Text color of selected items
                   "}";
        ui->tab_ajout->setStyleSheet(tab_style);
  ui->tab_c->setStyleSheet(tab_style);
   ui->tab_c_2->setStyleSheet(tab_style1);
        ui->widget->setStyleSheet(
            "QWidget {"
            "    background-color: #ecf0f1;"  // Background color
            "    color: #2c3e50;"              // Text color
            "    padding: 10px;"               // Padding around content
            "    border: 1px solid #bdc3c7;"   // Border color
            "    border-radius: 5px;"          // Border radius for rounded corners
            "}"
        );
       ui-> listWidget->setStyleSheet(
            "QListWidget {"
            "    background-color: #ecf0f1;"  // Background color of the listWidget
            "    border: 1px solid #bdc3c7;"   // Border color
            "    padding: 5px;"                // Padding around the content
            "}"
            ""
            "QListWidget::item {"
            "    background-color: #3498db;"  // Background color of each item
            "    color: #ffffff;"              // Text color
            "    padding: 5px 10px;"           // Padding around text
            "    border-radius: 5px;"          // Border radius for rounded corners
            "}"
            ""
            "QListWidget::item:selected {"
            "    background-color: #2980b9;"  // Background color of selected item
            "}"
        );

       Clients C;



       //code client
       ui->le_IDC->setValidator(new QIntValidator(0,9999999,this));
       ui->tab_Clients->setModel(C.afficher());
}





MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_ajouter_clicked()
{



     int id;
     bool isInt;
     Location l;
     id=ui->le->text().toInt(&isInt);
     if (!isInt) {

         QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer for ID.");
         return;
     }
     float poids;
     bool isFloat;
     poids=ui->poids->text().toFloat(&isFloat);
     if (!isFloat) {

         QMessageBox::warning(this, "Invalid Input", "Please enter a valid float for Poids.");
         return;
     }

     float volume;
      volume=ui->volume->text().toFloat(&isFloat);
      if (!isFloat) {

          QMessageBox::warning(this, "Invalid Input", "Please enter a valid float for Volume.");
          return;
      }

      QString etat = ui->combo_etat->currentText();

      if (etat == "casse") {
           etat="casse";
          } else if (etat == "non casse") {
            etat="non casse";
         }

    Colis C(id,poids,volume,etat);

     bool test=C.ajouter();
     if(test)
     {
            ui->tab_c->setModel(C.afficher());

              ui->tab_ajout->setModel(C.afficher());

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("connection successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("connection failed.\n"

                                "Click Cancel to exit."), QMessageBox::Cancel);


bool test1=l.ajouter_loc(id);
if(test1)
{
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("connection successful zied.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("connection failed alimi.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


     ui->le->clear();
     ui->poids->clear();
     ui->volume->clear();
       //ui->etat->clear();


}



void MainWindow::on_supp_clicked()
{
    QModelIndexList selectedIndexes = ui->tab_c->selectionModel()->selectedIndexes();

   // int id=ui->supp_2->text().toInt();


    if (!selectedIndexes.isEmpty()) {
           // Assuming the ID is in the first column (column 0) of the selected row
           int selectedRow = selectedIndexes.at(0).row();
           int id = ui->tab_c->model()->data(ui->tab_c->model()->index(selectedRow, 0)).toInt();

           // Call the supprimer function with the selected ID
           bool test = Ctmp.supprimer(id);

           if (test) {
               ui->tab_c->setModel(Ctmp.afficher());
               QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectuee\n""Click Cancel to exit."), QMessageBox::Cancel);
           } else {
               QMessageBox::critical(nullptr, QObject::tr("OK"), QObject::tr("Suppression non effectuee\n""Click Cancel to exit."), QMessageBox::Cancel);
           }
       } else {
           // Inform the user that no row is selected
           QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("Veuillez sélectionner une ligne à supprimer."), QMessageBox::Ok);
       }


}

void MainWindow::on_aff_clicked()
{
    Colis C;
       ui->tab_c->setModel(C.afficher());

}

void MainWindow::on_tri_clicked()
{
    Colis C;
    QSqlQueryModel MyModel;
    ui->tab_c->setModel(C.sortDatabaseById());
   /* if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Update effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_c->setModel(C.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("Update non effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);*/
}

void MainWindow::on_Rech_clicked()
{
    int id;
    Colis c;
    //id=ui->Rech_l->text().toInt();

    c.displayItemDetails(id) ;

}

void MainWindow::on_mod1_clicked()
{
    int id;
    id=ui->le->text().toInt();

    float poids;
    poids=ui->poids->text().toFloat();

    float volume;
     volume=ui->volume->text().toFloat();
     QString etat;
   //etat=ui->etat->text();



         Colis C(id, poids, volume, etat);

        bool test=C.modifierColis() ;

       if (test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("Update effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_ajout->setModel(C.afficher());
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                    QObject::tr("Update non effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tri_p_clicked()
{
    Colis C;
    QSqlQueryModel MyModel;
    ui->tab_c->setModel(C.sortDatabaseByPoids());
}

void MainWindow::on_tri_volume_clicked()
{
    Colis C;
    QSqlQueryModel MyModel;
    ui->tab_c->setModel(C.sortDatabaseByVolume());
}

void MainWindow::on_tri_b_clicked()
{
    // Get the selected item from the combo box
       QString selectedOption = ui->combo->currentText();
       Colis C;
       if (selectedOption == "id") {

           //QSqlQueryModel MyModel;
           ui->tab_c->setModel(C.sortDatabaseById());
           } else if (selectedOption == "poids") {
           QSqlQueryModel MyModel;
           ui->tab_c->setModel(C.sortDatabaseByPoids());
           } else if (selectedOption == "volume") {
           QSqlQueryModel MyModel;
           ui->tab_c->setModel(C.sortDatabaseByVolume());
           }

  }


void MainWindow::on_Rech_3_textChanged(const QString &arg1)
{

    Colis C;

    QString selectedOption = ui->combo_4->currentText();
    if (selectedOption == "id") {

        QString IDC=ui->Rech_3->text();
       ui->tab_ajout->setModel(C.rechercher(IDC));
      ui->tab_ajout->clearSelection();

if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
    ui->Rech->setToolTip("Entrez l'id à rechercher");
}

        } else if (selectedOption == "poids") {


        QString IDC=ui->Rech_3->text();
       ui->tab_ajout->setModel(C. rechercherpoids(IDC));
      ui->tab_ajout->clearSelection();}

if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
    ui->Rech->setToolTip("Entrez l'id à rechercher");

        } else if (selectedOption == "volume") {
    QString IDC=ui->Rech_3->text();
   ui->tab_ajout->setModel(C. rechercherVolume(IDC));
  ui->tab_ajout->clearSelection();}

if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
ui->Rech->setToolTip("Entrez l'id à rechercher");

        }



}

void MainWindow::on_pdf_clicked()
{

     int id=ui->pdf_bar->text().toInt();
QString    strid=  QString::number(id);
    // Get the selected item from the combo box
       QString selectedOption = ui->combo_2->currentText();
       Colis C;
       if (selectedOption == "liste des colis") {
              C.exportDataToPDF();
           //QSqlQueryModel MyModel;

           }
       else if (selectedOption == "coli") {

           C.exportDataToPDF_par_coli(strid);
           }







}





void MainWindow::on_stat_clicked()
{

    QLayoutItem* item;
       while ((item =ui->verticalLayout ->takeAt(0)) != nullptr) {
           delete item->widget();
           delete item;
       }
QVBoxLayout *verticalLayout = new QVBoxLayout();

    Colis c;

    QString selectedOption = ui->combo_3->currentText();
    Colis C;
    if (selectedOption == "etat") {

        // Call the function to create the pie chart
        QChartView *chartView = c.createPieChart();

        // Set up your UI to include the chart view
        ui->verticalLayout->addWidget(chartView);
        } else if (selectedOption == "poids") {
        // Call the function to create the pie chart
        QChartView *chartView1 = c.createPieChartPoids();

        // Set up your UI to include the chart view
        ui->verticalLayout->addWidget(chartView1);
        } else if (selectedOption == "volume") {
        // Call the function to create the pie chart
        QChartView *chartView2 = c.valume();

        // Set up your UI to include the chart view
        ui->verticalLayout->addWidget(chartView2);

        }






    //



   // Delete the layout item
 }




void MainWindow::on_stat_2_clicked()
{
  /* // QString num2st = QString::number(num2);
    QLayoutItem* item;
       while ((item =ui->verticalLayout ->takeAt(0)) != nullptr) {
           delete item->widget();
           delete item;
       }
QVBoxLayout *verticalLayout = new QVBoxLayout();


    while ((ui->verticalLayout_5->takeAt(0)) != nullptr) {
        delete ui->verticalLayout_5->widget();  // Delete the widget
        delete ui->verticalLayout_5;}
    while ((ui->verticalLayout_3->takeAt(0)) != nullptr) {
        delete ui->verticalLayout_3->widget();  // Delete the widget
        delete ui->verticalLayout_3;}*/
}

void MainWindow::on_stat_3_clicked()
{
    // QString num2st = QString::number(num2);
    QLayoutItem* item;
       while ((item =ui->verticalLayout ->takeAt(0)) != nullptr) {
           delete item->widget();
           delete item;
       }
QVBoxLayout *verticalLayout = new QVBoxLayout();


   /*  while ((ui->verticalLayout_5->takeAt(0)) != nullptr) {
         delete ui->verticalLayout_5->widget();  // Delete the widget
         delete ui->verticalLayout_5;}
     while ((ui->verticalLayout_3->takeAt(0)) != nullptr) {
         delete ui->verticalLayout_3->widget();  // Delete the widget
         delete ui->verticalLayout_3;}*/
}

void MainWindow::on_location_clicked()
{
    ui->quickWidget_MapView->setSource(QUrl(QString("qrc:/QmlMap.qml")));
    ui->quickWidget_MapView->show();

    auto Obje = ui->quickWidget_MapView->rootObject();
    //start position bta3 il map
    connect(this ,SIGNAL(setCenterPosition(QVariant,QVariant)), Obje ,SLOT(setCenterPosition(QVariant,QVariant)));
    //position bta3 il marking
     connect(this ,SIGNAL(setLocationMarking(QVariant,QVariant)), Obje ,SLOT(setLocationMarking(QVariant,QVariant)));

    int userId;
    userId=ui->location_2->text().toInt();
    //ui->MAPA->setText((QString::number(userId)));

   float longi;
         float  lati;
//query.prepare("SELECT * FROM COLIS WHERE poids LIKE :test");

          QSqlQuery   query("SELECT * FROM LOCATION WHERE IDL LIKE :userId");
        query.bindValue(":userId", userId);
              // int did=query.value("idl").toInt();
               longi=  query.value("longitude").toFloat();
                lati=  query.value("latitude").toFloat();
           //    ui->MAPA->setText(QString::number(lati));
               if(userId==1)
               {
                longi=36.8065;
                        lati=10.1815;
               }
              else if(userId==2)
               {
                longi=36.8588;
                        lati=10.3231;
               }
               else if(userId==3)
                {
                 longi=36.8000;
                         lati=10.1808;
                }
               else if(userId==4)
               {
                   longi=36.3969;
                           lati=10.6128;
               }
               else if(userId==5)
               {
                   longi=33.5331;
                           lati=9.9457;
               }
               else if(userId==32)
               {
                   longi=35.6784;
                           lati=10.0965;
               }

    emit setCenterPosition(longi, lati);
     emit setLocationMarking( longi,lati);

}

void MainWindow::on_add_clicked()
{


        QString userText = ui->doadd->text();

           QPushButton *displayLabel = new QPushButton(userText);
       ui->v1->addWidget(displayLabel);

           displayLabel->show();

           QObject::connect(displayLabel, &QPushButton::clicked, this, [this, displayLabel]() {
               if (ui->v1->indexOf(displayLabel) != -1) {
                   ui->v1->removeWidget(displayLabel);  // Remove the button from the current layout
                   ui->v2->addWidget(displayLabel);     // Add the button to the second layout (v2)
               } else if (ui->v2->indexOf(displayLabel) != -1) {
                   ui->v2->removeWidget(displayLabel);  // Remove the button from the current layout (v2)
                   ui->v3->addWidget(displayLabel);     // Add the button to the third layout (v3)
               }
           });



}
void MainWindow::afficherPosition(QString latitude, QString longitude)
{
    qDebug() << Q_FUNC_INFO << latitude << longitude;
    //ui->positionLatitude->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
   // ui->positionLongitude->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
    ui->editLatitude->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
    ui->editLongitude->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
}

void MainWindow::afficherInformations(QString adresse, QString coordonnee)
{
    qDebug() << Q_FUNC_INFO << adresse << coordonnee;
    ui->labelInformations->setText("Informations : " + adresse);
}
void MainWindow::on_location_3_clicked()
{
    QQuickItem *item7 = ui->quickWidget_MapView->rootObject();
        QObject *object = item7->findChild<QObject *>("indicateurPosition");
        QString latitude = ui->editLatitude->text();
        QString longitude = ui->editLongitude->text();

        afficherPosition(latitude,longitude);
        if(object != nullptr)
        {
            qDebug() << Q_FUNC_INFO << latitude << longitude;
            QMetaObject::invokeMethod(object, "aller", Q_ARG(QVariant, latitude), Q_ARG(QVariant, longitude));
        }
}
//**********************************

/*void MainWindow::on_pushButton_6_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_pushButton_4_clicked()
{
      A.write_to_arduino("0");  //envoyer 0 à arduino
}

void MainWindow::on_pushButton_clicked()
{
     A.write_to_arduino("2");   //envoyer 2 à arduino
}

void MainWindow::on_pushButton_3_clicked()
{
     A.write_to_arduino("3");  //envoyer 3 à arduino
}*/


void MainWindow::on_pushButton_clicked()
{

//createPieChart_TMP()
Colis c;
    QChartView *chartView1 = c.createPieChart_TMP();

    // Set up your UI to include the chart view
    ui->verticalLayout_2->addWidget(chartView1);
     //envoyer 2 à arduino
}


void MainWindow::on_pushButton_2_clicked()
{
      A.write_to_arduino("3");  //envoyer 3 à arduino
}

void MainWindow::on_pushButton_3_clicked()
{
          A.write_to_arduino("0");
}

void MainWindow::on_pushButton_4_clicked()
{
A.write_to_arduino("2");
}


void MainWindow::on_tmp_clicked()
{
    Colis c;
    bool test;
 A.write_to_arduino("4");
    // Create an instance of the Arduino class

QByteArray byteArray= A.read_from_arduino() ;

       // Process the response
       qDebug() <<  A.read_from_arduino();
     bool conversionOk;
//QLocale::setDefault(QLocale(QLocale::English));
     byteArray = byteArray.trimmed();
       double myDouble = byteArray.toDouble(&conversionOk);

       if (conversionOk) {
           qDebug() << "Converted value: " << myDouble;
       } else {
           qDebug() << "Conversion to double failed";
       }

         test=c.ajouter_tmp(myDouble);
       if(myDouble>=25)
       {
           A.write_to_arduino("1");
       }
       else
       {
           A.write_to_arduino("2");
       }

        qDebug() <<myDouble;
       // Display the received data directly on tmp_aff
        QString volume_string=QString::number((myDouble));
       ui->tmp_aff->setText(volume_string);

}

void MainWindow::update_label()
{
   // data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void MainWindow::on_aff_tmp_clicked()
{
    Colis C;
       ui->tab_c_2->setModel(C.afficher_tmp());
}

void MainWindow::on_B_ajouter_2_clicked()
{
    int newIndex = 0;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
}

void MainWindow::on_clients_clicked()
{
    int newIndex = 1;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
}



//**************************************8clients code


void MainWindow::on_ajout_clients_clicked()
{
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();
    Clients C(IDC,nomc,prenomc,  adressec,  emailc, numc, nb_commande);

    bool test=C.ajouter() ;
   if (test)
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("Ajout effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_Clients->setModel(C.afficher());
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("Ajout non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_Update_clicked()
{
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();


    Clients C( IDC,  nomc,  prenomc,  adressec,  emailc, numc, nb_commande);

    bool test=C.modifier() ;
   if (test)
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("Update effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_Clients->setModel(C.afficher());
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("Update non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_x_chercher_textChanged(const QString &arg1)
{
    Clients C;
    if (arg1!="")
        ui->tab_Clients->setModel(C.rechercher(arg1));
    else {
        ui->tab_Clients->setModel(C.rechercher(arg1));

    }

//     ui->tab_Clients->clearSelection();
}

void MainWindow::on_comboBox_tri_zii_activated(const QString &arg1)
{
    Clients C;
    if (arg1 == "par defaut") {

           ui->tab_Clients->setModel(C.triClients(arg1));

   } else if (arg1 == "ID") {

           ui->tab_Clients->setModel(C.triClients(arg1));

   } else if (arg1 == "NOM") {

           ui->tab_Clients->setModel(C.triClients(arg1));

   } else if (arg1 == "PRENOM") {

            ui->tab_Clients->setModel(C.triClients(arg1));
   } else if (arg1 == "ADRESSE") {

             ui->tab_Clients->setModel(C.triClients(arg1));
   }

}

void MainWindow::on_pb_pdf_clicked()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            filePath = QDir(filePath).filePath("G_Clients/listeClients.pdf");
            QPdfWriter pdf(filePath);

               QPainter painter(&pdf);
               int i = 4100;
          /* const QImage image("C:/Users/pc/Desktop/image/logo.png");
                           const QPoint imageCoordinates(155,0);
                           int width1 = 1600;
                           int height1 = 1600;
                           QImage img=image.scaled(width1,height1);
                           painter.drawImage(imageCoordinates, img );*/


                      QColor dateColor(0x4a5bcf);
                      painter.setPen(dateColor);

                      painter.setFont(QFont("Montserrat SemiBold", 11));
                      QDate cd = QDate::currentDate();
                      painter.drawText(8400,250,cd.toString("Tunis"));
                      painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                      QColor titleColor(0x341763);
                      painter.setPen(titleColor);
                      painter.setFont(QFont("Montserrat SemiBold", 25));

                      painter.drawText(3000,2700,"Liste des Clients");

                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Time New Roman", 15));
                      //painter.drawRect(100,100,9400,2500);
                      painter.drawRect(100,3300,9400,500);

                      painter.setFont(QFont("Montserrat SemiBold", 10));

                      painter.drawText(500,3600,"reference");
                      painter.drawText(1700,3600,"nom");
                      painter.drawText(2900,3600,"prenom");
                      painter.drawText(4100,3600,"adresse");
                      painter.drawText(5300,3600,"email");
                      painter.drawText(6500,3600,"numero");
                      painter.drawText(7700,3600,"nb_commande");

                      painter.setFont(QFont("Montserrat", 10));
                      painter.drawRect(100,3300,9400,9000);

                      QSqlQuery query;
                      query.prepare("select * from clients");
                      query.exec();
                      int y=4300;
                      while (query.next())
                      {
                          painter.drawLine(100,y,9490,y);
                          y+=500;
                          painter.drawText(500,i,query.value(0).toString());
                          painter.drawText(1700,i,query.value(1).toString());
                          painter.drawText(2900,i,query.value(2).toString());
                          painter.drawText(4100,i,query.value(3).toString());
                          painter.drawText(5300,i,query.value(4).toString());
                          painter.drawText(6500,i,query.value(5).toString());
                          painter.drawText(7700,i,query.value(6).toString());


                         i = i + 500;
                      }
                      QMessageBox::information(nullptr,QObject::tr("Pdf created"),
                      QObject::tr("File created with seccess.\n"
                                  ""),QMessageBox::Ok);
}

void MainWindow::on_pb_supprimer_clicked()
{
    Clients C;
    QString text_ID = ui->le_IDsupp->text();
int IDC = ui->le_IDsupp->text().toInt();

    if (text_ID.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Veuillez entrer un identifiant avant de tenter de supprimer."), QMessageBox::Ok);
        return;
    }

    Clients F1;
    F1.setIDC(IDC);

    if (F1.idExists(IDC)) {
        bool test = F1.supprimer(F1.getIDC());

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Suppression avec succès.\nClick Cancel to exit."), QMessageBox::Cancel);
            ui->tab_Clients->setModel(C.afficher()); // Mise à jour
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                QObject::tr("La suppression a échoué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("L'identifiant n'existe pas."), QMessageBox::Ok);
        return;
    }
}
void MainWindow::on_statistique_tabBarClicked(int index)
{
    int statisticsTabIndex = ui->tabWidget->indexOf(ui->stat);
    int stattabindex = ui->tabWidget->indexOf(ui->statFB);
    int stattab_feedback_index = ui->tabWidget->indexOf(ui->feedback_stat);

    if (index == stattabindex) {
        stat();
    }

    if (index == stattab_feedback_index) {
        //feedback_statt();
    }
    if (index == statisticsTabIndex) {
        update_Clients_StatisticsChart();
    } else {
        clearClients_StatisticsChart();
    }

}
void MainWindow::update_Clients_StatisticsChart()
{
    Clients C;
    qDebug() << "Updating Clients Statistics Chart";
    QMap<QString, int> statistics = C.getClients_Statistics();
    int totalClients = 0;

    for (const int &count : statistics.values()) {
        totalClients += count;
    }

    QPieSeries *series = new QPieSeries();
    QStringList colors = {"#55AA00", "#458C68", "#005500"};
    int colorIndex = 0;

    for (const QString &group : statistics.keys()) {
        int count = statistics[group];
        QPieSlice *slice = series->append(group, count);

        slice->setLabel(group + ": " + QString::number(static_cast<double>(count) / totalClients * 100, 'f', 2) + "%");

        if (colorIndex < colors.size()) {
            slice->setBrush(QColor(colors[colorIndex]));
        } else {
            slice->setBrush(QColor(Qt::green));
        }

        colorIndex++;
    }

    //clearClients_StatisticsChart();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par nombre de commande ");
    chart->setBackgroundBrush(QBrush(QColor("#F5F5DC")));
    chart->setAnimationOptions(QChart:: SeriesAnimations);


    ClientsStatisticsChartView = new QChartView(chart);
    ClientsStatisticsChartView->setRenderHint(QPainter::Antialiasing);
    ClientsStatisticsChartView->setParent(ui->stat);
    ClientsStatisticsChartView->setGeometry(70, 50, 600, 400);

    ClientsStatisticsChartView->show();
}

void MainWindow::clearClients_StatisticsChart()
{
    if (ClientsStatisticsChartView) {
        delete ClientsStatisticsChartView;
        ClientsStatisticsChartView = nullptr;
    }
}
