// coins_transfer.cpp

#include "coins.hpp"
#include <iostream>

int main() {
    // Step 1: Create two Coins objects
    Coins piggyBank(50, 50, 50, 50);
    Coins pocket(8, 3, 6, 8);

    // Step 2: Print piggyBank and pocket
    std::cout << "Piggy Bank:\n" << piggyBank << "\n\n";
    std::cout << "Pocket:\n" << pocket << "\n\n";

    // Step 3: Buy a bag of chips that costs $1.49
    Coins costOfChips = coins_required_for_cents(149);
    pocket = pocket.extract_exact_change(costOfChips);
    std::cout << "Bought chips for $1.49\n";
    std::cout << "Pocket after purchase:\n" << pocket << "\n\n";

    // Step 4: Transfer $4.05 from piggyBank to pocket
    Coins transferAmount(16, 4, 0, 5);  // $4.05 in coins
    piggyBank = piggyBank.extract_exact_change(transferAmount);
    pocket.deposit_coins(transferAmount);
    std::cout << "Transferred $4.05 from piggyBank to pocket\n";
    std::cout << "Piggy Bank after transfer:\n" << piggyBank << "\n\n";
    std::cout << "Pocket after transfer:\n" << pocket << "\n\n";

    // Step 5: Find loose change in the sofa
    Coins sofa(10, 10, 10, 10);
    piggyBank.deposit_coins(sofa);
    std::cout << "Found loose change in the sofa:\n" << sofa << "\n\n";
    std::cout << "Piggy Bank after finding change in the sofa:\n" << piggyBank << "\n\n";

    // Step 6: Print the dollar-and-cents value of the total balance in piggyBank
    std::cout << "Total balance in piggyBank: $" << piggyBank.total_value_in_cents() / 100.0 << "\n";

    return 0;
}

