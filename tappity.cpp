#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase*
tappity::tappity(std::string reference)
  : refer(reference), input("")
{
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string * *
void tappity::entry(std::string in)
{
 input = in;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length * *
int tappity::length_difference()
{
//get difference in length
int diff = refer.length() - input.length();
//return abs of the diff
return abs(diff);
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  int diff = this->length_difference();
  // if the refer and the input are both empty then they are the same and should return 100%
  if(refer.length() == 0 && input.length() == 0){
    return 100;//%
  }

  //if either string is empty simply return the diff
  if(refer.length() == 0 || input.length() == 0){
    return 0;
  }
  //otherwise we want to loop through the length of the largest string minus 
  //the diff
  //get the range we need to loop through without checking which string is larger
  
  int range = input.length() + refer.length() + diff;//2x larger string len
  range = range /2 - diff;//size of smaller string
  // example: in= 13, ref = 20, diff = 7
  // 1. 13 + 20 + 7 = 40 
  // 2. 40 / 2 = 20 -7 = 13  

  int perfect_score = range + diff; // this is set to the size of the larger string
  //start with a perfect score
  int score = perfect_score;

  for (int x = 0; x < range; x++){ //check the min number of chars 13
    if(int(input[x]) != int(refer[x])){
      score--;//deduct for each error
    }
  }
  score = score - diff;//subtract for each char not in the ref
    //also for each char that is extra
  return double((score/perfect_score)*100);
}
