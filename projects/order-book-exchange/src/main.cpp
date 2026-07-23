#include <iostream>
#include "core/Exchange.h"
#include "spdlog/spdlog.h"
#include <thread>
#include <chrono>

using namespace trading;

int main() {
    // Set global log level to info
    spdlog::set_level(spdlog::level::info);
    spdlog::info("Starting Trading Engine...");

    Exchange exchange;

    exchange.submitOrder(Order(1, "BTC/USD", OrderType::LIMIT, Side::BUY, 50000.0, 10));
    exchange.submitOrder(Order(2, "BTC/USD", OrderType::LIMIT, Side::SELL, 50100.0, 5));
    exchange.submitOrder(Order(3, "BTC/USD", OrderType::LIMIT, Side::BUY, 49900.0, 15));
    
    // Add another pair
    exchange.submitOrder(Order(10, "ETH/USD", OrderType::LIMIT, Side::SELL, 3000.0, 50));
    
    exchange.printAllBooks();

    spdlog::info("Adding aggressive sell order on BTC/USD...");
    exchange.submitOrder(Order(4, "BTC/USD", OrderType::LIMIT, Side::SELL, 49950.0, 12));

    spdlog::info("Canceling remaining 2 units of sell order (ID 4)...");
    exchange.cancelOrder("BTC/USD", 4);

    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // allow logs to flush
    exchange.printAllBooks();

    return 0;
}
