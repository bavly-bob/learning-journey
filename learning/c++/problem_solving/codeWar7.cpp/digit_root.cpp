// digital root
// https://www.codewars.com/kata/541c8630095125aba6000c00
// Digital root is the recursive sum of all the digits in a number.
// Given n, take the sum of the digits of n. If that value has more than
// one digit, continue reducing in this way until a single-digit number is produced.
// This is only applicable to the natural numbers.

int sum_digit(int n){
  int tmp = 0;
  do{
    tmp += n % 10;
  }while(n /= 10);
  return tmp;
}
int digital_root(int n)
{
    int sum = sum_digit(n);
    while(sum >= 10){
      sum = sum_digit(sum);
    }
  return sum;
}

// Optimal solution using properties of numbers
int digital_root(int n) 
{
    if (n == 0) return 0;
    return 1 + (n - 1) % 9;
}
