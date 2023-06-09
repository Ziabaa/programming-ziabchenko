#include "../src/colleague.hpp"
#include "../src/list.hpp"
#include <gtest/gtest.h>


TEST(programming_22_cpp, sort_test){
	vector<Programmer> input;
	input.push_back(Programmer("rex", 12.4f, senior));
	input.push_back(Programmer("next", 3.5f, middle));
	input.push_back(Programmer("fool", 3.0f, junior));
	input.push_back(Programmer("rex", 21.8f, senior));
	input.push_back(Programmer("next", 0.5f, middle));
	input.push_back(Programmer("fool", 8.4f, junior));
	float expected_val[6] = {0.5f, 3.0f, 3.5f, 8.4f, 12.4f, 21.8f};
	sortProgrammer("work_experience", input);
	for (size_t i = 0; i < 6; ++i) {
		ASSERT_EQ(input[i].work_experience, expected_val[i]);
	}
}

TEST(programming_22_cpp, find_test){
	vector<Translator> input;
	input.push_back(Translator("name", 12.5f, true));
	input.push_back(Translator("name", 5.6f, true));
	input.push_back(Translator("name", 3.0f, true));
	input.push_back(Translator("name", 5.7f, false));
	input.push_back(Translator("name", 3.5f, true));
	float expected_val[2] = {12.5f, 5.6f};
	vector<Translator> find_translator = findTranslatorInCompany_WithSincTranslate_and_WorkExperMoreThenFiveYear(input);
	for (size_t i = 0; i < find_translator.size(); ++i) {
		ASSERT_EQ(find_translator[i].work_experience, expected_val[i]);
	}
}

TEST(programming_22_cpp, merge_test){
	vector<Colleague> input1;
	input1.push_back(Colleague(1.0f));
	input1.push_back(Colleague(2.0f));
	input1.push_back(Colleague(3.0f));

	vector<Colleague> input2;
	input2.push_back(Colleague(4.0f));
	input2.push_back(Colleague(5.0f));
	input2.push_back(Colleague(6.0f));

	float expected_val[6] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

	vector<Colleague> res_merge = merge(input1, input2);

	for (size_t i = 0; i < res_merge.size(); ++i) {
		ASSERT_EQ(res_merge[i].work_experience, expected_val[i]);
	}
}