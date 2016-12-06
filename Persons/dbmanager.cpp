#include "dbmanager.h"
#include <QVariant>
#include <QSqlQuery>


DbManager::DbManager(){}

DbManager::DbManager(const QString &path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    getPersons();

}
DbManager::~DbManager() {_db.close();}

void DbManager::getPersons()
{
    QString s = "SELECT * FROM Persons";
    QSqlQuery query(_db);
    query.exec(s);
    Person temp;
    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();
        temp.setName(name);

        string gender = query.value("Gender").toString().toStdString();
        temp.setGender(gender);

        int birthYear = query.value("birthYear").toUInt();
        temp.setBirthYear(birthYear);

        int deathYear = query.value("deathYear").toUInt();
        temp.setDeathYear(deathYear);
        _persons.push_back(temp);
    }
}
vector<Person> DbManager::getVector() const {return _persons;}

bool DbManager::isOpen() const {return _db.isOpen();}

void DbManager::setVector(const vector<Person> &input) {_persons = input;}

void DbManager::changeData()
{

}
void DbManager::insertIntoComputer(const Computer &input)
{
    cout << "name: " << input.getName() << endl;
    cout << "type: " << input.getType() << endl;
    cout << "year: " << input.getYearBuilt() << endl;
    cout << "built? " << input.getBuilt() << endl;
    QString qsName = QString::fromStdString(input.getName());
    QString qsType= QString::fromStdString(input.getType());
    QString qsBuilt = QString::fromStdString(input.getBuilt());
    QString path = "C:/Users/Rabo/HR/onn1/Verklegt Namskeid/verklegt_namskeid1/ComputerScience.sqlite";
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();

    if(_db.open())
    {
        cout << "opened!";
        QSqlQuery qry;
        qry.prepare("INSERT INTO Computers(Name, yearBuilt, Type, Built)"
                    "VALUES(:C_Name,:C_yearBuilt,:C_Type,:C_Built");
        qry.bindValue(":C_Name",qsName);
        qry.bindValue(":C_yearBuilt",input.getYearBuilt());
        qry.bindValue(":C_Type",qsType);
        qry.bindValue(":C_Built",qsBuilt);
        if( !qry.exec() )
            //qDebug() << qry.lastError().text();
            cout << "error inserting into database";
        else
            qDebug( "Inserted!" );
        cout << "inserted! " << endl;
    }
    else
    {
        cout << "not open " << endl;
    }
}
