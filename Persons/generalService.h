#ifndef GENERALSERVICE_H
#define GENERALSERVICE_H
#include "person.h"
#include "computer.h"

class generalService
{
public:
    generalService();
    string toLower(const string& toLowerString);
    void setProgram(const string& command);
    bool getProgram() const;
private:
    bool _program;
};

#endif // GENERALSERVICE_H
