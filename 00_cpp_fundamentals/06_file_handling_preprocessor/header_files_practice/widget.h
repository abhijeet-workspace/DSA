// widget.h
// Declaration of Widget class; non-inline member functions defined in widget.cpp
#pragma once

#include <string>

class Widget {
public:
    explicit Widget(std::string name);
    ~Widget();

    // non-inline method (defined in .cpp to keep header lightweight)
    std::string name() const;

    // inline small method
    int id() const { return id_; }

private:
    std::string name_;
    int id_ = 0;
};
