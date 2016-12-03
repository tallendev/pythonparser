#include "symboltable.h"

SymbolTable::SymbolTable()
{
    push();
}

void SymbolTable::push()
{
    tables.emplace_front();
}

void SymbolTable::pop()
{
    tables.pop_front();
}

SymbolTable& SymbolTable::getInstance()
{
    static SymbolTable instance;
    return instance;
}

AstVal* SymbolTable::lookup(AstName* name)
{
    AstVal* ret = NULL; 
    std::list<std::map<std::string, AstVal*>>::iterator i = name->isGlobal() ? tables.end()-- : tables.begin();
    while (!ret && i != tables.end())
    {
        std::map<std::string, AstVal*>::iterator val = i->find(name->getName());
        if (val != i->end())
        {
            ret = val->second;
            if (ret->isFunc())
            {
                break;
            }
            else if (ret->isFloat())
            {
                ret = new AstDouble(ret->castToDouble());
            }
            else
            {
                ret = new AstInt(ret->castToInt());
            }
        }
        else
        {
            i++;
        }
    }
    return ret;
}

void SymbolTable::insert(AstName* name, AstVal* val)
{
    std::map<std::string, AstVal*>& map = name->isGlobal() ? tables.back() : tables.front();
    std::map<std::string, AstVal*>::iterator entry = map.find(name->getName());
    if (entry != map.end())
    {
        delete map[name->getName()];
    }
    map[name->getName()] = val;
}

SymbolTable::~SymbolTable()
{
    // right side is unique, needs to die at end.
    std::for_each(tables.begin(), tables.end(), [&](const std::map<std::string, AstVal*> table)
    {
        std::for_each(table.begin(), table.end(), 
                       [&](const std::pair<std::string, AstVal*>& ref) 
                           {
                               delete ref.second;
                           });
    });
}
