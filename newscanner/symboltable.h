// Singletons rule

#pragma once

#include <algorithm>
#include <map>
#include "ast.h"

class SymbolTable
{
    public:
        static SymbolTable& getInstance();
        // destroy these guys
        SymbolTable(SymbolTable const&) = delete;
        void operator=(SymbolTable const&) = delete;
        
        AstVal* lookup(const std::string& key);

        void insert(const std::string& key, AstVal* val);

    private:
        ~SymbolTable(); 
        // let string be literal to avoid memory mixups
        std::map<std::string, AstVal*> table;
        SymbolTable();
};

