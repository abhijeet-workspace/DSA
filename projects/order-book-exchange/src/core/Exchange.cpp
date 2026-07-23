#include "core/Exchange.h"
#include "spdlog/spdlog.h"
#include <iostream>

namespace trading {

OrderBook* Exchange::getOrCreateBook(const std::string& symbol) {
    std::lock_guard<std::mutex> lock(exchangeMutex_);
    auto it = orderBooks_.find(symbol);
    if (it == orderBooks_.end()) {
        auto book = std::make_unique<OrderBook>(symbol);
        OrderBook* ptr = book.get();
        orderBooks_[symbol] = std::move(book);
        return ptr;
    }
    return it->second.get();
}

void Exchange::submitOrder(const Order& order) {
    OrderBook* book = getOrCreateBook(order.symbol);
    if (book) {
        book->addOrder(order);
    }
}

void Exchange::cancelOrder(const std::string& symbol, uint64_t orderId) {
    std::lock_guard<std::mutex> lock(exchangeMutex_);
    auto it = orderBooks_.find(symbol);
    if (it != orderBooks_.end()) {
        it->second->removeOrder(orderId);
    } else {
        spdlog::warn("Attempted to cancel order on unknown symbol: {}", symbol);
    }
}

void Exchange::printAllBooks() const {
    std::lock_guard<std::mutex> lock(exchangeMutex_);
    std::cout << "=============================" << std::endl;
    std::cout << "      EXCHANGE STATUS        " << std::endl;
    std::cout << "=============================" << std::endl;
    for (const auto& pair : orderBooks_) {
        pair.second->printBook();
    }
}

} // namespace trading
