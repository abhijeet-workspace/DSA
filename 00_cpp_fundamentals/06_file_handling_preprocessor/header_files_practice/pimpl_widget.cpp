// PimplWidget — PIMPL implementation for pimpl_widget.h
#include "pimpl_widget.h"
#include <string>

struct PimplWidget::Impl { // private details live only in this TU
    std::string name;
    explicit Impl(std::string n) : name(std::move(n)) {}
};

PimplWidget::PimplWidget(std::string name)
    : impl_(std::make_unique<Impl>(std::move(name))) {}

PimplWidget::~PimplWidget() = default; // needed because Impl is incomplete in header

std::string PimplWidget::name() const {
    return impl_->name;
}
