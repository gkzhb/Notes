/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 张海斌 17307130118
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
  return ~((~x) | (~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
  return (x >> (n << 3)) & 0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n)
{
  int sign = x & (0x1 << 0x1f), move;
  x = (x ^ sign) >> n;
  move = ~n;
  sign = sign >> 0x1f & 0x1 << move;
  return x ^ sign;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
  int result;
  //int mask1=(0x55)|(0x55<<8)|(0x55<<16)|(0x55<<24);
  int tmp_mask1 = (0x55) | (0x55 << 8);
  int mask1 = (tmp_mask1) | (tmp_mask1 << 16);
  //int mask2=(0x33)|(0x33<<8)|(0x33<<16)|(0x33<<24);
  int tmp_mask2 = (0x33) | (0x33 << 8);
  int mask2 = (tmp_mask2) | (tmp_mask2 << 16);
  //int mask3=(0x0f)|(0x0f<<8)|(0x0f<<16)|(0x0f<<24);
  int tmp_mask3 = (0x0f) | (0x0f << 8);
  int mask3 = (tmp_mask3) | (tmp_mask3 << 16);
  int mask4 = (0xff) | (0xff << 16);
  int mask5 = (0xff) | (0xff << 8);
  //add every two bits
  result = (x & mask1) + ((x >> 1) & mask1);
  //add every four bits
  result = (result & mask2) + ((result >> 2) & mask2);
  //add every eight bits
  //result=(result&mask3)+((result>>4)&mask3);
  result = (result + (result >> 4)) & mask3;
  //add every sixteen bits
  //result=(result&mask4)+((result>>8)&mask4);
  result = (result + (result >> 8)) & mask4;
  //add every thirty two bits
  //result=(result&mask5)+((result>>16)&mask5);
  result = (result + (result >> 16)) & mask5;
  return result;
  // 参考博客：https://blog.csdn.net/lwfcgz/article/details/8515188?utm_source=copy
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x)
{
  int ans = (x >> 0x10) | x;
  ans = ans | (ans >> 0x8);
  ans = ans | (ans >> 0x4);
  ans = ans | (ans >> 0x2);
  return ((ans | ans >> 0x1) & 0x1) ^ 0x1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  return 0x1 << 0x1f;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
  int shiftNumber = ~n + 33;
  return !(x ^ ((x << shiftNumber) >> shiftNumber));
  // 参考博客同上
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n)
{
  /* 原错误代码
  int sign = x & (0x1 << 0x1f), t, m = ~n;
  t = ~0x0 ^ (0x1 << 0x1f);
  t = t >> m;
  sign = (~sign >> 0x1a) & 0x20;
  t = t >> sign;
  x = x + t;
  return x >> n;
  */
  //all zeros or all ones
  int signx = x >> 31;
  //int mask=(1<<n)+(-1);
  int mask = (1 << n) + (~0);
  int bias = signx & mask;
  return (x + bias) >> n;
  // 参考博客同上
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x)
{
  int sign = (x >> 0x1f) & 0x1;
  return (~x + 1 >> 0x1f) & !sign;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  int sign1 = ((x ^ y) >> 0x1f) & 0x1, sign2 = (y >> 0x1f) & 0x1, sign3, ans;
  // sign1: x y 同号为0 异号为1   sign2: y 的符号   sign3: ans = y - x 的符号
  x = ~x + 1;
  ans = x + y;
  sign3 = (ans >> 0x1f) & 0x1;
  return (sign1 & !sign2) | !(sign1 | sign3);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x)
{
  int bitsNumber = 0;
  // binary search process
  bitsNumber = (!!(x >> 16)) << 4;
  bitsNumber = bitsNumber + ((!!(x >> (bitsNumber + 8))) << 3);
  bitsNumber = bitsNumber + ((!!(x >> (bitsNumber + 4))) << 2);
  bitsNumber = bitsNumber + ((!!(x >> (bitsNumber + 2))) << 1);
  bitsNumber = bitsNumber + (!!(x >> (bitsNumber + 1)));
  // for non zero bitsNumber, it should add 0
  // for zero bitsNumber, it should subtract 1
  bitsNumber = bitsNumber + (!!bitsNumber) + (~0) + (!(1 ^ x));
  return bitsNumber;
  // 参考博客同上
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf)
{
  /* unsigned x = 0xff << 0x; */
  unsigned flag = 0x0, i = 0x17, last = uf & 0x1, cp = uf;
  // flag: 0表示为 NaN 1表示不是NaN
  while (i)
  {
    if (uf & 0x1 != last)
      flag = 0x1;
    i = i - 1;
    uf = uf >> 0x1;
  }
  if (((uf & 0xff) == 0xff) && flag)
    flag = 0x0;
  else
    flag = 0x1;
  return cp ^ (flag << 0x1f);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x)
{
  /* 原错误代码
  if (!x)
    return x;
  unsigned ans = 0, t = 0, sign = 0, exp, cp, mask = (0x7f << 0x10) | (0xff << 0x8) | 0xff, tmp;
  if (x < 0)
  {
    ans = 0x1 << 0x1f;
    x = ~x + 1;
  }
  cp = x;
  while (x && t < 32)
  {
    t = t + 1;
    x = x >> 1;
  }
  exp = t;
  if (t < 24)
    tmp = cp << (24 - exp);
  else
    tmp = cp >> (exp - 24);
  tmp = tmp & mask;
  exp = (exp + 126) << 0x17;
  return ans | exp | tmp;
  */

  unsigned shiftLeft = 0;
  unsigned afterShift, tmp, flag;
  unsigned absX = x;
  unsigned sign = 0;
  //special case
  if (x == 0)
    return 0;
  //if x < 0, sign = 1000...,abs_x = -x
  if (x < 0)
  {
    sign = 0x80000000;
    absX = -x;
  }
  afterShift = absX;
  //count shift_left and after_shift
  while (1)
  {
    tmp = afterShift;
    afterShift <<= 1;
    shiftLeft++;
    if (tmp & 0x80000000)
      break;
  }
  if ((afterShift & 0x01ff) > 0x0100)
    flag = 1;
  else if ((afterShift & 0x03ff) == 0x0300)
    flag = 1;
  else
    flag = 0;

  return sign + (afterShift >> 9) + ((159 - shiftLeft) << 23) + flag;
  // 参考博客同上
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{
  unsigned /*flag = 0x0, i = 0x17, last = uf & 0x1, */cp = uf;
  // flag: 0表示为 NaN 1表示不是NaN
  unsigned x = (0xff | (0x1 << 8)) << 0x16, sign = uf & (0x1 << 0x1f), exp = x & uf;
  if (exp == 0 | exp == (0x1 << 0x16))
    return ((uf << 0x1) | sign);
  /*while (i)
  {
    if ((uf & 0x1) != last)
      flag = 0x1;
    i = i - 1;
    uf = uf >> 0x1;
    } */
  uf = uf >> 0x17;
  if ((uf & 0xff) == 0xff)
    return cp;
  else
    return cp + (0x1 << 0x17);
}
