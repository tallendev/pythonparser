// Singletons rule

#pragma once

#include <algorithm>
#include <map>
#include <list>
#include "ast.h"

class SymbolTable
{
    public:
        static SymbolTable& getInstance();
        // destroy these guys
        SymbolTable(SymbolTable const&) = delete;
        void operator=(SymbolTable const&) = delete;
        
        AstVal* lookup(AstName* name);
        void push();
        void pop();
        void insert(AstName* name, AstVal* val);
        void globalize(AstName* name);

    private:
        ~SymbolTable(); 
        // let string be literal to avoid memory mixups
        std::list<std::map<std::string, AstVal*>> tables;
        void __insert(AstName* name, AstVal* val, std::map<std::string, AstVal*>& map);
        SymbolTable();
};

