#include <gtest/gtest.h>
#include "algo.h"

std::string get_answer_as_string(size_t value) {
  
    std::string answer;

    if (value == polish_notation_stack::INF_VALUE) {
        answer = "INF";
    } else {
        answer = std::to_string(value);
    }

    return answer;
}

TEST(algo_test_1, first_sample) {
    std::string regular_expression = "ab+c.aba.*.bac.+.+*";
    int l = 1;
    int k = 3;
    std::string correct_answer = "4";

    polish_notation_stack solver(k);
    std::string solver_answer;
    try {
        solver_answer = get_answer_as_string(solver.get_minimal_len_equals_l_mod_k(regular_expression, l));
    } catch (std::runtime_error& ) {
        solver_answer = "ERROR";
    }
    
    EXPECT_EQ(solver_answer, correct_answer);
}

TEST(algo_test_2, second_sample) {
    std::string regular_expression = "acb..bab.c.*.ab.ba.+.+*a.";
    int l = 0;
    int k = 3;
    std::string correct_answer = "INF";

    polish_notation_stack solver(k);
    std::string solver_answer;
    try {
        solver_answer = get_answer_as_string(solver.get_minimal_len_equals_l_mod_k(regular_expression, l));
    } catch (std::runtime_error& ) {
        solver_answer = "ERROR";
    }
    EXPECT_EQ(solver_answer, correct_answer);
}

TEST(algo_test_3, bad_polish_notation) {
    std::string regular_expression_1 = "*ab+";
    int l1 = 3;
    int k1 = 14;
    std::string correct_answer = "ERROR";

    polish_notation_stack first_solver(k1);
    std::string first_solver_answer;

    try {
        first_solver_answer = get_answer_as_string(first_solver.get_minimal_len_equals_l_mod_k(regular_expression_1, l1));
    } catch (std::runtime_error& ) {
        first_solver_answer = "ERROR";
    }
    
    EXPECT_EQ(first_solver_answer, correct_answer);

    std::string regular_expression_2 = "ab+ac.";
    int l2 = 23;
    int k2 = 105;
    
    polish_notation_stack second_solver(k2);
    std::string second_solver_answer;

    try {
        second_solver_answer = get_answer_as_string(second_solver.get_minimal_len_equals_l_mod_k(regular_expression_2, l2));
    } catch (std::runtime_error& ) {
        second_solver_answer = "ERROR";
    }

    EXPECT_EQ(second_solver_answer, correct_answer);
}

TEST(algo_test_4, simple_tests) {
    std::string regular_expression = "acbc.acc...*..";
    int l1 = 3;
    int k1 = 5;
    std::string first_correct_answer = "INF";

    polish_notation_stack first_solver(k1);
    std::string first_solver_answer;

     try {
        first_solver_answer = get_answer_as_string(first_solver.get_minimal_len_equals_l_mod_k(regular_expression, l1));
    } catch (std::runtime_error& ) {
        first_solver_answer = "ERROR";
    }
    
    EXPECT_EQ(first_solver_answer, first_correct_answer);

    int l2 = 2;
    int k2 = 25;
    std::string second_correct_answer = "2";

    polish_notation_stack second_solver(k2);
    std::string second_solver_answer;

    try {
        second_solver_answer = get_answer_as_string(second_solver.get_minimal_len_equals_l_mod_k(regular_expression, l2));
    } catch (std::runtime_error& ) {
        second_solver_answer = "ERROR";
    }

    EXPECT_EQ(second_solver_answer, second_correct_answer);
}

TEST(algo_test_5, odd_regular_expression) {
    std::string regular_expression = "1bc.d.aa.a.a.+*a++";
    int l1 = 0;
    int k1 = 17;
    std::string first_correct_answer = "0";

    polish_notation_stack first_solver(k1);
    std::string first_solver_answer;

     try {
        first_solver_answer = get_answer_as_string(first_solver.get_minimal_len_equals_l_mod_k(regular_expression, l1));
    } catch (std::runtime_error& ) {
        first_solver_answer = "ERROR";
    }
    
    EXPECT_EQ(first_solver_answer, first_correct_answer);

    int l2 = 1;
    int k2 = 4;
    std::string second_correct_answer = "1";

    polish_notation_stack second_solver(k2);
    std::string second_solver_answer;

    try {
        second_solver_answer = get_answer_as_string(second_solver.get_minimal_len_equals_l_mod_k(regular_expression, l2));
    } catch (std::runtime_error& ) {
        second_solver_answer = "ERROR";
    }

    EXPECT_EQ(second_solver_answer, second_correct_answer);
    
    int l3 = 5;
    int k3 = 6;
    std::string third_correct_answer = "11";

    polish_notation_stack third_solver(k3);
    std::string third_solver_answer;

    try {
        third_solver_answer = get_answer_as_string(third_solver.get_minimal_len_equals_l_mod_k(regular_expression, l3));
    } catch (std::runtime_error& ) {
        third_solver_answer = "ERROR";
    }

    EXPECT_EQ(third_solver_answer, third_correct_answer);
    int l4 = 5;
    int k4 = 13;
    std::string thourth_correct_answer = "18";

    polish_notation_stack thourth_solver(k4);
    std::string thourth_solver_answer;

    try {
        thourth_solver_answer = get_answer_as_string(thourth_solver.get_minimal_len_equals_l_mod_k(regular_expression, l4));
    } catch (std::runtime_error& ) {
        thourth_solver_answer = "ERROR";
    }

    EXPECT_EQ(thourth_solver_answer, thourth_correct_answer);
}

TEST(algo_test_6, good_regular_expression) {
    std::string regular_expression = "abc..cbabcc.....+*ba..cabb...*aaa...+";
    int l1 = 1;
    int k1 = 5;
    std::string first_correct_answer = "11";

    polish_notation_stack first_solver(k1);
    std::string first_solver_answer;

     try {
        first_solver_answer = get_answer_as_string(first_solver.get_minimal_len_equals_l_mod_k(regular_expression, l1));
    } catch (std::runtime_error& ) {
        first_solver_answer = "ERROR";
    }
    
    EXPECT_EQ(first_solver_answer, first_correct_answer);

    int l2 = 2;
    int k2 = 105;
    std::string second_correct_answer = "2";

    polish_notation_stack second_solver(k2);
    std::string second_solver_answer;

    try {
        second_solver_answer = get_answer_as_string(second_solver.get_minimal_len_equals_l_mod_k(regular_expression, l2));
    } catch (std::runtime_error& ) {
        second_solver_answer = "ERROR";
    }

    EXPECT_EQ(second_solver_answer, second_correct_answer);
    
    int l3 = 1;
    int k3 = 7;
    std::string third_correct_answer = "8";

    polish_notation_stack third_solver(k3);
    std::string third_solver_answer;

    try {
        third_solver_answer = get_answer_as_string(third_solver.get_minimal_len_equals_l_mod_k(regular_expression, l3));
    } catch (std::runtime_error& ) {
        third_solver_answer = "ERROR";
    }

    EXPECT_EQ(third_solver_answer, third_correct_answer);
    int l4 = 4;
    int k4 = 7;
    std::string thourth_correct_answer = "11";

    polish_notation_stack thourth_solver(k4);
    std::string thourth_solver_answer;

    try {
        thourth_solver_answer = get_answer_as_string(thourth_solver.get_minimal_len_equals_l_mod_k(regular_expression, l4));
    } catch (std::runtime_error& ) {
        thourth_solver_answer = "ERROR";
    }

    EXPECT_EQ(thourth_solver_answer, thourth_correct_answer);
}


TEST(get_size_append_vector_and_char_methods_test, series_appendings) {
    int module_value = 5;
    std::vector<int> first_array = {0, 1, 0, 1, 0};
    std::vector<int> second_array(module_value, static_cast<int>(polish_notation_stack::INF_VALUE));
    std::vector<int> symbol_array(module_value, static_cast<int>(polish_notation_stack::INF_VALUE));
    std::vector<int> epsilon_array(module_value, static_cast<int>(polish_notation_stack::INF_VALUE));
    symbol_array[1] = 1;
    epsilon_array[0] = 0;
    size_t expecting_size = 4;

    polish_notation_stack testing_stack(module_value);
    
    testing_stack.append_vector(first_array);
    
    EXPECT_EQ(testing_stack.top(), first_array);

    testing_stack.append_symbol('a');

    EXPECT_EQ(testing_stack.top(), symbol_array);

    testing_stack.append_vector(second_array);

    EXPECT_EQ(testing_stack.top(), second_array);

    testing_stack.append_symbol('1');

    EXPECT_EQ(testing_stack.top(), epsilon_array);
    
    EXPECT_EQ(testing_stack.get_size(), expecting_size);
}

TEST(summary_result_test, simple_test) {
    int module_value = 10;
    std::vector<int> first_array = {20, 30, 11, 0, 1, polish_notation_stack::INF_VALUE, 13, 105, 3, 0};
    std::vector<int> second_array = {13, 105, 234, 17, 20, 100, 20, 1, 0, 1};
    std::vector<int> correct_answer = {13, 30, 11, 0, 1, 100, 13, 1, 0, 0};

    polish_notation_stack testing_stack(module_value);
    testing_stack.append_vector(first_array);
    testing_stack.append_vector(second_array);

    testing_stack.make_sum_operation();
    std::vector<int> solver_answer = testing_stack.top();

    EXPECT_EQ(solver_answer, correct_answer);
}

TEST(concatenate_result_test, simple_concatenation) {
    int module_value = 5;
    std::vector<int> first_array = {polish_notation_stack::INF_VALUE, 13, 3, 4, polish_notation_stack::INF_VALUE};
    std::vector<int> second_array = {0, polish_notation_stack::INF_VALUE, polish_notation_stack::INF_VALUE, polish_notation_stack::INF_VALUE, 23};
    std::vector<int> correct_answer = {36, 13, 3, 4 , polish_notation_stack::INF_VALUE};

    polish_notation_stack testing_stack(module_value);
    testing_stack.append_vector(first_array);
    testing_stack.append_vector(second_array);

    testing_stack.make_concatenate_operation();
    std::vector<int> solver_answer = testing_stack.top();

    EXPECT_EQ(solver_answer, correct_answer);
}

TEST(closure_result_test_1, one_residue_word) {
    int module_value = 5;
    std::vector<int> word = {polish_notation_stack::INF_VALUE, polish_notation_stack::INF_VALUE, 3, polish_notation_stack::INF_VALUE, polish_notation_stack::INF_VALUE};
    std::vector<int> correct_answer = {0, 9, 3, 12, 6};

    polish_notation_stack testing_stack(module_value);
    testing_stack.append_vector(word);
    testing_stack.make_closure_operation();
    std::vector<int> solver_answer = testing_stack.top();

    EXPECT_EQ(solver_answer, correct_answer);
}

TEST(closure_result_test_2, many_residue_word) {
    int module_value = 5;
    std::vector<int> word = {0, 4, polish_notation_stack::INF_VALUE, 1, polish_notation_stack::INF_VALUE};
    std::vector<int> correct_answer = {0, 2, 4, 1, 3};

    polish_notation_stack testing_stack(module_value);
    testing_stack.append_vector(word);
    testing_stack.make_closure_operation();
    std::vector<int> solver_answer = testing_stack.top();

    EXPECT_EQ(solver_answer, correct_answer);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
