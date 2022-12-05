/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){
			//tappity tap1("Hello, my name is Slim Shady.");
		}
		virtual void TearDown(){}
};


/* SMOKE TEST/ SANITY TEST (one) */
	TEST(tappityTest, smoke_test)
	{
		ASSERT_TRUE(true);
	}

/* TEST INPUT USING LEN_DIFF()  (six)*/
	TEST(tappityTest, input_perfect_match)
	{
		//give the test input the same input as the refrence
		//this test confirms the refrence is being set in the
			// constructor as well as the input 
		tappity tap1("Hello, my name is Slim Shady.");
		tap1.entry("Hello, my name is Slim Shady.");
		int diff = tap1.length_difference();
		ASSERT_EQ(diff , 0);
	}
	
	TEST(tappityTest, no_input_given)
	{
		//test to see if string is empty by calling compare len
			//before string is populated with entry
		tappity tap1("");
		int diff = tap1.length_difference();
		ASSERT_EQ(diff , 0);
	}

	TEST(tappityTest, input_shorter_non_zero)
	{
		//given two inputs of non zero do we obtain the diff we expect
		tappity tap1("1234567890");
		tap1.entry("1234");
		int diff = tap1.length_difference();
		ASSERT_EQ(diff , 6);
	}

	TEST(tappityTest, ref_shorter_non_zero)
	{
		//given two inputs of non zero do we obtain the diff we expect
		tappity tap1("1234");
		tap1.entry("1234567890");
		int diff = tap1.length_difference();
		ASSERT_EQ(diff , 6);
	}

	TEST(tappityTest, diff_zero_input)
	{
		//given the refrence input do we obtain the diff equal to ref length
		tappity tap1("1234567890");
		int diff = tap1.length_difference();
		ASSERT_EQ(diff , 10);
	}

	TEST(tappityTest, diff_zero_refrence)
	{
		//given the refrence input do we obtain the diff equal to input length
		tappity tap1("");
		tap1.entry("1234567890");
		int diff = tap1.length_difference();
		ASSERT_EQ(diff , 10);
	}

/* TEST INPUT USING ACCURACY()  (eleven)*/
	TEST(tappityTest, perfect_acc_test)
	{
		//this is a happy test to see if the method correctly IDs
			// a perfect match
		std::string str1 = "this is a test string 123.";
		std::string str2 = "this is a test string 123.";
		double acc = 26/26;
		acc = acc * 100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, wrong_case_acc_test)
	{
		//this is a happy test to see if the method correctly IDs
			// a would be perfect match where the case is incorrect
			// resulting in a 0% match 
		std::string str1 = "THIS IS A TEST STRING";
		std::string str2 = "this is a test string";
		double acc = 0/21;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}
	
	TEST(tappityTest, fifty_acc_test_lenth_off)
	{
		//this is a sad test to see if we can ID a 50% match
			//where the error is ommission of part of the 
			//string
		std::string str1 = "12345678901234567890";
		std::string str2 = "1234567890";
		double acc = 10/20;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}
	
	TEST(tappityTest, fifty_acc_test_case_off)
	{
		///this is a sad test to see if we can ID a 50% match
			// where the error is a case difference of part of
			// the string

		std::string str1 = "abcdefghijabcdefghij";
		std::string str2 = "abcdefghijABCDEFGHIJ";
		double acc = 10/20;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, acc_test_beginning_errors)
	{
		//this is a test to see if the method correctly IDs
			// a 75% match with errors in the begining 
		std::string str1 = "abcdefghijabcdefghij";
		std::string str2 = "ABCDEfghiabcdefghij";
		double acc = 15/20;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, acc_test_middle_errors)
	{
		//this is a test to see if the method correctly IDs
			// a 75% match with errors in the middle 
		std::string str1 = "abcdefghijabcdefghij";
		std::string str2 = "abcdefghijABCDEfghij";
		double acc = 15/20;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, acc_test_end_errors)
	{
		//this is a test to see if the method correctly IDs
			// a 75% match with errors in the ending 
		std::string str1 = "abcdefghijfghijabcde";
		std::string str2 = "abcdefghijfghijABCDE";
		double acc = 15/20;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, acc_test_no_ref)
	{
		//this is a test to see if the acc() method
			//works correctly when given an empty 
			//refrence string
		std::string str1 = "";
		std::string str2 = "abcdefghij";
		double acc = 0/10;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, acc_test_no_input)
	{
		//this is a test to see if the acc() method
			//works correctly when given an empty 
			//input string
		std::string str1 = "abcdefghij";
		std::string str2 = "";
		double acc = 0/10;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}

	TEST(tappityTest, acc_test_no_input_ref_is_empty_str)
	{
		//this is a test to see if the acc() method
			//works correctly when given an empty 
			//input string AND empty refrence
		std::string str1 = "";
		std::string str2 = "";
		double acc = 1;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}
	
	TEST(tappityTest, acc_test_extra_characters)
	{
		//this is a test to see if the acc() method
			//works correctly when given an empty 
			//input string
		std::string str1 = "abcdefghij";
		std::string str2 = "abcdefghijabcdefghij";
		double acc = 10/20;
		acc = acc *100;
		tappity tap1(str1);
		tap1.entry(str2);
		double diff = tap1.accuracy();
		ASSERT_EQ(diff , acc);
	}