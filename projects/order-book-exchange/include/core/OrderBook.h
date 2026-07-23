#pragma once
#include "Order.h"
#include <map>
#include <list>
#include <unordered_map>
#include <string>
#include <mutex>

namespace trading {

class OrderBook {
public:
    explicit OrderBook(std::string symbol);
    
    void addOrder(const Order& order);
    void removeOrder(uint64_t orderId);
    
    void printBook() const;

private:
    std::string symbol_;
    
    // Concurrency protection for this specific order book
    mutable std::mutex bookMutex_;
    
    // Price -> List of Orders (Time priority)
    // Buy orders (Bids) sorted descending
    std::map<double, std::list<Order>, std::greater<double>> bids_;
    
    // Sell orders (Asks) sorted ascending
    std::map<double, std::list<Order>> asks_;
    
    // Fast cancellation map: orderId -> Iterator and Price/Side info
    struct OrderLocation {
        std::list<Order>::iterator iterator;
        double price;
        Side side;
    };
    std::unordered_map<uint64_t, OrderLocation> orderMap_;
    
    void matchOrders();
};

} // namespace trading
