// Stock Price Fluctuation — LC 2034
#include <iostream>
#include <map>
#include <set>

struct StockPrice {
    std::map<int, int> timePrice;
    std::multiset<int> prices;
    int latestTime = 0;

    void update(int timestamp, int price) {
        if (timePrice.count(timestamp)) {
            prices.erase(prices.find(timePrice[timestamp]));
        }
        timePrice[timestamp] = price;
        prices.insert(price);
        latestTime = std::max(latestTime, timestamp);
    }
    int current() { return timePrice[latestTime]; }
    int maximum() { return *prices.rbegin(); }
    int minimum() { return *prices.begin(); }
};

int main() {
    StockPrice sp;
    sp.update(1, 10);
    sp.update(2, 5);
    std::cout << "cur=" << sp.current() << " max=" << sp.maximum() << " (expected 5 10)\n";
    sp.update(1, 3);
    std::cout << "max=" << sp.maximum() << " min=" << sp.minimum() << " (expected 5 3)\n";
    return 0;
}
