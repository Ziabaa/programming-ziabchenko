#include "../src/colleague.h"
#include "../src/worker.h"
#include <gtest/gtest.h>


TEST(programming_18_cpp, sort_test){
	const int N = 3;
	Workers * workers = new Workers();
	Colleague * colleague1 = new Colleague(3.2f);
	Colleague * colleague2 = new Colleague(8.5f);
	Colleague * colleague3 = new Colleague(2.2f);
	workers->addElement(0, colleague1);
	delete colleague1;
	workers->addElement(1, colleague2);
	delete colleague2;
	workers->addElement(2, colleague3);
	delete colleague3;


	workers->sort("work_experience");
	float expected_experience[N] = {2.2f, 3.2f, 8.5f};
	Colleague ** alfa = workers->getColleague();
	for (int i = 0; i < N; ++i) {
		ASSERT_NEAR(alfa[i]->getWorkExperience(), expected_experience[i], 0.01f);
	}

	delete workers;
}


TEST(programming_18_cpp, find_withoutInsursnce_test){
	Workers * workers = new Workers();
	Colleague * colleague1 = new Colleague(0, "Fox");
	Colleague * colleague2 = new Colleague(1, "Fox");
	Colleague * colleague3 = new Colleague(0, "Fox");
	workers->addElement(0, colleague1);
	delete colleague1;
	workers->addElement(1, colleague2);
	delete colleague2;
	workers->addElement(2, colleague3);
	delete colleague3;
	size_t expected_count = 2;
	size_t res_count = workers->findCountColleagueInCompany_WithoutInsurance("Fox");

	ASSERT_EQ(res_count, expected_count);
	delete workers;
}

TEST(programming_18_cpp, parse_str_test){
	string input = "0,Google,2.300000,Ivan,Teplyi,dev-good@lal.com,0";
	Colleague * parse_colleague;
	parse_colleague = parseColleague(input);
	ASSERT_EQ(0, parse_colleague->getInsurance());
	ASSERT_EQ("Google", parse_colleague->getNameCompany());
	ASSERT_NEAR(2.3, parse_colleague->getWorkExperience(), 0.01f);
	ASSERT_EQ("Ivan", parse_colleague->getNameColleague());
	ASSERT_EQ("Teplyi", parse_colleague->getSurname());
	ASSERT_EQ("dev-good@lal.com", parse_colleague->getEmail());
	ASSERT_EQ(0, parse_colleague->getEmployCharacteristic());
	delete parse_colleague;
}