
#ifndef PHONE_H
#define PHONE_H


#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRegularExpression>
#include <QLabel>
#include <QChar>
#include <QDateEdit>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QListWidget>
#include <QAbstractItemView>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QStringList>
#include <QHeaderView>
#include <algorithm>
#include <QComboBox>
#include <fstream>
#include <string>
#include <filesystem>



using namespace std;
namespace fs = std::filesystem;

class Phone : public QWidget {
    int num_num=1;
    QTableWidget *tableWidget;
    QListWidget* fieldSort;
    QListWidget* fieldSerch;
    QComboBox* bSserch;
    QTableWidget *tableSerch;

    bool flag = false;

    QLineEdit pName;
    QDateEdit pBirthday;
    QLineEdit pEmail;
    QVector<QLineEdit*>PhoneNum;
    QVector<QLabel*> errorNum;
    QLineEdit numChange;
    QLineEdit numDel;
    QLineEdit fileName;
    QLineEdit lSerch;


    QPushButton NewPerson;
    QPushButton addButton;
    QPushButton change;
    QPushButton saveChange;
    QPushButton find;
    QPushButton del;
    QPushButton del2;
    QPushButton saveFile;
    QPushButton saveFile2;
    QPushButton loadFile;
    QPushButton loadFile2;
    QPushButton sort1;
    QPushButton sort2;
    QPushButton Serch1;
    QPushButton Serch2;
    QPushButton endProg;
    QPushButton back;
    QPushButton sortback;
    QPushButton serchback;
    QPushButton SLback;
    QPushButton addNum;
    QPushButton addNumChange;

    QLabel errorName;
    QLabel errorEmail;
    QLabel errorData;
    QLabel errorChange;
    QLabel errorDel;
    QLabel lsotr;
    QLabel lday;
    QLabel* n;
    QLabel a;

public:
    Phone();
    bool wrongNumChange(QString sNChange);
    bool wrongNumDel(QString sNChange);
    bool wrongName(QString Name);
    bool wrongNumber(QString PhoneNum,int i);
    bool wrongEmail(QString email);
    bool wrongData(QDate data);
    QString correctNum(QString num);

    private slots:
        void newPerson();
    void addPerson();
    void changePerson();
    void sChange();
    void cField();
    void delPerson();
    void delPerson2();
    void saveToFile();
    void saveToFile2();
    void loadFromFile();
    void loadFromFile2();
    void sortTab();
    void sortTab2();
    void serch1();
    void serch2();
    void vback();
    void vSback();
    void serchChange(const QString& text);
    void serchBack();
    void vSLback();
    void addNumVoid();
    void addNumVChange();
};

#endif //PHONE_H
