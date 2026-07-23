// Algorithm Demo — <algorithm> & <numeric>
// Audit prices with accumulate/min/max/clamp; query sorted stock codes with binary search.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Transaction {
    int id;
    double amount;
};

void auditTransactions(std::vector<double>& prices) {
    double total = std::accumulate(prices.begin(), prices.end(), 0.0); // sum all prices
    auto minIt = std::min_element(prices.begin(), prices.end()); // cheapest
    auto maxIt = std::max_element(prices.begin(), prices.end()); // most expensive

    std::cout << "Audit Stats:\n";
    std::cout << "   Total sales: $" << total << "\n";
    std::cout << "   Min price:   $" << *minIt << " | Max price:   $" << *maxIt << "\n";

    double calculatedTax = total * 0.15; // 15% tax
    double cappedTax = std::clamp(calculatedTax, 5.0, 50.0); // bound into [5, 50]
    std::cout << "   Tax due (15%): $" << calculatedTax
              << " | Capped Tax payment: $" << cappedTax << "\n";
}

void queryWarehouse(std::vector<int>& stockCodes, int queryCode) {
    std::sort(stockCodes.begin(), stockCodes.end()); // binary search needs sorted range
    bool exists = std::binary_search(stockCodes.begin(), stockCodes.end(), queryCode);
    std::cout << "Query Code " << queryCode << ": "
              << (exists ? "AVAILABLE" : "OUT OF STOCK") << "\n";

    if (exists) {
        auto lb = std::lower_bound(stockCodes.begin(), stockCodes.end(), queryCode); // first >= query
        std::cout << "   Indexed at location "
                  << std::distance(stockCodes.begin(), lb) << "\n";
    }
}

int main() {
    std::cout << "=== Built-in Functions: <algorithm> & <numeric> ===\n";

    int x = 5, y = 9;
    std::swap(x, y); // exchange values
    std::cout << "Swapped: x = " << x << ", y = " << y
              << " | GCD(18, 24) = " << std::gcd(18, 24) << "\n";

    std::cout << "\n1. Transaction Price Auditing:\n";
    std::vector<double> prices = {12.99, 45.50, 8.25, 125.00, 22.10};
    auditTransactions(prices);

    std::cout << "\n2. Stock Code Index Queries:\n";
    std::vector<int> codes = {8821, 1024, 9901, 1024, 4532, 7701};
    queryWarehouse(codes, 1024);
    queryWarehouse(codes, 5000);

    return 0;
}
