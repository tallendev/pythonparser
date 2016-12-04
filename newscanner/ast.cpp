//  Declarations for an AST calculator
//  From "flex & bison", fb3-1, by John Levine
//  Adapted by Brian Malloy
#include "ast.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

// output file
extern std::ofstream ast_out;

// length of id
#define ID_LEN 11

// poor man's unique id
#define NODE_ID       "a" << this
#define LEFT_NODE_ID  "a" << getLeft()
#define RIGHT_NODE_ID "a" << getRight()
class AstVal;
class AstInt;

//Ast
Ast::Ast() {}
Ast::~Ast() {} 
Ast* Ast::getLeft()     const { throw std::string("No Left"); }
Ast* Ast::getRight()    const { throw std::string("No Right"); }

AstVal::AstVal() : Ast() {} 
AstVal::~AstVal() {}
void AstVal::print_node(const std::string& s) const
{
    ast_out << NODE_ID << "[label=\"" << s << "\"]" << std::endl;
}

AstSuite::AstSuite(Ast* node) : AstNode(node, nullptr) {}
AstSuite::AstSuite(Ast* node, AstSuite* nnode) : AstNode(node, nnode) {}
AstSuite::~AstSuite() { delete getLeft(); if(getRight()) delete getRight(); }
void AstSuite::print_node(const std::string& s) const { }
AstVal* AstSuite::eval()
{
    if (!getLeft())
    {
        throw unsupported_exception();
    }
    delete getLeft()->eval();
    AstVal* ret = nullptr;
    if (getRight())
    {
        ret = getRight()->eval();
    }
    return ret;
}

AstFuncdef::AstFuncdef(AstName* n, AstSuite* f) : AstNode(n, f) {}
AstFuncdef::~AstFuncdef() {}
void AstFuncdef::print_node(const std::string& s) const {}
AstVal* AstFuncdef::eval()
{
    if (!getRight()) throw unsupported_exception();
    AstName* name = ((AstName*)getLeft());
    AstName* n = new AstName(name->getName());
    // surrender pointers to other node
    AstVal* f = (AstVal*) new AstFunc((AstSuite*)getRight());
    SymbolTable::getInstance().insert(name, f);
    print_node(name->getName());
    return n; // return name node i guess? 
}

AstFunc::AstFunc(AstSuite* f) : AstVal(), def(f) {}
AstFunc::~AstFunc() { delete def; }
void AstFunc::print_node(const std::string& s) const
{
    ast_out << NODE_ID << "[label=\"" << s << "()" << "\"]" << std::endl;
}
AstVal* AstFunc::eval()
{
    SymbolTable::getInstance().push();
    AstVal* ret = def->eval();
    SymbolTable::getInstance().pop();
    return ret;
}
int AstFunc::isFloat() { return 0; }
int AstFunc::isFunc() { return 1; }
double AstFunc::castToDouble() { throw unsupported_exception(); }
int AstFunc::castToInt() { throw unsupported_exception(); }


// AstReturn
AstReturn::AstReturn(Ast* node) : AstSuite(node) {}
AstVal* AstReturn::eval()
{
    if (!getLeft()) throw unsupported_exception();
    return getLeft()->eval();
}

//AstName
AstName::AstName(std::string* str) : name(str), global(0){}
AstName::AstName(std::string& str) : name(new std::string(str)), global(0){}
AstName::~AstName() { delete name; }
std::string& AstName::getName() { return *name; }

void AstName::makeGlobal()
{
    global = 1;
}

AstVal* AstName::eval() 
{
    SymbolTable& s = SymbolTable::getInstance();
    if (isGlobal())
    {
        s.globalize(this);
        global = 0;
    }
    AstVal* temp = s.lookup(this);
    if (temp)
    {
        if (temp->isFunc())
        {
            temp = temp->eval();
        }
        print_node(*name);
        return temp;
    }
    else
    {
        throw name_exception();
    }
    
}

int AstName::isGlobal()
{
    return global;
}

double AstName::castToDouble()
{
    AstVal* val = SymbolTable::getInstance().lookup(this);
    if (val->isFunc()) throw unsupported_exception();
    double out = val->castToDouble();
    delete val;
    return out;
}

int AstName::isFunc()
{
    AstVal* val = SymbolTable::getInstance().lookup(this);
    int func = val->isFunc();
    if (!func) delete val;
    return func;
}

int AstName::castToInt()
{
    AstVal* val = SymbolTable::getInstance().lookup(this);
    if (val->isFunc()) throw unsupported_exception();
    int out = val->castToInt();
    delete val;
    return out;
}

int AstName::isFloat()
{
    AstVal* val = SymbolTable::getInstance().lookup(this);
    int out = 0;
    if (val && !val->isFunc())
    {
        out = val->isFloat();
        delete val;
    }
    return out;
}

//AstStr
AstStr::AstStr(std::string* string) : str(string) {}
AstStr::AstStr(std::string& string) : str(new std::string(string)) {}
AstStr::~AstStr() { delete str; }

AstVal* AstStr::eval() 
{ 
    return new AstStr(*str); 
}

int AstStr::isFunc() { return 0; }

double AstStr::castToDouble()
{
    throw unsupported_exception();
}

int AstStr::castToInt()
{
    throw unsupported_exception();
}

int AstStr::isFloat()
{
    return 0;
}

//AstInt
AstInt::AstInt(int n) : AstVal(), number(n) {} 
AstInt::AstInt(AstInt* n) : AstVal(), number(n->number) {}
AstInt::~AstInt() {}
AstVal* AstInt::eval() 
{ 
    const std::string str = std::to_string(number);
    print_node(str);
    return new AstInt(this);
}        
int AstInt::isFloat()
{
    return 0;
}

double AstInt::castToDouble()
{
    return number;
}

int AstInt::castToInt()
{
    return number;
}

int AstInt::isFunc() { return 0; }

//AstDouble
AstDouble::AstDouble(double n) : AstVal(), number(n) {} 
AstDouble::AstDouble(AstDouble* n) : AstVal(), number(n->number) {} 
AstDouble::~AstDouble() {}
AstVal* AstDouble::eval() 
{ 
    const std::string str = std::to_string(number);
    print_node(str);
    return new AstDouble(this); 
}

int AstDouble::isFunc() { return 0; }
int AstDouble::isFloat()
{
    return 1;
}

double AstDouble::castToDouble()
{
    return number;
}

int AstDouble::castToInt()
{
    return number;
}

//AstNode
AstNode::AstNode(Ast* l, Ast* r) : Ast(), l(l), r(r) {}
AstNode::~AstNode() {}
Ast* AstNode::getLeft()  const { return l; }
Ast* AstNode::getRight() const { return r; }

//AstBinary
AstBinary::AstBinary(Ast* l, Ast* r) : AstNode(l, r) {} 
// deletes both nodes or binary ops
AstBinary::~AstBinary() { delete getLeft(); delete getRight(); }

void AstBinary::print_node(const std::string& s) const
{
    ast_out << NODE_ID << "[label=\"" << s << "\"]" << std::endl;
    ast_out << NODE_ID << " -> " << LEFT_NODE_ID << std::endl;
    ast_out << NODE_ID << " -> " << RIGHT_NODE_ID << std::endl;
}

AstVal* AstBinary::eval()
{
    getLeft() && getRight() ? 0 : throw unsupported_exception();
    AstVal* l = getLeft()->eval(); 
    AstVal* r; 
    try
    {
        r = getRight()->eval(); 
    }
    catch(std::exception& e)
    {
        delete l;
        throw;
    }
    AstVal* b;
    if (l->isFloat() || r->isFloat())
    {
        b = real_eval(l->castToDouble(), r->castToDouble());
    }
    else
    {
        b = real_eval(l->castToInt(), r->castToInt());
    }
    delete l;
    delete r;
    return b;
}

//AstAssign
AstAssign::AstAssign(AstName* l, Ast* r) : AstNode(l, r) {}
AstAssign::~AstAssign() { delete getLeft(); delete getRight(); }
void AstAssign::print_node(const std::string& s) const
{
    ast_out << NODE_ID << "[label=\"" << s << "\"]" << std::endl;
    ast_out << NODE_ID << " -> " << ((AstName*)getLeft())->getName() << std::endl;
    ast_out << NODE_ID << " -> " << RIGHT_NODE_ID << std::endl;
}
AstVal* AstAssign::eval()
{
    AstName* l = (AstName*)getLeft();
    AstVal* r = getRight()->eval();
    AstVal* b;
    AstVal* retval;
    AstVal* val = SymbolTable::getInstance().lookup(l);
    if (!val)
    {
        throw name_exception();
    }
    if (val->isFloat() || r->isFloat())
    {
        retval = real_eval(val->castToDouble(), r->castToDouble());
    }
    else
    {
        retval = real_eval(val->castToInt(), r->castToInt());
    }
    b = retval->eval();
    if (b->isFloat())
    {
        SymbolTable::getInstance().insert(l, new AstDouble(b->castToDouble()));
    }
    else
    {
        SymbolTable::getInstance().insert(l, new AstInt(b->castToInt()));
    }
    delete retval;
    delete val;
    delete r;
    return b;
}

//AstUnary
AstUnary::AstUnary(Ast* l) : AstNode(l, NULL) {}
// deletes l node for unary ops
AstUnary::~AstUnary() { if(getLeft()) delete getLeft(); }

void AstUnary::print_node(const std::string& s) const
{
    ast_out << NODE_ID << "[label=\"" << s << "\"]" << std::endl;
    ast_out << NODE_ID << " -> " << LEFT_NODE_ID << std::endl;
}
AstVal* AstUnary::eval()
{
    getLeft() ? 0 : throw unsupported_exception();
    AstVal* l = getLeft()->eval();
    AstVal* b;
    if (l->isFloat())
    {
         b = real_eval(l->castToDouble());
    }
    else
    {
        b = real_eval(l->castToInt());
    }
    delete l;
    return b;
}

//AstEqual
AstEqual::AstEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstEqual::eval()
{
    getLeft() && getRight() ? 0 : throw unsupported_exception();
    AstName* l = (AstName*)getLeft();
    AstVal* r = getRight()->eval();
    AstVal* retval;
    AstVal* b;
    if (r->isFloat())
    {
        retval = real_eval(0.0, r->castToDouble());
    }
    else
    {
        retval = real_eval(0, r->castToInt());
    }
    b = retval->eval();
    if (b->isFloat())
    {
        SymbolTable::getInstance().insert(l, new AstDouble(b->castToDouble()));
    }
    else
    {
        SymbolTable::getInstance().insert(l, new AstInt(b->castToInt()));
    }
    delete retval;
    delete r;
    return b;
}
AstVal* AstEqual::real_eval(int l, int r)
{
    print_node("=");
    return (AstVal*) new AstInt(r);
}
AstVal* AstEqual::real_eval(double l, double r)
{
    print_node("=");
    return (AstVal*) new AstDouble(r);
}


//AstPlusEqual
AstPlusEqual::AstPlusEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstPlusEqual::real_eval(int l, int r)
{
    print_node("+=");
    return (AstVal*) new AstPlus(new AstInt(l), new AstInt(r));
}
AstVal* AstPlusEqual::real_eval(double l, double r)
{
    print_node("+=");
    return (AstVal*) new AstPlus(new AstDouble(l), new AstDouble(r));
}

//AstMinusEqual
AstMinusEqual::AstMinusEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstMinusEqual::real_eval(int l, int r)
{
    print_node("-=");
    return (AstVal*) new AstMinus(new AstInt(l), new AstInt(r));
}
AstVal* AstMinusEqual::real_eval(double l, double r)
{
    print_node("-=");
    return (AstVal*) new AstMinus(new AstDouble(l), new AstDouble(r));
}
//AstStarEqual
AstStarEqual::AstStarEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstStarEqual::real_eval(int l, int r)
{
    print_node("*=");
    return (AstVal*) new AstMult(new AstInt(l), new AstInt(r));
}
AstVal* AstStarEqual::real_eval(double l, double r)
{
    print_node("*=");
    return (AstVal*) new AstMult(new AstDouble(l), new AstDouble(r));
}

//AstDivEqual
AstDivEqual::AstDivEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstDivEqual::real_eval(int l, int r)
{
    print_node("/=");
    return (AstVal*) new AstDiv(new AstInt(l), new AstInt(r));
}
AstVal* AstDivEqual::real_eval(double l, double r)
{
    print_node("/=");
    return (AstVal*) new AstDiv(new AstDouble(l), new AstDouble(r));
}

//AstModEqual
AstModEqual::AstModEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstModEqual::real_eval(int l, int r)
{
    print_node("%=");
    return (AstVal*) new AstMod(new AstInt(l), new AstInt(r));
}
AstVal* AstModEqual::real_eval(double l, double r)
{
    print_node("%=");
    return (AstVal*) new AstMod(new AstDouble(l), new AstDouble(r));
}

//AstIntDivEqual
AstIntDivEqual::AstIntDivEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstIntDivEqual::real_eval(int l, int r)
{
    print_node("//=");
    return (AstVal*) new AstIntDiv(new AstInt(l), new AstInt(r));
}
AstVal* AstIntDivEqual::real_eval(double l, double r)
{
    print_node("//=");
    return (AstVal*) new AstIntDiv(new AstDouble(l), new AstDouble(r));
}

//AstExpEqual
AstExpEqual::AstExpEqual(AstName* l, Ast* r) : AstAssign(l, r) {}
AstVal* AstExpEqual::real_eval(int l, int r)
{
    if (r <= 0)
    {
        return real_eval((double) l, (double) r);
    }
    else
    {
        print_node("**=");
        return (AstVal*) new AstExp(new AstInt(l), new AstInt(r));
    }
}
AstVal* AstExpEqual::real_eval(double l, double r)
{
    print_node("**=");
    return (AstVal*) new AstExp(new AstDouble(l), new AstDouble(r));
}

//AstPlus
AstPlus::AstPlus(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstPlus::real_eval(int l, int r)
{
    print_node("+");
    return new AstInt(l + r); 
}
AstVal* AstPlus::real_eval(double l, double r)
{
    print_node("+");
    return new AstDouble(l + r);
}

//AstMinus
AstMinus::AstMinus(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstMinus::real_eval(int l, int r)
{
    print_node("-");
    return new AstInt(l - r);
}
AstVal* AstMinus::real_eval(double l, double r)
{
    print_node("-");
    return new AstDouble(l - r);
}

//AstMult
AstMult::AstMult(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstMult::real_eval(int l, int r)
{
    print_node("*");
    return new AstInt(l * r); 
}
AstVal* AstMult::real_eval(double l, double r)
{
    print_node("*");
    return new AstDouble(l * r); 
}

//AstDiv
AstDiv::AstDiv(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstDiv::real_eval(int l, int r)
{
    print_node("/");
    if (r == 0.0)
    {
        throw div_zero_exception();
    }
    return new AstInt((int)floor((float)(l) / r)); 
}
AstVal* AstDiv::real_eval(double l, double r)
{
    print_node("/");
    if (r == 0.0)
    {
        throw div_zero_exception();
    }
    return new AstDouble(l / r);
}

//AstIntDiv
AstIntDiv::AstIntDiv(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstIntDiv::real_eval(int l, int r)
{
    print_node("//");
    if (r == 0.0)
    {
        throw div_zero_exception();
    }
    return new AstInt(floor((double)l / r));
}
AstVal* AstIntDiv::real_eval(double l , double r)
{
    print_node("//");
    if (r == 0.0)
    {
        throw div_zero_exception();
    }
    return new AstDouble(floor(l / r));
}

//AstMod
AstMod::AstMod(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstMod::real_eval(int l, int r)
{
    print_node("%");
    if (r == 0.0)
    {
        throw div_zero_exception();
    }
    return new AstInt(((l % r) + r) % r);
}
// stolen from python spec
AstVal* AstMod::real_eval(double l, double r)
{
    print_node("%");
    if (r == 0.0)
    {
        throw div_zero_exception();
    }
    double mod = 0;
    mod = fmod (l, r);
    if (mod)
    {
        if ((r < 0) != (mod < 0)) 
        { 
            mod += r;                                                          
        }
    }
    else
    {
        mod = std::copysign(0.0, r);
    }
    return new AstDouble(mod);
}

//AstExp
AstExp::AstExp(Ast* l, Ast* r) : AstBinary(l, r) {}
AstVal* AstExp::real_eval(int l, int r)
{
    if (r <= 0)
    {
        return real_eval((double) l, (double) r);
    }
    else
    {
        print_node("**");
        return new AstInt(pow(l, r));
    }
}
AstVal* AstExp::real_eval(double l, double r)
{
    print_node("**");
    if (l == 0 && r < 0)
    {
        throw div_zero_exception();
    }
    return new AstDouble(pow(l, r));
}

//AstUMin
AstUMin::AstUMin(Ast* l) : AstUnary(l) {}
AstVal* AstUMin::real_eval(int l)
{
    print_node("-");
    return new AstInt(-l);
}
AstVal* AstUMin::real_eval(double l)
{
    print_node("-");
    return new AstDouble(-l);
}

//AstUPlus
AstUPlus::AstUPlus(Ast* l) : AstUnary(l) {}
AstVal* AstUPlus::real_eval(int l)
{
    print_node("+");
    return new AstInt(+l);
}
AstVal* AstUPlus::real_eval(double l)
{
    print_node("+");
    return new AstDouble(+l);
}

//AstUNot
AstUNot::AstUNot(Ast* l) : AstUnary(l) {}
AstVal* AstUNot::real_eval(int l)
{
    print_node("~");
    return new AstInt(~l);
}
AstVal* AstUNot::real_eval(double l)
{
    throw tilde_exception();
}

//AstPrint
AstPrint::AstPrint(Ast* l): AstUnary(l) {}

AstVal* AstPrint::eval()
{
    AstVal* v = NULL;
    // can be replaced with string class if setLeft() implemented
    if (getLeft() == NULL)
    {
        std::cout << std::endl;                        
    }
    else
    {
        v = AstUnary::eval();
    }
    return v;
}

AstVal* AstPrint::real_eval(int l)
{
    std::cout << l << std::endl;
    print_node("print");
    return NULL;
}
AstVal* AstPrint::real_eval(double l)
{
    if (l == (double)(int)l)
    {
        std::cout << std::setprecision(1) << std::fixed << l << std::endl;
        std::cout.unsetf(std::ios_base::fixed);
    }
    else
    {
        std::cout << std::setprecision(12) << l << std::endl;
    }
    print_node("print");
    return NULL;
}
