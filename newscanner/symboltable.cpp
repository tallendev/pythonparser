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
    std::for_each(tables.front().begin(), tables.front().end(), 
                   [&](const std::pair<std::string, AstVal*>& ref) 
                       {
                           if (ref.second)
                            delete ref.second;
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
    int iters = 0;
    AstVal* ret = NULL; 
    std::list<std::map<std::string, AstVal*>>::iterator i = tables.begin();
    while (!ret && i != tables.end())
    {
        std::map<std::string, AstVal*>::iterator val = i->find(name->getName());
        std::cout << val->first << std::endl;
        if (val != i->end())
        {
            ret = val->second;
            if (ret == nullptr)
            {
                std::cout << "iters " << iters++ << std::endl;
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
    if (name->getName().find_first_not_of(' ') != std::string::npos)
        throw unsupported_exception();
    std::cout << name->getName() << std::endl;
    std::map<std::string, AstVal*>::iterator entry = map.find(name->getName());
    std::map<std::string, AstVal*>::iterator last = map.end();
    if (last != entry)
        last--;
    if (entry != map.end())
    {
        if (entry->second == nullptr)
        {
            map = tables.back();
            __insert(name, val, map);
            return;
        }
        else
        {
            delete map[name->getName()];
        }
        map[name->getName()] = val;
    }
}


void SymbolTable::globalize(AstName* name)
{
    std::cout << tables.size() << std::endl;
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
