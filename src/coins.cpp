#include "coins.hpp"
#include <iostream>

Coins::Coins(int q, int d, int n, int p)
    : quarters(q), dimes(d), nickels(n), pennies(p) {}

void Coins::deposit_coins(Coins& coins) {
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;
}
Coins Coins::extract_exact_change(const Coins& coins) const {
    int extractedQuarters = (quarters < coins.quarters) ? quarters : coins.quarters;
    int extractedDimes = (dimes < coins.dimes) ? dimes : coins.dimes;
    int extractedNickels = (nickels < coins.nickels) ? nickels : coins.nickels;
    int extractedPennies = (pennies < coins.pennies) ? pennies : coins.pennies;

    return Coins(extractedQuarters, extractedDimes, extractedNickels, extractedPennies);
}

int Coins::total_value_in_cents() const {
    return (quarters * CENTS_PER_QUARTER) + (dimes * CENTS_PER_DIME) +
           (nickels * CENTS_PER_NICKEL) + pennies;
}

void Coins::print(std::ostream& out) const {
    out << "Quarters: " << quarters << ", Dimes: " << dimes
        << ", Nickels: " << nickels << ", Pennies: " << pennies;
}

std::ostream& operator<<(std::ostream& out, const Coins& coins) {
     coins.print(out);
    return out;}
Coins coins_required_for_cents(int amount_in_cents) {
    int q = amount_in_cents / CENTS_PER_QUARTER;
    amount_in_cents %= CENTS_PER_QUARTER;
    int d = amount_in_cents / CENTS_PER_DIME;
    amount_in_cents %= CENTS_PER_DIME;
    int n = amount_in_cents / CENTS_PER_NICKEL;
    amount_in_cents %= CENTS_PER_NICKEL;
    int p = amount_in_cents;

    return Coins(q, d, n, p);
}

void print_Cents(int cents, std::ostream& out) {
    out << cents;
    }

Coins ask_for_coins(std::istream& in, std::ostream& out) {
    int q, d, n, p;
    out << "Enter the number of Quarters: ";
    in >> q;
    out << "Enter the number of Dimes: ";
    in >> d;
    out << "Enter the number of Nickels: ";
    in >> n;
    out << "Enter the number of Pennies: ";
    in >> p;

    return Coins(q, d, n, p);
}

void coins_menu(std::istream& in, std::ostream& out) {
    Coins userCoins(0, 0, 0, 0);

    while (true) {
        out << "\nCoins Menu\n"
            << "1. Deposit Change\n"
            << "2. Extract Change\n"
            << "3. Print Balance\n"
            << "4. Exit\n"
            << "User Input: ";

        int choice;
        in >> choice;

        switch (choice) {
            case 1: {
                out << "Quarters? ";
                int q, d, n, p;
                in >> q;
                out << "Dimes? ";
                in >> d;
                out << "Nickels? ";
                in >> n;
                out << "Pennies? ";
                in >> p;

                Coins depositCoins(q, d, n, p);
                userCoins.deposit_coins(depositCoins);

                out << "Thank you!\n";
                break;
            }
            case 2: {
                out << "Quarters? ";
                int q, d, n, p;
                in >> q;
                out << "Dimes? ";
                in >> d;
                out << "Nickels? ";
                in >> n;
                out << "Pennies? ";
                in >> p;

                Coins extractCoins(q, d, n, p);
                Coins extractedChange = userCoins.extract_exact_change(extractCoins);

                if (extractedChange == extractCoins) {
                    userCoins.deposit_coins(extractCoins);
                    out << "Thank you!\n";
                } else {
                    out << "ERROR: Insufficient Funds\n";
                }
                break;
            }
            case 3:
                out << "$" << userCoins.total_value_in_cents() / 100.0 << "\n";
                out << "Thank you!\n";
                break;
              case 4:
                return;
            default:
                out << "ERROR: Invalid Command\n";
        }
    }
}
