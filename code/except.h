#pragma once

#include <exception>

class name_exception: public std::exception
{
        virtual const char* what() const throw()
        {
            return "NameError: name is not defined";
        }
};

class div_zero_exception: public std::exception
{
        virtual const char* what() const throw()
        {
            return "ZeroDivisionError: integer division or modulo by zero";
        }
};

class tilde_exception: public std::exception
{
        virtual const char* what() const throw()
        {
            return "TypeError: bad operand type for unary ~";
        }
};

class unsupported_type_exception: public std::exception
{
        virtual const char* what() const throw()
        {
            return "UnsupportedTypeError: unsupported type";
        }
};

class unsupported_exception: public std::exception
{
        virtual const char* what() const throw()
        {
            return "Unsupported Operation: operation not implemented yet";
        }
};

class negative_exponent_exception: public std::exception
{
        virtual const char* what() const throw()
        {
            return "NegativeExponentError: not yet supported";
        }
};
