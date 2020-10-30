#include "algo.h"
#include <iostream>

int main() {

    std::string input;
    int k, l;

    std::cin >> input >> k >> l;

    polish_notation_stack solver(k);

    int answer;

    try {
        answer = solver.get_minimal_len_equals_l_mod_k(input, l);

    } catch (std::runtime_error somthing_wrong) {
        
        std::cout << "ERROR\n";
        return 0;
    }


    if (answer == polish_notation_stack::INF_VALUE) {
        std::cout << "INF\n";
    } else {
        std::cout << answer << "\n";
    }

    return 0;
}
