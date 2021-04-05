#include "rational.h"

bigint gcd( bigint n1, bigint n2 )

{ 
  if (n1 == 0) {
    return n2;
  } else if (n2 == 0)
 {
    return n1;
 }

  if (n1 == 0 && n2 == 0){
    std::runtime_error( "GCD: both arguments are zero" );
  }

  if (n1 < 0){
    n1 *= (-1);
  }

  if (n2 < 0) {
    n2 *= (-1);
  }

  while (n1 != 0 && n2!= 0){

    if (n1 > n2){
      n1 = n1 % n2;
    }
    else{
      n2 = n2 % n1;
    }

    if (n1 == 0){
      return (n1 + n2);
    } else if (n2 == 0 ){
      return (n1 + n2);
    }
  }
  return 0; 
}


void rational::normalize( )
{
  if (denom == 0){
    std::runtime_error("rational: denom == 0");
  } else if (denom < 0){

    num *= -1;
    denom *= -1;

  }

  bigint gcd1 =gcd(num, denom);
  denom = denom/gcd1;
  num = num/gcd1;
} 

double rational::approximation( ) const
{ 

   return num. approximation( ) / denom. approximation( ); 

}

rational rational::operator - ( ) const 
{ 
  return rational (num*(-1), denom);
}

rational rational::operator + ( const rational& r2 ) const 
{ 

  rational plus_integer;

  plus_integer.num = (num * r2.denom + r2.num * denom);
  plus_integer.denom = denom * r2.denom;

  rational normalize_integer (plus_integer.num, plus_integer.denom);

  return normalize_integer;
}

rational rational::operator - ( const rational& r2 ) const 
{ 

  rational minus_integer;

  minus_integer.num = (num * r2.denom - r2.num * denom);
  minus_integer.denom = denom * r2.denom;

  rational normalize_integer (minus_integer.num, minus_integer.denom);

  return normalize_integer;
}

rational rational::operator * ( const rational& r2 ) const 
{ 

  rational multiple_integer;
  multiple_integer.num = (num * r2.num);
  multiple_integer.denom = (denom * r2.denom);

  rational normalize_integer (multiple_integer.num, multiple_integer.denom);

  return normalize_integer;
}

rational rational::operator / ( const rational& r2 ) const 
{ 

  rational divide_integer;
  divide_integer.num = (num * r2.denom);
  divide_integer.denom = (denom * r2.num);

  rational normalize_integer (divide_integer.num, divide_integer.denom);

  return normalize_integer;
}


// Putting full trust in our normalization:

bool rational::operator == ( const rational& r2 ) const
{ 
  if ((num == r2.num) && (denom == r2.denom)){
    return true;
  }
  else {
    return false;
  }
}

bool rational::operator != ( const rational& r2 ) const
{ 
  if ((num != r2.num) || (denom != r2.denom)){
    return true;
  }
  else {
    return false;
  }
}

void rational::print( std::ostream& stream ) const 
{ 
  if (denom == 1){
    stream << num <<std::endl;
  }

  else {
    stream << num << "/" << denom <<std::endl;
  }
}

