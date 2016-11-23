// definitions in cpp file to save on recompilation, avoid circular dependency
#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "except.h"

class AstVal;

class Ast
{
    public:
        Ast();
        virtual ~Ast();
        virtual Ast* getLeft() const;
        virtual Ast* getRight() const;
        virtual void print_node(const std::string& s) const = 0;
        virtual AstVal* eval() = 0;
};

// value types: names, ints, doubles
class AstVal : public Ast 
{
    public:
        AstVal();
        virtual ~AstVal();
        virtual AstVal* eval() = 0; 
        virtual double castToDouble() = 0;
        virtual int castToInt() = 0;
        virtual int isFloat() = 0;
        virtual void print_node(const std::string& s) const;
};

class AstName : public AstVal
{
    public:
        AstName(std::string* str);
        ~AstName();
        std::string& getName();
        virtual AstVal* eval();
        virtual double castToDouble();
        virtual int castToInt();
        virtual int isFloat();
    private:
        std::string* name;
};

class AstInt : public AstVal
{
    public:
        AstInt(int n); 
        AstInt(AstInt* n);
        virtual ~AstInt();
        virtual AstVal* eval(); 
        virtual int isFloat();
        virtual double castToDouble();
        virtual int castToInt();
        const int number;
};

class AstDouble : public AstVal
{
    public:
        AstDouble(double n); 
        AstDouble(AstDouble* n); 
        virtual ~AstDouble();
        virtual AstVal* eval();
        virtual int isFloat();
        virtual double castToDouble();
        virtual int castToInt();
        const double number;
};

class AstNode : public Ast
{
    public:
        AstNode(Ast* l, Ast* r);
        virtual ~AstNode();
        virtual Ast* getLeft() const;
        virtual Ast* getRight() const;
        virtual AstVal* eval() = 0;
    private:
        Ast *l;
        Ast *r;
};

// Binary operations
class AstBinary : public AstNode 
{
    public:
        AstBinary(Ast* l, Ast* r); 
        ~AstBinary();
        virtual AstVal* eval();
        virtual void print_node(const std::string& s) const;
    private:
        virtual AstVal* real_eval(int, int) = 0;
        virtual AstVal* real_eval(double, double) = 0;
};

// Assignment Operations. Single equals is special
class AstAssign : public AstNode 
{
    public:
        AstAssign(AstName* l, Ast* r);
        ~AstAssign();
        virtual AstVal* eval();
        virtual void print_node(const std::string& s) const;
    private:
        virtual AstVal* real_eval(int, int) = 0;
        virtual AstVal* real_eval(double, double) = 0;
};

// Unary operations.
class AstUnary : public AstNode 
{
    public:
        AstUnary(Ast* l);
        ~AstUnary();
        virtual AstVal* eval();
        virtual void print_node(const std::string& s) const;
    private:
        virtual AstVal* real_eval(int) = 0;
        virtual AstVal* real_eval(double) = 0;
};

class AstEqual : public AstAssign
{
    public:
        AstEqual(AstName* l, Ast* r);
        virtual AstVal* eval();
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstPlusEqual : public AstAssign
{
    public:
        AstPlusEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstMinusEqual : public AstAssign
{
    public:
        AstMinusEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstStarEqual : public AstAssign
{
    public:
        AstStarEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstDivEqual : public AstAssign
{
    public:
        AstDivEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstModEqual : public AstAssign
{
    public:
        AstModEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstIntDivEqual : public AstAssign
{
    public:
        AstIntDivEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstExpEqual : public AstAssign
{
    public:
        AstExpEqual(AstName* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double, double r);
};

class AstPlus : public AstBinary
{
    public:
        AstPlus(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstMinus : public AstBinary
{
    public:
        AstMinus(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstMult : public AstBinary
{
    public:
        AstMult(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstDiv : public AstBinary
{
    public:
        AstDiv(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstIntDiv : public AstBinary
{
    public:
        AstIntDiv(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l , double r);
};

class AstMod : public AstBinary
{
    public:
        AstMod(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};


class AstExp : public AstBinary
{
    public:
        AstExp(Ast* l, Ast* r);
    private:
        virtual AstVal* real_eval(int l, int r);
        virtual AstVal* real_eval(double l, double r);
};

class AstUMin : public AstUnary
{
    public:
        AstUMin(Ast* l);
    private:
        virtual AstVal* real_eval(int l);
        virtual AstVal* real_eval(double l);
};

class AstUPlus : public AstUnary
{
    public:
        AstUPlus(Ast* l);
    private:
        virtual AstVal* real_eval(int l);
        virtual AstVal* real_eval(double l);
};

class AstUNot : public AstUnary
{
    public:
        AstUNot(Ast* l);
    private:
        virtual AstVal* real_eval(int l);
        virtual AstVal* real_eval(double l);
};

// included at bottom to avoid circular dependency
#include "symboltable.h"
