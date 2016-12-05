#include "dbmanager.h"

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        cout << "Error: connection with database fail" << endl;
    }
    else
    {
        cout << "Database: connection ok" << endl;
    }
}
bool DbManager::addPerson(const Person& input)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO people (Name) VALUES (:name)");
   //input.bindValue(":name", input);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        cout << "addPerson error:  ";
   }

   return success;
}
