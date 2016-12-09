#include "dbmanager.h"
#include <QVariant>
//#include <QSqlQuery>
#include <Qdebug>
//b#include "computer.h"

DbManager::DbManager()//constructor that gest the connection to the database
{
    if( QSqlDatabase::contains( "dbconnection" ) )          // iI there is already an connection we dont have to connect again
    {
        const QString path = "ComputerScience.sqlite";
        QString dbName = path;
    }
    else
    {           // If the connection does not exist make the connection to the database
        const QString path = "ComputerScience.sqlite";
        _db = QSqlDatabase::addDatabase("QSQLITE", "dbconnection");
        QString dbName = path;
        _db.setDatabaseName(dbName);
        _db.open();
    }
    getPersons();//gets the persons, computers and connections in their vector
    getComputers();
    getConnections();
}
DbManager::~DbManager() {_db.close();}



void DbManager::getPersons()            // Gets the connection and then selects all from the data base and then puts it in a Person vector
{
    const QString path = "ComputerScience.sqlite";
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

        int ID = query.value("ID").toUInt();
        temp.setID(ID);

        _persons.push_back(temp);
    }
}

void DbManager::getComputers()      // Gets the connection and then selects all from the data base and then puts it in a computer vector
{
    const QString path = "ComputerScience.sqlite";
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

        int ID = query.value("ID").toUInt();
        temp.setID(ID);

        _computers.push_back(temp);
    }
}

vector<Person> DbManager::getPVector() const {return _persons;}

void DbManager::getConnections()        // Gets the connection and then selects all from the data base and then puts it in a connection vector
{

    const QString path = "ComputerScience.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    QString s = "select Connections.ID, Persons.ID as 'PID', Persons.Name as 'PName', Computers.ID as 'CID', Computers.Name as 'CName' from Persons INNER JOIN Connections on Persons.ID=Connections.PersonID INNER JOIN Computers on Connections.ComputerID=Computers.ID";
    QSqlQuery query(_db);
    query.exec(s);
    Connection temp;
    while (query.next())
    {
        int connectionid = query.value("ID").toInt();
        temp.setConnectionID(connectionid);

        int personid = query.value("PID").toInt();
        temp.setFromID(personid);

        string Pname = query.value("PName").toString().toStdString();
        temp.setFromName(Pname);

        int computerid = query.value("CID").toInt();
        temp.setToID(computerid);

        string Cname = query.value("CName").toString().toStdString();
        temp.setToName(Cname);

        _connections.push_back(temp);
    }
}
vector<Connection> DbManager::getCOVector() const {return _connections;}//returns the vector of connections
vector<Computer> DbManager::getCVector() const {return _computers;}//returns the vector of computers

bool DbManager::isOpen() const {return _db.isOpen();}// Checks if the connection is open

void DbManager::setVector(const vector<Person> &input) {_persons = input;} // normal set function to set the person vector

void DbManager::setCVector(const vector<Computer> &input){_computers = input;} // normal set function to set the computer vector


void DbManager::insertIntoComputer(const Computer &input)//Takes values of an computer instance in the database
{
    QString qsName = QString::fromStdString(input.getName());//puts the valuse in an qstring
    QString qsType= QString::fromStdString(input.getType());
    QString qsBuilt = QString::fromStdString(input.getBuilt());
    QString path = "ComputerScience.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    if(_db.open())
    {
        QSqlQuery qry(_db);
        qry.prepare("INSERT INTO Computers(Name, yearBuilt, Type, Built)"       //prepares the sql for execution
                    "VALUES(:C_Name,:C_yearBuilt,:C_Type,:C_Built)");
        qry.bindValue(":C_Name",qsName);
        qry.bindValue(":C_yearBuilt",input.getYearBuilt());
        qry.bindValue(":C_Type",qsType);
        qry.bindValue(":C_Built",qsBuilt);
        if( !qry.exec() )
        {
            cout << "error inserting into database";
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::removeFromComputers(const Computer &input) // removing computer from the computers table and the computer vector
{
    QString qsName = QString::fromStdString(input.getName());
    QString path = "ComputerScience.sqlite";
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

void DbManager::removeFromPersons(const Person &input)    // removing person from the computers table and the person vector
{
    QString qsName = QString::fromStdString(input.getName());
    QString path = "ComputerScience.sqlite";
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

void DbManager::removeFromConnections(Connection input)// removing connection from the computers table and the connection vector
{
    QString path = "ComputerScience.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    if(_db.open())
    {
        QSqlQuery qry(_db);

        qry.prepare("DELETE FROM Connections WHERE PersonID = :P_ID AND ComputerID = :C_ID");
        qry.bindValue(":C_ID",input.getToID());
        qry.bindValue(":P_ID",input.getFromID());
        if( !qry.exec() )
            cout << "error removing from database";
        else
        {
            qry.exec();
            cout << "The connection between " << input.getFromName() << " and "
                 << input.getToName() << " has been removed."<<  endl;
        }
    }
    else
    {
        cout << "not openajsd ajsln " << endl;
    }
}


void DbManager::insertIntoConnection(const Connection &input)   // Inserting Conection into the connecion table and the connection vector
{
    QString path = "ComputerScience.sqlite";
    QSqlDatabase _db = QSqlDatabase::database("dbconnection");
    QString dbName = path;
    _db.setDatabaseName(dbName);
    _db.open();
    if(_db.open())
    {
        QSqlQuery qry(_db);
        qry.prepare("INSERT INTO Connections (PersonID, ComputerID)  VALUES (:P_ID, :C_ID)");
        qry.bindValue(":P_ID",input.getFromID());
        qry.bindValue(":C_ID",input.getToID());
        if( !qry.exec() )
        {
            cout << "error inserting into database";
        }

    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::insertIntoPerson(const Person &input)   // Inserting Person into the Person table and the connection vector
{
    QString qsName = QString::fromStdString(input.getName());
    QString qsGender= QString::fromStdString(input.getGender());
    QString path = "ComputerScience.sqlite";
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
            cout << "error inserting into database";
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::changePerson(const Person& input, const int personIndex)    // Modifying/updating a person
{
    Person oldPerson = _persons[personIndex];
    QString qsOldName = QString::fromStdString(oldPerson.getName());
    QString qsName = QString::fromStdString(input.getName());
    QString qsGender = QString::fromStdString(input.getGender());
    QString path = "ComputerScience.sqlite";

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
            qry.exec();
            if( !qry.exec() )
            {
                cout << "error updating into database";
            }
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}

void DbManager::changeComputer(const Computer& input, const int computerIndex)  // Modifying/updating a Computer
{
    Computer oldComputer = _computers[computerIndex];
    QString qsOldName = QString::fromStdString(oldComputer.getName());
    QString qsName = QString::fromStdString(input.getName());
    QString qsType = QString::fromStdString(input.getType());
    QString qsBuilt = QString::fromStdString(input.getBuilt());
    QString path = "ComputerScience.sqlite";
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
            qry.exec();
            if( !qry.exec() )
            {
                cout << "error updating into database";
            }
        }
    }
    else
    {
        cout << "not inserted" << endl;
    }
}

