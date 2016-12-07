#include "dbmanager.h"
#include <QVariant>
#include <QSqlQuery>
#include "computer.h"


DbManager::DbManager()
{
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        //cout << "dbconnection found " << endl;

        //Do stuff...
    }
    else
    {
        //_db = QSqlDatabase::addDatabase("QSQLITE");
        const QString path = "ComputerScience.sqlite";
        _db = QSqlDatabase::addDatabase("QSQLITE", "dbconnection");
        QString dbName = path;
        _db.setDatabaseName(dbName);
        _db.open();
    }
    getPersons();
    getComputers();
}
DbManager::~DbManager() {_db.close();}



void DbManager::getPersons()
{
    const QString path = "ComputerScienceBackup.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
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

void DbManager::getComputers()
{
    const QString path = "ComputerScienceBackup.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    QString s = "SELECT * FROM Computers";
    QSqlQuery query(_db);
    query.exec(s);
    Computer temp;
    while (query.next())
    {
        string name = query.value("Name").toString().toStdString();
        temp.setName(name);

        int YearBuilt = query.value("YearBuilt").toUInt();
        temp.setYearbuild(YearBuilt);

        string Type = query.value("Type").toString().toStdString();
        temp.setType(Type);

        string Built = query.value("Built").toString().toStdString();
        temp.setBuilt(Built);
        _Computer.push_back(temp);
    }
}

vector<Person> DbManager::getVector() const {return _persons;}

vector<Computer> DbManager::getCVector() const {return _Computer;}

bool DbManager::isOpen() const {return _db.isOpen();}

void DbManager::setVector(const vector<Person> &input) {_persons = input;}

void DbManager::setCVector(const vector<Computer> &input){_Computer = input;}

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
    QString path = "ComputerScience.sqlite";
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        cout << "dbconnection found " << endl;

        //Do stuff...
    }
    else
    {
        cout << "dbconnection not found" << endl;
    }
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();

    if(_db.open())
    {
        cout << "opened!" << endl;
        QSqlQuery qry(_db);
        qry.prepare("INSERT INTO Computers(Name, yearBuilt, Type, Built)"
                    "VALUES(:C_Name,:C_yearBuilt,:C_Type,:C_Built)");
        qry.bindValue(":C_Name",qsName);
        qry.bindValue(":C_yearBuilt",input.getYearBuilt());
        qry.bindValue(":C_Type",qsType);
        qry.bindValue(":C_Built",qsBuilt);
        //qry.exec();
        if( !qry.exec() )
            //qDebug() << qry.lastError().text();

            cout << "error inserting into database";
        else
        {
            qDebug( "Inserted!" );
            cout << "inserted! " << endl;
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::removeFromComputers(const Computer &input)
{
    cout << "name: " << input.getName() << endl;
    QString qsName = QString::fromStdString(input.getName());
    QString path = "ComputerScience.sqlite";
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        cout << "dbconnection found " << endl;

        //Do stuff...
    }
    else
    {
        cout << "dbconnection not found" << endl;
    }
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();

    if(_db.open())
    {
        cout << "opened!" << endl;
        QSqlQuery qry(_db);
        qry.prepare("DELETE FROM Computers"
                    "WHERE Name=:C_Name");
        qry.bindValue(":C_Name",qsName);
        //qry.exec();
        if( !qry.exec() )
            //qDebug() << qry.lastError().text();

            cout << "error removing from database";
        else
        {
            qDebug( "Removed" );
            cout << "Removed! " << endl;
        }
    }
    else
    {
        cout << "not openajsd ajsln " << endl;
    }
}
