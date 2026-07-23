// Widget — class method definitions for widget.h
#include "widget.h"

// external definition for GLOBAL_CONST declared in basics.h
extern const int GLOBAL_CONST = 42;

Widget::Widget(std::string name) : name_(std::move(name)) {} // take ownership

Widget::~Widget() = default;

std::string Widget::name() const { // accessor
    return name_;
}
