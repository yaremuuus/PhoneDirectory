
#include "Phone.h"


Phone::Phone() {
    setWindowTitle("Телефонный справочник");
    tableWidget = new QTableWidget(0, 4);
    QStringList headers;
    headers << "ФИО"  << "Дата рождения"<<"e-mail"<< "Телефон";
    tableWidget->setHorizontalHeaderLabels(headers);

    NewPerson.setText("Добавить запись");
    connect(&NewPerson, &QPushButton::clicked, this, &Phone::newPerson);
    NewPerson.setParent(this);
    NewPerson.setGeometry(10,10,250,40);

    change.setParent(this);
    change.setText("Изменть контакт");
    change.setGeometry(10,60,250,40);
    connect(&change, &QPushButton::clicked,this,&Phone::changePerson);
    change.show();

    del.setParent(this);
    del.setText("Удалить контакт");
    del.setGeometry(10,110,250,40);
    connect(&del,&QPushButton::clicked,this,&Phone::delPerson);
    del.show();

    sort1.setParent(this);
    sort1.setText("Сортировать");
    sort1.setGeometry(10,160,250,40);
    connect(&sort1,&QPushButton::clicked,this,&Phone::sortTab);
    sort1.show();

    saveFile.setParent(this);
    saveFile.setText("Сохранить в файл");
    saveFile.setGeometry(10,210,250,40);
    connect(&saveFile,&QPushButton::clicked,this,&Phone::saveToFile);
    saveFile.show();

    a.setParent(this);

    loadFile.setParent(this);
    loadFile.setText("Загрузить из файла");
    loadFile.setGeometry(10,260,250,40);
    connect(&loadFile,&QPushButton::clicked,this,&Phone::loadFromFile);
    loadFile.show();

    Serch1.setParent(this);
    Serch1.setText("Поиск");
    Serch1.setGeometry(10,310,250,40);
    connect(&Serch1,&QPushButton::clicked,this,&Phone::serch1);
    Serch1.show();

    lday.setParent(this);
    lday.setText("Дата рождения:");
    lday.hide();

    back.setParent(this);
    back.setText("Назад");
    back.setGeometry(880,640,150,50);
    connect(&back,&QPushButton::clicked,this,&Phone::vback);
    back.hide();

    sortback.setParent(this);
    sortback.setText("Назад");
    sortback.setGeometry(880,640,150,50);
    connect(&sortback,&QPushButton::clicked,this,&Phone::vSback);
    sortback.hide();

    serchback.setParent(this);
    serchback.setText("Назад");
    serchback.setGeometry(880,640,150,50);
    connect(&serchback,&QPushButton::clicked,this,&Phone::serchBack);
    serchback.hide();

    SLback.setParent(this);
    SLback.setText("Назад");
    SLback.setGeometry(880,640,150,50);
    connect(&SLback,&QPushButton::clicked,this,&Phone::vSLback);
    SLback.hide();

    endProg.setParent(this);
    endProg.setText("Выход");
    endProg.setGeometry(1040,640,150,50);
    connect(&endProg,&QPushButton::clicked,this,&QApplication::quit);
    endProg.show();

    PhoneNum.resize(4);
    errorNum.resize(4);
    for (int i = 0; i < 4; ++i) {
        QLineEdit *num = new QLineEdit(this);
        num->hide();
        PhoneNum[i]=(num);

        QLabel* erNum = new QLabel(this);
        erNum->hide();
        errorNum[i]=(erNum);
    }
    addNum.setText("Добавить телефон");
    connect(&addNum,&QPushButton::clicked,this, &Phone::addNumVoid);
    tableWidget->setParent(this);
    tableWidget->setGeometry(270,10,920,600);
    errorName.setParent(this);
    tableSerch = new QTableWidget(0, 7);
    errorEmail.setParent(this);
    errorData.setParent(this);
    numChange.setParent(this);
    errorChange.setParent(this);
    saveChange.setParent(this);
    numDel.setParent(this);
    del2.setParent(this);
    fileName.setParent(this);
    saveFile2.setParent(this);
    fileName.setParent(this);
    loadFile2.setParent(this);
    lsotr.setParent(this);
    sort2.setParent(this);
    errorChange.setParent(this);
    Serch2.setParent(this);
    addNum.setParent(this);
    addNumChange.setParent(this);
    addNumChange.hide();
    addNum.hide();
    numChange.hide();
    errorChange.hide();
    saveChange.hide();
    numDel.hide();
    del2.hide();
    fileName.hide();
    saveFile2.hide();
    fileName.hide();
    loadFile2.hide();
    lsotr.hide();
    sort2.hide();
    errorChange.hide();
    Serch2.hide();

    errorDel.setParent(this);
    errorDel.setGeometry(10,115,250,10);
    errorDel.hide();

    pName.setParent(this);
    pBirthday.setParent(this);
    pEmail.setParent(this);
    addButton.setParent(this);
    addButton.setText("Сохранить");
    connect(&addButton, &QPushButton::clicked, this, &Phone::addPerson);

    find.setParent(this);
    find.setText("Найти");
    find.setGeometry(130,10,120,40);
    connect(&find,&QPushButton::clicked,this,&Phone::cField);
    find.hide();

    pName.hide();
    pBirthday.hide();
    pEmail.hide();
    addButton.hide();
}


void Phone::newPerson() {
    back.show();
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    pName.show();
    PhoneNum[0]->show();
    PhoneNum[0]->setPlaceholderText(QString("Телефонный номер 1"));
    PhoneNum[0]->setGeometry(10,190,250,40);
    for(int i = 0; i< 4;i++) {
        errorNum[i]->setGeometry(10,225+i*55,250,10);
        errorNum[i]->hide();
    }
    addNum.setGeometry(10,190+55,250,40);
    addNum.show();
    lday.setGeometry(10,70,120,40);
    lday.show();
    pName.setPlaceholderText("ФИО");
    pEmail.setPlaceholderText("e-mail");
    pName.setGeometry(10,10,250,40);
    pBirthday.setGeometry(130,70,120,40);
    pEmail.setGeometry(10,130,250,40);
    addButton.setGeometry(10,300,250,40);
    errorName.setGeometry(10,55,250,10);
    errorData.setGeometry(10,115,250,10);
    errorEmail.setGeometry(10,170,250,13);
    pBirthday.show();
    pEmail.show();
    addButton.show();
}

void Phone::addNumVoid() {
    num_num++;
    if(num_num<5){
        for(int i =1;i<num_num;i++) {
            PhoneNum[i]->show();
            PhoneNum[i]->setPlaceholderText(QString("Телефонный номер %1").arg(i + 1));
            PhoneNum[i]->setGeometry(10,190+i*55,250,40);
            errorNum[i]->setGeometry(10,230+i*55,250,10);
            errorNum[i]->hide();
        }
        addNum.setGeometry(10,190+num_num*55,250,40);
        addButton.setGeometry(10,245+num_num*55,250,40);
    }
}


void Phone::addPerson() {
    errorName.hide();
    errorEmail.hide();
    errorData.hide();
    saveFile.hide();
    int p = 0;
    QString sPhone ="";
    for(int i =0; i< 4;i++) {
        errorNum[i]->hide();
        if(wrongNumber(PhoneNum[i]->text(),i)) {
            sPhone += PhoneNum[i]->text();
            sPhone+=", ";
            p++;
        }
    }

    sPhone.chop(2);
    QString sName = pName.text();
    QString sBday = pBirthday.text();
    QString sEmail = pEmail.text();
    QDate sData = pBirthday.date();
    bool n(wrongName(sName)),e(wrongEmail(sEmail)), d(wrongData(sData));
    if (n && p==4 && e && d) {
        int rowCount = tableWidget->rowCount();
        tableWidget->insertRow(rowCount);
        tableWidget->setItem(rowCount, 0, new QTableWidgetItem(sName.trimmed()));
        tableWidget->setItem(rowCount, 1, new QTableWidgetItem(sBday));
        tableWidget->setItem(rowCount, 2, new QTableWidgetItem(sEmail.trimmed()));
        tableWidget->setItem(rowCount, 3, new QTableWidgetItem(sPhone.trimmed()));
        tableWidget->resizeColumnToContents(3);
        for(int k =0;k <4;k++) {
            PhoneNum[k]->clear();
            PhoneNum[k]->hide();
        }
        pName.clear();
        pBirthday.clear();
        pEmail.clear();
        vback();
    }
}

void Phone::changePerson() {
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    find.show();
    lday.show();
    back.show();

    addNumChange.setText("Добавить телефон");
    addNumChange.setGeometry(10,190+55+55,250,40);
    addNumChange.show();
    connect(&addNumChange,&QPushButton::clicked,this,&Phone::addNumVChange);
    numChange.setPlaceholderText("Номер изменяемого контакта");
    numChange.setGeometry(10,10,120,40);
    pName.setGeometry(10,70,250,40);
    pBirthday.setGeometry(130,130,120,40);
    lday.setGeometry(10,130,120,40);
    pEmail.setGeometry(10,190,250,40);

    errorChange.setGeometry(10,55,250,10);
    errorName.setGeometry(10,115,250,10);
    errorData.setGeometry(10,170,250,10);
    errorEmail.setGeometry(10,230,250,13);
    pName.setPlaceholderText("ФИО");
    pEmail.setPlaceholderText("e-mail");
    PhoneNum[0]->show();
    PhoneNum[0]->setPlaceholderText(QString("Телефонный номер 1"));
    PhoneNum[0]->setGeometry(10,250,250,40);
    errorNum[0]->setGeometry(10,295,250,10);

    numChange.show();
    pName.show();
    pBirthday.show();
    pEmail.show();

    saveChange.setText("Изменить");
    saveChange.setGeometry(10,470,250,40);
    connect(&saveChange,&QPushButton::clicked, this,& Phone::sChange);
    saveChange.show();
}

void Phone::addNumVChange() {
    num_num++;
    if(num_num<5){
        PhoneNum[num_num-1]->show();
        PhoneNum[num_num-1]->setPlaceholderText(QString("Телефонный номер %1").arg((num_num)));
        PhoneNum[num_num-1]->setGeometry(10,190+55+(num_num-1)*55,250,40);
        errorNum[num_num-1]->setGeometry(10,190+55*2+(num_num-1)*55,250,10);

        addNumChange.setGeometry(10,190+55+num_num*55,250,40);
        saveChange.setGeometry(10,245+55+num_num*55,250,40);
    }
}

void Phone::sChange() {
    errorChange.hide();
    errorName.hide();
    errorEmail.hide();
    errorData.hide();
    errorChange.hide();
    QVector<QString*> sPhone;
    sPhone.resize(4);
    for(int i =0; i< 4;i++) {
        errorNum[i]->hide();
        QString *num = new QString(PhoneNum[i]->text());
        sPhone[i]=(num);
    }
    QString sNChange = numChange.text();
    QString sName = pName.text();
    QString sBday = pBirthday.text();
    QString sEmail = pEmail.text();
    QDate sData = pBirthday.date();
    bool c,n,e,d;
    c = wrongNumChange(sNChange);
    !sName.isEmpty()? n = wrongName(sName):n=true;
    !sEmail.isEmpty()? e = wrongEmail(sEmail):e=true;
    !sBday.isEmpty()? d =wrongData(sData):d = true;

    if (c && n && e &&  d){
        int rowCount = sNChange.toInt()-1;

        if(!sName.isEmpty())tableWidget->setItem(rowCount, 0, new QTableWidgetItem(sName));
        if(!sBday.isEmpty())tableWidget->setItem(rowCount, 1, new QTableWidgetItem(sBday));
        if(!sEmail.isEmpty())tableWidget->setItem(rowCount, 2, new QTableWidgetItem(sEmail));
        int c =3;
        for(int i =0;i<4;i++) {
            if(!sPhone[i]->isEmpty())
                tableWidget->setItem(rowCount, c++, new QTableWidgetItem(*sPhone[i]));
            tableWidget->resizeColumnToContents(i);
            PhoneNum[i]->clear();
        }
        numChange.clear();
        pBirthday.clear();
        pEmail.clear();
        num_num=1;
        vback();
    }
}

void Phone::delPerson() {
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    back.show();

    numDel.setPlaceholderText("Номер удаляемого контакта");
    numDel.setGeometry(10,70,250,40);

    numDel.show();
    del2.setText("Удалить");
    del2.setGeometry(10,130,250,40);
    connect(&del2,&QPushButton::clicked, this,&Phone::delPerson2);
    del2.show();
}

void Phone::delPerson2() {
    errorDel.hide();
    QString sDel = numDel.text();
    if ((wrongNumDel(sDel))) {
        int row = numDel.text().toInt()-1;
        tableWidget->removeRow(row);
        numDel.clear();
        vback();
    }
}

void Phone::saveToFile() {
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    SLback.show();

    fileName.setPlaceholderText("Имя файла");
    fileName.setGeometry(10,70,250,40);
    fileName.show();

    saveFile2.setText("Сохранить");
    saveFile2.setGeometry(10,110,250,40);
    connect(&saveFile2,&QPushButton::clicked, this,&Phone::saveToFile2);
    saveFile2.show();
}

void Phone::saveToFile2() {
    QString temp;
    int rowCount = tableWidget->rowCount();
    int columnCount = tableWidget->columnCount();
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column) {
            QTableWidgetItem* item = tableWidget->item(row, column);
            if (item) {
                temp+=item->text();
            }
            else temp+=" ";

            if (column < columnCount - 1) {
                temp+= "\t";
            }
        }
        temp+="\n";
    }
    temp.chop(1);
    QString fname = fileName.text();
    QString fmap;
    QFile file(fname);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out<<temp;
        file.close();
    }
    else {
        a.setGeometry(10,235,250,40);
        a.setText("Не удалось сохранить.\nПопробуйте еще раз");
        a.setStyleSheet( "color: RED;");
        fileName.clear();
        a.show();
    }
    fileName.clear();
    vSLback();
    a.hide();
}

void Phone::loadFromFile() {
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    SLback.show();

    fileName.setPlaceholderText("Имя файла");
    fileName.setGeometry(10,70,250,40);
    fileName.show();

    loadFile2.setText("Извлечь");
    loadFile2.setGeometry(10,115,250,40);
    connect(&loadFile2,&QPushButton::clicked, this,&Phone::loadFromFile2);
    loadFile2.show();
}

void Phone::loadFromFile2() {
    QString fname = fileName.text();
    QFile file(fname);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        tableWidget->clearContents();
        tableWidget->setRowCount(0);

        QString line = in.readAll();
        QStringList rows = line.split("\n");

        for(const QString& row : rows) {
            if(!row.isEmpty()) {
                QStringList items = row.split('\t');
                int rowCount = tableWidget->rowCount();
                tableWidget->insertRow(rowCount);
                for(int column = 0; column < items.size(); ++column) {
                    QTableWidgetItem* newItem = new QTableWidgetItem(items[column]);
                    tableWidget->setItem(rowCount, column, newItem);
                }
            }
        }

        file.close();
        tableWidget->resizeColumnsToContents();
        fileName.clear();
        vSLback();
    } else {
        a.setGeometry(10, 170, 250, 40);
        a.setText("Не удалось открыть файл.\nПопробуйте еще раз");
        a.setStyleSheet("color: RED;");
        fileName.clear();
        a.show();
    }
}

void Phone::sortTab() {
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    sortback.show();

    lsotr.setText("Выберите поля для сортировки");
    lsotr.setGeometry(10,30,250,40);
    lsotr.show();
    fieldSort = new QListWidget(this);
    fieldSort->addItems({"ФИО", "День рождение", "e-mail","Телефон"});
    fieldSort->setGeometry(10,70,250,200);
    fieldSort->setSelectionMode(QAbstractItemView::MultiSelection);
    fieldSort->show();

    sort2.setText("Сортировать");
    sort2.setGeometry(10,280,250,40);
    connect(&sort2,&QPushButton::clicked, this,&Phone::sortTab2);
    sort2.show();
}

void Phone::sortTab2() {
    if (!(tableWidget->rowCount() == 0)) {
        QVector<int> selectedItems;
        QList<QListWidgetItem*> items = fieldSort->selectedItems();
        for(int i =0; i<items.size();i++) {
            if(items[i]->text()=="ФИО")
                selectedItems.append(0);
            else if(items[i]->text()=="День рождение")
                selectedItems.append(1);
            else if(items[i]->text()=="e-mail")
                selectedItems.append(2);
            else if(items[i]->text()=="Телефон")
                selectedItems.append(3);
        }
        QVector<QPair<int, QStringList>> sortData;

        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            QStringList values;
            for (int col : selectedItems) {
                if (col < tableWidget->columnCount()) {
                    QTableWidgetItem *item = tableWidget->item(row, col);
                    values << (item ? item->text() : "");
                }
            }
            sortData.append(qMakePair(row, values));
        }

        std::sort(sortData.begin(), sortData.end(), [](const QPair<int, QStringList> &a, const QPair<int, QStringList> &b) {
            return a.second < b.second;
        });

        QTableWidget *sortedTable = new QTableWidget(tableWidget->rowCount(), tableWidget->columnCount());
        QStringList horizontalHeaders;

        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            horizontalHeaders << tableWidget->horizontalHeaderItem(col)->text();
        }
        sortedTable->setHorizontalHeaderLabels(horizontalHeaders);

        for (int newRow = 0; newRow < sortData.size(); ++newRow) {
            int originalRow = sortData[newRow].first;
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = tableWidget->item(originalRow, col);
                sortedTable->setItem(newRow, col, new QTableWidgetItem(item ? item->text() : ""));
            }
        }

        delete tableWidget;
        tableWidget = sortedTable;
        tableWidget->setParent(this);
        tableWidget->show();
        tableWidget->setGeometry(270,10,920,600);

        fieldSort->clear();
    }
    vSback();
}

void Phone::serch1() {
    change.hide();
    NewPerson.hide();
    del.hide();
    saveFile.hide();
    loadFile.hide();
    sort1.hide();
    Serch1.hide();
    serchback.show();
    n = new QLabel("Введите значения полей",this);
    n->setGeometry(10,10,250,50);
    n->show();
    n->setStyleSheet( "font-size: 12pt;");

    bSserch= new QComboBox(this);
    bSserch->setGeometry(10,75,250,40);
    bSserch->addItems({"ФИО", "День рождения", "e-mail","Телефон"});
    bSserch->show();
    lSerch.setParent(this);
    lSerch.setGeometry(10,130,250,40);
    errorName.setGeometry(10,170,250,10);
    errorData.setGeometry(10,170,250,10);
    errorEmail.setGeometry(10,170,250,13);
    errorNum[0]->setGeometry(10,170,250,10);
    lSerch.show();
    lSerch.setPlaceholderText("ФИО");
    connect(bSserch, &QComboBox::currentTextChanged, this, &Phone::serchChange);

    Serch2.setText("Поиск");
    Serch2.setGeometry(10,185,250,40);
    connect(&Serch2,&QPushButton::clicked, this,&Phone::serch2);
    Serch2.show();
}

void Phone::serch2() {
    tableSerch->clear();
    errorName.hide();
    errorEmail.hide();
    errorData.hide();
    errorNum[0]->hide();
    QString text = bSserch->currentText();
    QString sSerch = lSerch.text();
    bool a;
    if(text=="ФИО") a =wrongName(sSerch);
    if(text=="День рождения") a =wrongData(pBirthday.date());
    if(text=="e-mail") a =wrongName(sSerch);
    if(text=="Телефон") a =wrongNumber(sSerch,0);

    if (a) {
        tableSerch->resize(0, 7);
        QStringList headers;
        headers << "ФИО" << "день рождения" << "e-mail" << "Телефон" << "Телефон" << "Телефон" << "Телефон";
        tableSerch->setHorizontalHeaderLabels(headers);
        tableSerch->setParent(this);
        tableSerch->setGeometry(270, 10, 920, 600);

        for (int i = 0; i < tableWidget->rowCount(); ++i) {
            if(text!="Телефон"&& text!= "День рождения"){
                if (tableWidget->item(i, bSserch->currentIndex())->text().indexOf(sSerch)!=-1) {
                    tableSerch->insertRow(tableSerch->rowCount());
                    for (int j = 0; j < 7; ++j) {
                        QTableWidgetItem* sourceItem = tableWidget->item(i, j);
                        QTableWidgetItem* newItem = new QTableWidgetItem(*sourceItem);
                        tableSerch->setItem(tableSerch->rowCount()-1, j, newItem);
                    }
                }
            }
            else if(text=="Телефон"){
                for(int k = 3;k < 7;k++) {
                    if (tableWidget->item(i, k)->text(). indexOf(sSerch)!=-1){
                        tableSerch->insertRow(tableSerch->rowCount());
                        for (int j = 0; j < 7; ++j) {
                            QTableWidgetItem* sourceItem = tableWidget->item(i, j);
                            QTableWidgetItem* newItem = new QTableWidgetItem(*sourceItem);
                            tableSerch->setItem(tableSerch->rowCount()-1, j, newItem);
                        }
                    }
                }
            }
            else {
                if ( (tableWidget->item(i, bSserch->currentIndex())->text() == pBirthday.date().toString("dd.MM.yyyy"))) {
                    tableSerch->insertRow(tableSerch->rowCount());
                    for (int j = 0; j < 7; ++j) {
                        QTableWidgetItem* sourceItem = tableWidget->item(i, j);
                        QTableWidgetItem* newItem = new QTableWidgetItem(*sourceItem);
                        tableSerch->setItem(tableSerch->rowCount()-1, j, newItem);
                    }
                }
            }

        }
        tableWidget->hide();
        tableSerch->show();
        errorName.hide();
        errorEmail.hide();
        errorData.hide();
        errorNum[0]->hide();
    }
    lSerch.clear();
}

bool Phone::wrongNumChange(QString sNChange) {
    auto num =sNChange.trimmed();
    if (num.isEmpty() ) {
        errorChange.setText("Пустое поле");
        errorChange.setStyleSheet( "color: RED;");
        errorChange.show();
        numChange.clear();
        return false;
    }
    for (QChar ch : num) {
        if (!ch.isDigit()){
            errorChange.setText("Неверные символы");
            errorChange.setStyleSheet( "color: RED;");
            errorChange.show();
            numChange.clear();
            return false;
        }
    }

    if (num.toInt()-1<0 || num.toInt()>tableWidget->rowCount()) {
        errorChange.setText(QString("Номер должен быть от 1 до %1").arg(tableWidget->rowCount()) );
        errorChange.setStyleSheet( "color: RED;");
        errorChange.show();
        numChange.clear();
        return false;
    }
    return true;
}

bool Phone::wrongNumDel(QString sDel) {
    auto nD =sDel.trimmed();
    if (nD.isEmpty() ) {
        errorDel.setText("Пустое поле");
        errorDel.setStyleSheet( "color: RED;");
        errorDel.show();
        numDel.clear();
        return false;
    }
    for (QChar ch : nD) {
        if (!ch.isDigit()){
            errorDel.setText("Неверные символы");
            errorDel.setStyleSheet( "color: RED;");
            errorDel.show();
            numDel.clear();
            return false;
        }
    }

    if (nD.toInt()-1<0 || nD.toInt()-1>tableWidget->rowCount()) {
        errorDel.setText(QString("Номер должен быть от 1 до %1").arg(tableWidget->rowCount()) );
        errorDel.setStyleSheet( "color: RED;");
        errorDel.show();
        numDel.clear();
        return false;
    }
    return true;
}

bool Phone::wrongName(QString Name) {
    Name = Name.trimmed();
    if (Name.isEmpty()) {
        errorName.setText("Пустое поле");
        errorName.setStyleSheet("color: RED;");
        errorName.show();
        pName.clear();
        return false;
    }

    for (QChar ch : Name) {
        if (!ch.isLetter() && ch != ' ' && ch != '-') {
            errorName.setText("Неверные символы");
            errorName.setStyleSheet("color: RED;");
            errorName.show();
            pName.clear();
            return false;
        }
    }

    if (Name.endsWith('-')) {
        errorName.setText("Имя не должно заканчиваться на деффис");
        errorName.setStyleSheet( "color: RED;");
        errorName.show();
        pName.clear();
        return false;
    }
    return true;
}

bool Phone::wrongNumber(QString PhoneNum,int i) {
    auto num = PhoneNum.trimmed();
    if(PhoneNum.isEmpty() && i == 0) {
        errorNum.at(i)->setText("Пустое поле");
        errorNum[i]->setStyleSheet( "color: RED;");
        errorNum[i]->show();
        PhoneNum.clear();
        return false;
    }
    for (QChar ch : num) {
        if (!ch.isDigit() && ch != ' ' &&ch != '-' && ch != '(' && ch != ')' && ch != '+' && ch!= ',') {
            errorNum[i]->setText("Неверные символы");
            errorNum[i]->setStyleSheet( "color: RED;");
            errorNum[i]->show();
            PhoneNum.clear();
            return false;
        }
    }
    if (num.endsWith('+') || num.endsWith('(')) {
        errorNum[i]->setText("Номер не может заканчиваться на + ( ");
        errorNum[i]->setStyleSheet( "color: RED;");
        errorNum[i]->show();
        PhoneNum.clear();
        return false;
    }
    return true;
}

bool Phone::wrongEmail(QString email) {

    email = email.trimmed();
    if (email.isEmpty()) {
        errorEmail.setText("Пустое поле");
        errorEmail.setStyleSheet("color: RED;");
        errorEmail.show();
        pEmail.clear();
        return false;
    }

    for (QChar ch : email) {
        QRegularExpression re("^[a-zA-Z]+._$");

        if (re.match(ch).hasMatch() && !ch.isDigit() && ch != '-'&& ch !='_' && ch!= '@') {
            errorEmail.setText("Неверные символы");
            errorEmail.setStyleSheet( "color: RED;");
            errorEmail.show();
            pEmail.clear();
            return false;
        }
    }

    if (!email.contains('@')) {
        errorEmail.setText("e-mail должен содержать @");
        errorEmail.setStyleSheet("color: RED;");
        errorEmail.show();
        pEmail.clear();
        return false;
    }
    if (email.endsWith('@') || email[0]=='@') {
        errorEmail.setText("@ не должен стоять вначале или конце");
        errorEmail.setStyleSheet("color: RED;");
        errorEmail.show();
        pEmail.clear();
        return false;
    }
    return true;
}

bool Phone::wrongData(QDate data) {
    QDate today = QDate::currentDate();
    if (data >= today) {
        errorData.setText("Дата не может превышать сегодняшнюю");
        errorData.setStyleSheet("color: RED;");
        errorData.show();
        return false;
    }
    return true;
}

void Phone::cField() {
    QString  row = numChange.text();
    if (wrongNumChange(row)) {
        int row = numChange.text().toInt()-1;
        if (tableWidget->item(row, 0)&&tableWidget->item(row, 0)->text() != "") {
            pName.setPlaceholderText(QString(tableWidget->item(row, 0)->text()));
        }
        else pName.setPlaceholderText("ФИО");
        if (tableWidget->item(row, 2)&&tableWidget->item(row, 2)->text()!="") {
            pEmail.setPlaceholderText(QString(tableWidget->item(row, 2)->text()));
        }
        else pEmail.setPlaceholderText("e-mail");
        for (int i = 0; i < 4; i++) {
            if (tableWidget->item(row, 3 + i)&&tableWidget->item(row, 3 + i)->text()!="") {
                PhoneNum[i]->setPlaceholderText(tableWidget->item(row, 3 + i)->text());
            }
            else PhoneNum[i]->setPlaceholderText(QString("Телефонный номер %1").arg(i + 1));
        }
    }
}

void Phone::serchChange(const QString& text) {
    if(text=="ФИО") {
        lSerch.clear();
        lSerch.show();
        lSerch.setPlaceholderText("ФИО");
        pBirthday.hide();
        lday.hide();
    }
    else if(text=="e-mail") {
        lSerch.clear();
        lSerch.show();
        lSerch.setPlaceholderText("e-mail");
        pBirthday.hide();
        lday.hide();
    }
    else if(text== "Телефон") {
        lSerch.clear();
        lSerch.show();
        pBirthday.hide();
        lday.hide();
        lSerch.setPlaceholderText("Телефон");
    }
    else if(text =="Дата рождения") {
        pBirthday.clear();
        lSerch.hide();
        pBirthday.show();
        lday.show();
        pBirthday.setGeometry(130,130,120,40);
        lday.setGeometry(10,130,120,40);
    }
}


void Phone::vback() {
    a.hide();
    pName.hide();
    pBirthday.hide();
    pEmail.hide();
    for(auto n: PhoneNum)
        n->hide();
    for(auto n :errorNum)
        n->hide();
    numChange.hide();
    numDel.hide();
    fileName.hide();
    NewPerson.show();
    addButton.hide();
    change.show();
    saveChange.hide();
    find.hide();
    del.show();
    del2.hide();

    saveFile.show();
    saveFile2.hide();
    loadFile.show();
    loadFile2.hide();
    sort1.show();
    sort2.hide();
    Serch1.show();
    Serch2.hide();
    back.hide();
    sortback.hide();
    addNum.hide();
    addNumChange.hide();
    num_num =1;
    errorName.hide();
    errorEmail.hide();
    errorData.hide();
    errorChange.hide();
    errorDel.hide();
    lsotr.hide();
    lday.hide();
}

void Phone::vSLback() {
    fileName.hide();
    NewPerson.show();
    addButton.hide();
    change.show();
    del.show();

    saveFile.show();
    saveFile2.hide();
    loadFile.show();
    loadFile2.hide();
    sort1.show();
    Serch1.show();
    SLback.hide();
    a.hide();
}


void Phone::vSback() {
    fieldSort->hide();
    pName.hide();
    pBirthday.hide();
    pEmail.hide();
    for(auto n: PhoneNum)
        n->hide();
    for(auto n :errorNum)
        n->hide();
    numChange.hide();
    numDel.hide();
    fileName.hide();
    NewPerson.show();
    addButton.hide();
    change.show();
    saveChange.hide();
    find.hide();
    del.show();
    del2.hide();

    saveFile.show();
    saveFile2.hide();
    loadFile.show();
    loadFile2.hide();
    sort1.show();
    sort2.hide();
    Serch1.show();
    Serch2.hide();
    back.hide();

    errorName.hide();
    errorEmail.hide();
    errorData.hide();
    errorChange.hide();
    errorDel.hide();
    lsotr.hide();
    lday.hide();
}

void Phone::serchBack() {
    change.show();
    lday.hide();
    pBirthday.hide();
    NewPerson.show();
    del.show();
    saveFile.show();
    loadFile.show();
    sort1.show();
    Serch1.show();
    serchback.hide();
    n->hide();
    bSserch->hide();
    lSerch.hide();
    Serch2.hide();
    errorName.hide();
    errorEmail.hide();
    errorData.hide();
    errorChange.hide();
    errorNum[0]->hide();
    tableSerch->hide();
    tableWidget->show();
}


QString Phone::correctNum(QString num) {
    QString cleaned = num;
    cleaned.remove(QRegExp("[\\s()]+"));
    return cleaned;
}


