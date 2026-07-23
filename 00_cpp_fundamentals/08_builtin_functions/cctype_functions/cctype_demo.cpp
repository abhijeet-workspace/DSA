// Cctype Demo — <cctype>
// Validate password strength and sanitize/normalize free-form text input.
#include <iostream>
#include <cctype>
#include <string>

bool validatePassword(const std::string& password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (std::isupper(static_cast<unsigned char>(c))) hasUpper = true;
        else if (std::islower(static_cast<unsigned char>(c))) hasLower = true;
        else if (std::isdigit(static_cast<unsigned char>(c))) hasDigit = true;
        else if (std::ispunct(static_cast<unsigned char>(c))) hasSpecial = true; // special symbols
    }

    std::cout << "   Password Metrics for \"" << password << "\":\n";
    std::cout << "     Length >= 8:      " << (password.length() >= 8 ? "Pass" : "FAIL") << "\n";
    std::cout << "     Has Uppercase:    " << (hasUpper ? "Pass" : "FAIL") << "\n";
    std::cout << "     Has Lowercase:    " << (hasLower ? "Pass" : "FAIL") << "\n";
    std::cout << "     Has Digit:        " << (hasDigit ? "Pass" : "FAIL") << "\n";
    std::cout << "     Has Special Char: " << (hasSpecial ? "Pass" : "FAIL") << "\n";

    return password.length() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial;
}

std::string sanitizeInput(const std::string& rawText) {
    std::string cleaned;
    bool lastWasSpace = false;

    for (char c : rawText) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isalnum(uc)) {
            cleaned += static_cast<char>(std::tolower(uc)); // keep alnum, lowercase
            lastWasSpace = false;
        } else if (std::isspace(uc)) {
            if (!lastWasSpace && !cleaned.empty()) {
                cleaned += ' '; // collapse runs of whitespace
                lastWasSpace = true;
            }
        }
        // punctuation skipped
    }
    if (!cleaned.empty() && cleaned.back() == ' ') {
        cleaned.pop_back(); // trim trailing space
    }
    return cleaned;
}

int main() {
    std::cout << "=== Built-in Functions: <cctype> ===\n";

    std::cout << "\n1. Password Validation Audit:\n";
    validatePassword("P@ss123"); // fails length
    std::cout << "\n";
    validatePassword("SecureP@ss1234"); // passes all

    std::cout << "\n2. Input Text Normalization:\n";
    std::string dirtyInput = "  Hello,   C++   World!!  123#  ";
    std::cout << "   Original: \"" << dirtyInput << "\"\n";
    std::cout << "   Sanitized: \"" << sanitizeInput(dirtyInput) << "\"\n";

    return 0;
}
