#pragma once
#include "OrderBook.h"
#include <unordered_map>
#include <string>
#include <memory>
#include <mutex>

namespace trading {

class Exchange {
public:
    Exchange() = default;

    // Route order to the correct order book
    void submitOrder(const Order& order);
    
    // Cancel an existing order
    void cancelOrder(const std::string& symbol, uint64_t orderId);

    // Print all books
    void printAllBooks() const;

private:
    std::unordered_map<std::string, std::unique_ptr<OrderBook>> orderBooks_;
    mutable std::mutex exchangeMutex_; // Protect the unordered_map
    
    OrderBook* getOrCreateBook(const std::string& symbol);
};

} // namespace trading
