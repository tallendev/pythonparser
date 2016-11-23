#include "symboltable.h"

SymbolTable& SymbolTable::getInstance()
{
    static SymbolTable instance;
    return instance;
}

AstVal* SymbolTable::lookup(const std::string& key)
{
    AstVal* ret = NULL;
    std::map<std::string, AstVal*>::iterator val = table.find(key);
    if (val != table.end())
    {
        ret = val->second;
        if (ret->isFloat())
        {
            ret = new AstDouble(ret->castToDouble());
        }
        else
        {
            ret = new AstInt(ret->castToInt());
        }
    }
    return ret;
}

void SymbolTable::insert(const std::string& key, AstVal* val)
{
    if (table.find(key) != table.end())
    {
        delete table[key];
    }
    table[key] = val;
}

SymbolTable::~SymbolTable()
{
    // right side is unique, needs to die at end.
    std::for_each(table.begin(), table.end(), 
                   [&](const std::pair<std::string, AstVal*>& ref) 
                       {
                           delete ref.second;
                       });
}

SymbolTable::SymbolTable() {}
