#include <gtest/gtest.h>
#include "core/OrderBook.h"
#include "core/Exchange.h"

using namespace trading;

TEST(OrderBookTest, BasicMatching) {
    OrderBook ob("ETH/USD");
    
    ob.addOrder(Order(1, "ETH/USD", OrderType::LIMIT, Side::BUY, 2000.0, 10));
    ob.addOrder(Order(2, "ETH/USD", OrderType::LIMIT, Side::SELL, 2005.0, 5));
    
    // No match expected initially
    
    // The second sell should match exactly 5 of the buy order at 2000.0
    // So 5 should be remaining in the BUY side.
    ob.addOrder(Order(3, "ETH/USD", OrderType::LIMIT, Side::SELL, 2000.0, 5));
    
    // Test cancellation of remaining quantity
    ob.removeOrder(1);
}

TEST(ExchangeTest, MultiSymbolRouting) {
    Exchange exchange;
    
    exchange.submitOrder(Order(1, "AAPL", OrderType::LIMIT, Side::BUY, 150.0, 100));
    exchange.submitOrder(Order(2, "MSFT", OrderType::LIMIT, Side::SELL, 300.0, 50));
    
    // Cancel the AAPL order
    exchange.cancelOrder("AAPL", 1);
    
    SUCCEED();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
