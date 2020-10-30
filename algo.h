#include <stack>
#include <vector>
#include <stdexcept>
#include <string>

class polish_notation_stack {

private:

    int module_ = 0;
    std::stack<std::vector<int> > regular_expression_stack_;
    
    std::vector<int> get_top_expression_();
    std::vector<int> sum_result_(const std::vector<int>& first_expression, const std::vector<int>& second_expression);
    std::vector<int> concatenate_result_(const std::vector<int>& first_expression, const std::vector<int>& second_expression);

public:
    
    static const int INF_VALUE = static_cast<int>(2e9);
    
    void swap(polish_notation_stack& other) {
        std::swap(module_, other.module_);
        std::swap(regular_expression_stack_, other.regular_expression_stack_);
    }

    polish_notation_stack() = default;
    polish_notation_stack(int given_module) : module_(given_module) {}
    polish_notation_stack(const polish_notation_stack& other) : module_(other.module_), regular_expression_stack_(other.regular_expression_stack_) {}
    
    polish_notation_stack(polish_notation_stack&& other) {
        module_ = other.module_;
        regular_expression_stack_ = std::move(other.regular_expression_stack_);
        other.module_ = 0;
    }
    
    polish_notation_stack& operator=(const polish_notation_stack& other) {
        if (this != &other) {
            polish_notation_stack(other).swap(*this);
        }

        return *this;
    }
    
    polish_notation_stack& operator=(polish_notation_stack&& other) {
        if (this != &other) {
            polish_notation_stack(std::move(other)).swap(*this);
        }

        return *this;
    }
    
    size_t get_size() const;
    const std::vector<int>& top() const;
    template<typename T>
    void append_vector(T&& vector_residue);
    void append_symbol(char symbol);
    void make_sum_operation();
    void make_concatenate_operation();
    void make_closure_operation();
    size_t get_minimal_len_equals_l_mod_k(const std::string& input, size_t residue);

};
