#include "algo.h"


size_t polish_notation_stack::get_size() const {
    return regular_expression_stack_.size();
}

template<typename U>
void polish_notation_stack::append_vector(U&& residue_vector) {
    regular_expression_stack_.push(std::forward<U>(residue_vector));
}

void polish_notation_stack::append_symbol(char symbol) {
    std::vector<int> symbol_vector_of_residue(module_, static_cast<int>(INF_VALUE));
    if (symbol == '1') {
        symbol_vector_of_residue[0] = 0;
    } else {
        symbol_vector_of_residue[1] = 1;
    }
    
    regular_expression_stack_.push(std::move(symbol_vector_of_residue));
}

std::vector<int> polish_notation_stack::get_top_expression_() {
    if (get_size() == 0) {
        throw std::runtime_error("pop_with_empty_stack");
    }

    std::vector<int> answer = regular_expression_stack_.top();
    regular_expression_stack_.pop();
    return answer;
}

std::vector<int> polish_notation_stack::sum_result_(const std::vector<int>& first_expression, const std::vector<int>& second_expression) {
    std::vector<int> summ_expression(module_, static_cast<int>(INF_VALUE));

    for (size_t i = 0; i < module_; ++i) {
        summ_expression[i] = std::min(first_expression[i], second_expression[i]);
    }

    return summ_expression;
}

std::vector<int> polish_notation_stack::concatenate_result_(const std::vector<int>& first_expression, const std::vector<int>& second_expression) {
    std::vector<int> concatenate_expression(module_, static_cast<int>(INF_VALUE));

    for (int i = 0; i < module_; ++i) {
        if (first_expression[i] == INF_VALUE) {
            continue;
        }
        for (int j = 0; j < module_; ++j) {
            if (second_expression[j] == INF_VALUE) {
                continue;
            }
            
            int new_index = (i + j) % module_;

            concatenate_expression[new_index] = std::min(concatenate_expression[new_index], first_expression[i] + second_expression[j]);
        }
    }

    return concatenate_expression;
    
}

const std::vector<int>& polish_notation_stack::top() const {
    if (get_size() == 0) {
        throw std::runtime_error("bad_polish_notation_for_regular_expression");
    }
    return regular_expression_stack_.top();
}

void polish_notation_stack::make_sum_operation() {
    if (get_size() < 2) {
        throw std::runtime_error("bad_polish_notation_for_regular_expression");
    }

    std::vector<int> first_expression = get_top_expression_();
    std::vector<int> second_expression = get_top_expression_();
    
    append_vector(sum_result_(second_expression, first_expression));
}

void polish_notation_stack::make_concatenate_operation() {
    if (get_size() < 2) {
        throw std::runtime_error("bad_polish_notation_for_regular_expression");
    }

    std::vector<int> first_expression = get_top_expression_();
    std::vector<int> second_expression = get_top_expression_();
    
    append_vector(concatenate_result_(second_expression, first_expression));
}

void polish_notation_stack::make_closure_operation() {
    if (get_size() < 1) {
        throw std::runtime_error("bad_polish_notation_for_regular_expression");
    }

    std::vector<int> expression = get_top_expression_();

    std::vector<int> closure_expression(module_, static_cast<int>(INF_VALUE));
    closure_expression[0] = 0;

    int bound = module_ + 1;
    
    std::vector<int> temp_expression = expression; 

    for (int i = 1; i < bound; ++i) {
        closure_expression = sum_result_(closure_expression, temp_expression);
        temp_expression = concatenate_result_(expression, temp_expression);
    }       

    append_vector(closure_expression);
}

size_t polish_notation_stack::get_minimal_len_equals_l_mod_k(const std::string& input, size_t residue) {

    for (char symbol : input) {
        if (symbol == '+') {
            make_sum_operation();
        }

        else if (symbol == '.') {
            make_concatenate_operation();
        }

        else if (symbol == '*') {
            make_closure_operation();
        }

        else {
            append_symbol(symbol);
        }
    }

    if (get_size() != 1) {
        throw std::runtime_error("bad_polish_notation_for_regular_expression");
    }

    return regular_expression_stack_.top()[residue];
}

