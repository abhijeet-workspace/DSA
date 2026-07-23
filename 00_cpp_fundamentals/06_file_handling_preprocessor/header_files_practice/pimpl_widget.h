// pimpl_widget.h
#pragma once

#include <memory>
#include <string>

class PimplWidget {
public:
    PimplWidget(std::string name);
    ~PimplWidget();

    std::string name() const;

    // copy/move support can be added as needed; omitted for brevity

private:
    struct Impl;
    std::unique_ptr<Impl> impl_; // hides implementation details and reduces build coupling
};
