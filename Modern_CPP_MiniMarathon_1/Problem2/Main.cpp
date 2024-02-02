#include "Functionalities.h"
#include "CustomMessageException.h"
#include <array>

int main() {
    LoanPointerContainer data;
    createObjects(data);
    try {
        std::array<int, 4> result = valueCount(data);
        std::cout << "\nCount of Loan Intent: " << "{Education: " << result[0] << ", Personal: " << result[1] 
                                                << ", Medical: " << result[2] << ", Venture: " << result[3] << "}" 
                                                <<std::endl;
        highestInterestRateForAcceptedLoans(data);
        float answer = getContainerMatchesIntent(data, LoanIntent::MEDICAL);
        std::cout << "Max Interest Rate: " << answer << std::endl;
    }
    catch(CustomMessageException e) {
        std::cerr << e.what() << '\n';
    }
}