#include "symboltable.h"

SymbolTable::SymbolTable()
{
    push();
}

void SymbolTable::push()
{
    std::map<std::string, AstVal*> prev = tables.front();
    tables.emplace_front();
    std::for_each(tables.front().begin(), tables.front().end(), 
                   [&](const std::pair<std::string, AstVal*>& ref) 
                       {
                           if (!ref.second) tables.front()[ref.first] = nullptr;
                       });


}

void SymbolTable::pop()
{
    std::for_each(tables.front().begin(), tables.front().end(), 
                   [&](const std::pair<std::string, AstVal*>& ref) 
                       {
                           if (ref.second) delete ref.second;
                       });

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
    std::list<std::map<std::string, AstVal*>>::iterator i = tables.begin();
    while (!ret && i != tables.end())
    {
        std::map<std::string, AstVal*>::iterator val = i->find(name->getName());
        if (val != i->end())
        {
            ret = val->second;
            if (ret == nullptr)
            {
                i = tables.end();
                i--;
            }
            else if (ret->isFunc())
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
    __insert(name, val, tables.front());
}

void SymbolTable::__insert(AstName* name, AstVal* val, std::map<std::string, AstVal*>& map)
{
    std::map<std::string, AstVal*>::iterator entry = map.find(name->getName());
    if (entry != map.end())
    {
        if (entry->second == nullptr)
        {
            __insert(name, val, tables.back());
            return;
        }
        else
        {
            delete map[name->getName()];
        }
    }
    map[name->getName()] = val;
}


void SymbolTable::globalize(AstName* name)
{
    if (tables.size() > 1)
    {
        insert(name, nullptr);
    }
}

SymbolTable::~SymbolTable()
{
    // right side is unique, needs to die at end.
    std::for_each(tables.begin(), tables.end(), [&](const std::map<std::string, AstVal*> table)
    {
        std::for_each(table.begin(), table.end(), 
                       [&](const std::pair<std::string, AstVal*>& ref) 
                           {
                               if (ref.second)
                                delete ref.second;
                           });
    });
}
