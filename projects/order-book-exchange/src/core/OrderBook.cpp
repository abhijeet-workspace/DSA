#include "core/OrderBook.h"
#include <iostream>
#include "spdlog/spdlog.h"

namespace trading {

OrderBook::OrderBook(std::string symbol) : symbol_(std::move(symbol)) {
    spdlog::info("OrderBook created for symbol: {}", symbol_);
}

void OrderBook::addOrder(const Order& order) {
    std::lock_guard<std::mutex> lock(bookMutex_);
    
    if (order.type == OrderType::MARKET) {
        spdlog::warn("MARKET orders not yet fully implemented, processing as LIMIT at 0/MAX for now");
    }

    if (order.side == Side::BUY) {
        bids_[order.price].push_back(order);
        auto it = std::prev(bids_[order.price].end());
        orderMap_[order.orderId] = {it, order.price, Side::BUY};
        spdlog::debug("Added BUY order {} for {} at {}", order.orderId, order.quantity, order.price);
    } else {
        asks_[order.price].push_back(order);
        auto it = std::prev(asks_[order.price].end());
        orderMap_[order.orderId] = {it, order.price, Side::SELL};
        spdlog::debug("Added SELL order {} for {} at {}", order.orderId, order.quantity, order.price);
    }
    matchOrders();
}

void OrderBook::removeOrder(uint64_t orderId) {
    std::lock_guard<std::mutex> lock(bookMutex_);
    
    auto mapIt = orderMap_.find(orderId);
    if (mapIt != orderMap_.end()) {
        const auto& loc = mapIt->second;
        if (loc.side == Side::BUY) {
            bids_[loc.price].erase(loc.iterator);
            if (bids_[loc.price].empty()) bids_.erase(loc.price);
        } else {
            asks_[loc.price].erase(loc.iterator);
            if (asks_[loc.price].empty()) asks_.erase(loc.price);
        }
        orderMap_.erase(mapIt);
        spdlog::info("Cancelled order {}", orderId);
    } else {
        spdlog::warn("Attempted to cancel unknown order ID: {}", orderId);
    }
}

void OrderBook::matchOrders() {
    while (!bids_.empty() && !asks_.empty()) {
        auto bestBidIt = bids_.begin();
        auto bestAskIt = asks_.begin();

        if (bestBidIt->first >= bestAskIt->first) {
            auto& bidOrder = bestBidIt->second.front();
            auto& askOrder = bestAskIt->second.front();

            uint64_t matchedQuantity = std::min(bidOrder.quantity, askOrder.quantity);
            double matchedPrice = bestAskIt->first; // Match at maker price
            
            spdlog::info("MATCH: {} units of {} at price {}", matchedQuantity, symbol_, matchedPrice);

            bidOrder.quantity -= matchedQuantity;
            askOrder.quantity -= matchedQuantity;

            if (bidOrder.quantity == 0) {
                orderMap_.erase(bidOrder.orderId);
                bestBidIt->second.pop_front();
                if (bestBidIt->second.empty()) bids_.erase(bestBidIt);
            }
            if (askOrder.quantity == 0) {
                orderMap_.erase(askOrder.orderId);
                bestAskIt->second.pop_front();
                if (bestAskIt->second.empty()) asks_.erase(bestAskIt);
            }
        } else {
            break; // Spread > 0, no match
        }
    }
}

void OrderBook::printBook() const {
    std::lock_guard<std::mutex> lock(bookMutex_);
    std::cout << "--- ORDER BOOK: " << symbol_ << " ---" << std::endl;
    std::cout << "ASKS:" << std::endl;
    for (auto it = asks_.rbegin(); it != asks_.rend(); ++it) {
        uint64_t totalQty = 0;
        for (const auto& o : it->second) totalQty += o.quantity;
        std::cout << it->first << " : " << totalQty << std::endl;
    }
    std::cout << "BIDS:" << std::endl;
    for (const auto& bid : bids_) {
        uint64_t totalQty = 0;
        for (const auto& o : bid.second) totalQty += o.quantity;
        std::cout << bid.first << " : " << totalQty << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}

} // namespace trading
