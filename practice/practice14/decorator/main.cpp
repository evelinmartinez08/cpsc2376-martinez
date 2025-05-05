#include <iostream>
#include <memory>
#include "SimplePurchase.h"
#include "TaxDecorator.h"
#include "ShippingFeeDecorator.h"
#include "DiscountDecorator.h"

int main() {
    double cost;
    std::cout << "Enter the base cost of your purchase: $";
    std::cin >> cost;

    std::shared_ptr<Purchase> purchase = std::make_shared<SimplePurchase>(cost);

    int choice;
    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Add Tax\n";
        std::cout << "2. Add Shipping Fee\n";
        std::cout << "3. Apply Discount\n";
        std::cout << "4. Finalize Purchase\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                purchase = std::make_shared<TaxDecorator>(purchase);
                break;
            case 2:
                purchase = std::make_shared<ShippingFeeDecorator>(purchase);
                break;
            case 3:
                purchase = std::make_shared<DiscountDecorator>(purchase);
                break;
            case 4:
                std::cout << "Final cost: $" << purchase->getCost() << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice, try again." << std::endl;
        }
    }
}
 