#pragma once
#include <string>
#include <cstdint>
#include <chrono>

namespace trading {

enum class OrderType {
    MARKET,
    LIMIT
};

enum class Side {
    BUY,
    SELL
};

struct Order {
    uint64_t orderId;
    std::string symbol;
    OrderType type;
    Side side;
    double price;
    uint64_t quantity;
    uint64_t timestamp;

    Order(uint64_t id, std::string sym, OrderType t, Side s, double p, uint64_t q)
        : orderId(id), symbol(std::move(sym)), type(t), side(s), price(p), quantity(q) {
        timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }
};

} // namespace trading
