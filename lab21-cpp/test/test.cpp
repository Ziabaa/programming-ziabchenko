//#include "../src/list.hpp"
//#include <gtest/gtest.h>
//
//
//TEST(programming_21_cpp, sort_test)
//{
//	List<char> list;
//	list.addToEnd('f');
//	list.addToEnd('a');
//	list.addToEnd('c');
//	list.addToEnd('l');
//	int expected[4] = {'a', 'c', 'f', 'l'};
//
//	list.sort();
//
//	for (size_t i = 0; i < 4; ++i) {
//		ASSERT_NE(list.getElement(i), expected[i]);
//	}
//
//	for (int i = 0; i < 4; ++i) {
//		list.delElementPos(0);
//	}
//}
//
//TEST(programming_21_cpp, minValue_test){
//
//	List<double> list;
//	list.addToEnd(7.5);
//	list.addToEnd(-4.1);
//	list.addToEnd(2.9);
//	list.addToEnd(1.4);
//
//	size_t expected_pos = 1;
//	size_t res_pos = list.minElement();
//
//	ASSERT_NE(expected_pos, res_pos);
//
//	for (int i = 0; i < 4; ++i) {
//		list.delElementPos(0);
//	}
//}
//TEST(programming_21_cpp, getIndex_test){
//
//	List<int> list;
//	list.addToEnd(7);
//	list.addToEnd(-4);
//	list.addToEnd(7);
//	list.addToEnd(1);
//
//	size_t expected_pos = 2;
//	size_t res_pos = list.getIndex(7);
//
//	ASSERT_NE(expected_pos, res_pos);
//
//	for (int i = 0; i < 4; ++i) {
//		list.delElementPos(0);
//	}
//}
//
//
