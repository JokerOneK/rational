#include "rational.h"

int main( int argc, char* argv [ ] )


{
    //initializing with constructor(normalizer)
  rational sample1(3, 12), sample2(-200, 120);

  // performing - operator on rational numbers
  sample1 = -sample1;
  sample2 = -sample2;

  //displaying values by using print function
  std::cout << "Value of first rational number after normalization: ";
  sample1.print(std::cout);
  std::cout << "Value of second rational number after normalization: ";
  sample2.print(std::cout);

  //displaying values by using approxmation function
  std::cout << "Approximation of first number: " << sample1.approximation() << '\n';
  std::cout << "Approximation of second number: " << sample2.approximation() << '\n';

  //comparison of two rational numbers
  if(sample1 == sample2){
    std::cout << "First rational number is equal to second rational number\n";
  }
  else{
    std::cout << "Second rational number is greater than first rational number\n";
  }

  //performing different operations such as +, -, *, /
  rational addition = sample1 + sample2;
  rational subtraction = sample1 - sample2;
  rational multiplication = sample1 * sample2;
  rational division = sample1 / sample2;

  std::cout << "Addition of two rational numbers: ";
  addition.print(std::cout);
  std::cout << "Subtraction of two rational numbers: ";
  subtraction.print(std::cout);
  std::cout << "Multiplication of two rational numbers: ";
  multiplication.print(std::cout);
  std::cout << "Division of two rational numbers: ";
  division.print(std::cout);

  return 0;
}


