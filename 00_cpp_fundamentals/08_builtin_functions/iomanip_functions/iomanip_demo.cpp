// Iomanip Demo — <iomanip>
// Format a client invoice with aligned columns and fixed decimal money amounts.
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct InvoiceItem {
    std::string name;
    int quantity;
    double unitPrice;
};

void printInvoice(const std::string& client, const std::vector<InvoiceItem>& items) {
    std::cout << "\n========================================\n";
    std::cout << "CLIENT: " << client << "\n";
    std::cout << "========================================\n";

    std::cout << std::left << std::setw(20) << "Item Name"
              << std::right << std::setw(6) << "Qty"
              << std::setw(12) << "Unit Price"
              << std::setw(12) << "Total" << "\n";

    std::cout << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << "\n"; // divider

    double grandTotal = 0.0;
    std::cout << std::fixed << std::setprecision(2); // money: two decimal places

    for (const auto& item : items) {
        double total = item.quantity * item.unitPrice;
        grandTotal += total;

        std::cout << std::left << std::setw(20) << item.name
                  << std::right << std::setw(6) << item.quantity
                  << std::setw(12) << item.unitPrice
                  << std::setw(12) << total << "\n";
    }

    std::cout << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << "\n";
    std::cout << std::right << std::setw(38) << "GRAND TOTAL:"
              << std::setw(12) << grandTotal << "\n";
    std::cout << "========================================\n";
}

int main() {
    std::cout << "=== Built-in Functions: <iomanip> ===\n";

    std::vector<InvoiceItem> items = {
        {"MacBook Pro M3", 1, 1999.00},
        {"USB-C Adapter", 3, 19.99},
        {"Wireless Mouse", 2, 59.50},
        {"Keyboard Protector", 1, 14.00}
    };

    printInvoice("Abhijeet Singh", items);
    return 0;
}
