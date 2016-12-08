#include "dbmanager.h"
#include <QVariant>
//#include <QSqlQuery>
#include <Qdebug>
//b#include "computer.h"

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
    getConnections();
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
        _computers.push_back(temp);
    }
}

vector<Person> DbManager::getPVector() const {return _persons;}

void DbManager::getConnections()
{

    const QString path = "ComputerScienceBackup.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    QString s = "select Connections.ID, Persons.ID as 'PID', Persons.Name as 'PName', Computers.ID as 'CID', Computers.Name as 'CName' from Persons INNER JOIN Connections on Persons.ID=Connections.PersonID INNER JOIN Computers on Connections.ComputerID=Computers.ID";
    QSqlQuery query(_db);
    query.exec(s);
    Connection temp;
    while (query.next())
    {
        int personid = query.value("PID").toInt();
        cout << personid;
        //temp.setPersonID(personid);

        string Pname = query.value("PName").toString().toStdString();
        temp.setPersonName(Pname);

        int computerid = query.value("CID").toInt();
        cout << computerid;
        //temp.setComputerID(personid);

        //string Pname = query.value("PName").toString().toStdString();
        //temp.setPersonName(Pname);




        //int computerid = query.value("computerID").toInt();
        //temp.setComputerID(computerid);
        cout << computerid << endl;

        _connections.push_back(temp);
    }
}

vector<Computer> DbManager::getCVector() const {return _computers;}

bool DbManager::isOpen() const {return _db.isOpen();}

void DbManager::setVector(const vector<Person> &input) {_persons = input;}

void DbManager::setCVector(const vector<Computer> &input){_computers = input;}

void DbManager::changeData()
{

}
void DbManager::insertIntoComputer(const Computer &input)
{
    QString qsName = QString::fromStdString(input.getName());
    QString qsType= QString::fromStdString(input.getType());
    QString qsBuilt = QString::fromStdString(input.getBuilt());
    QString path = "ComputerScienceBackup.sqlite";
    /* nota seinna mögulega
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        //cout << "dbconnection found " << endl;

    }
    else
    {
        cout << "dbconnection not found" << endl;
    }*/

    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    if(_db.open())
    {
        QSqlQuery qry(_db);
        qry.prepare("INSERT INTO Computers(Name, yearBuilt, Type, Built)"
                    "VALUES(:C_Name,:C_yearBuilt,:C_Type,:C_Built)");
        qry.bindValue(":C_Name",qsName);
        qry.bindValue(":C_yearBuilt",input.getYearBuilt());
        qry.bindValue(":C_Type",qsType);
        qry.bindValue(":C_Built",qsBuilt);
        //qry.exec();
        if( !qry.exec() )
        {
            //qDebug() << qry.lastError().text();
            cout << "error inserting into database";
        }

    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::removeFromComputers(const Computer &input)
{
    QString qsName = QString::fromStdString(input.getName());
    QString path = "ComputerScienceBackup.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();

    if(_db.open())
    {
        QSqlQuery qry(_db);
        qry.prepare("DELETE FROM Computers WHERE Name=:C_Name");
        qry.bindValue(":C_Name",qsName);
        if( !qry.exec() )
            //qDebug() << qry.lastError().text();
            cout << "error removing from database";
        else
        {
            qry.exec();
            cout << "Removed " << input.getName() << endl;
        }
    }
    else
    {
        cout << "not openajsd ajsln " << endl;
    }
}

void DbManager::removeFromPersons(const Person &input)
{
    QString qsName = QString::fromStdString(input.getName());
    QString path = "ComputerScienceBackup.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    string asd = "sadasd";
    if(_db.open())
    {
        QSqlQuery qry(_db);

        qry.prepare("DELETE FROM Persons WHERE Name=:C_Name");
        qry.bindValue(":C_Name",qsName);
        if( !qry.exec() )
            //qDebug() << qry.lastError().text();
            cout << "error removing from database";
        else
        {
            qry.exec();
            cout << "Removed " << input.getName() << endl;
        }
    }
    else
    {
        cout << "not openajsd ajsln " << endl;
    }
}

void DbManager::insertIntoPerson(const Person &input)
{
    QString qsName = QString::fromStdString(input.getName());
    QString qsGender= QString::fromStdString(input.getGender());
    QString path = "ComputerScienceBackup.sqlite";
    /* nota seinna mögulega
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        //cout << "dbconnection found " << endl;

    }
    else
    {
        cout << "dbconnection not found" << endl;
    }*/

    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    if(_db.open())
    {
        QSqlQuery qry(_db);
        qry.prepare("INSERT INTO Persons(Name, Gender, birthYear, deathYear)"
                    "VALUES(:P_Name,:P_Gender,:P_BirthYear,:P_DeathYear)");
        qry.bindValue(":P_Name",qsName);
        qry.bindValue(":P_Gender",qsGender);
        qry.bindValue(":P_BirthYear",input.getBirthYear());
        qry.bindValue(":P_DeathYear",input.getDeathYear());
        //qry.exec();
        if( !qry.exec() )
        {
            //qDebug() << qry.lastError().text();
            cout << "error inserting into database";
        }

    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::changePerson(const Person& input, const int personIndex)
{
    Person oldPerson = _persons[personIndex];
    QString qsOldName = QString::fromStdString(oldPerson.getName());
    QString qsName = QString::fromStdString(input.getName());
    QString qsGender = QString::fromStdString(input.getGender());
    QString path = "ComputerScience.sqlite";
    /* nota seinna mögulega
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        //cout << "dbconnection found " << endl;

    }
    else
    {
        cout << "dbconnection not found" << endl;
    }*/

    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    const QString SQLCommand = "UPDATE Persons SET Name = :P_Name, "
                               "Gender = :P_Gender , birthYear = :P_BirthYear,  deathYear = "
                               ":P_DeathYear WHERE Name = :P_OldName";
    if(_db.open())
    {
        QSqlQuery qry(_db);
        if(qry.prepare(SQLCommand))
        {
            qry.bindValue(":P_Name",qsName);
            qry.bindValue(":P_Gender",qsGender);
            qry.bindValue(":P_BirthYear",input.getBirthYear());
            qry.bindValue(":P_DeathYear",input.getDeathYear());
            qry.bindValue(":P_OldName",qsOldName);
            qDebug() << qsName;
            qry.exec();
            if( !qry.exec() )
            {
                //cout << qry.lastError().text();
                cout << "error updating into database";
            }
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::changeComputer(const Computer& input, const int computerIndex)
{
    Computer oldComputer = _computers[computerIndex];
    QString qsOldName = QString::fromStdString(oldComputer.getName());
    QString qsName = QString::fromStdString(input.getName());
    QString qsType = QString::fromStdString(input.getType());
    QString qsBuilt = QString::fromStdString(input.getBuilt());
    QString path = "ComputerScience.sqlite";
    /* nota seinna mögulega
    if( QSqlDatabase::contains( "dbconnection" ) )
    {
        //cout << "dbconnection found " << endl;

    }
    else
    {
        cout << "dbconnection not found" << endl;
    }*/

    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    const QString SQLCommand = "UPDATE Computers SET Name = :C_Name, "
                               "yearBuilt = :C_YearBuilt ,  Type = :C_Type,  Built = "
                               ":C_Built WHERE Name = :C_OldName";
    if(_db.open())
    {
        QSqlQuery qry(_db);
        if(qry.prepare(SQLCommand))
        {
            qry.bindValue(":C_Name",qsName);
            qry.bindValue(":C_YearBuilt", input.getYearBuilt());
            qry.bindValue(":C_Type",qsType);
            qry.bindValue(":C_Built",qsBuilt);
            qry.bindValue(":C_OldName",qsOldName);
            qDebug() << qsName;
            qry.exec();
            if( !qry.exec() )
            {
                //cout << qry.lastError().text();
                cout << "error updating into database";
            }
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}
