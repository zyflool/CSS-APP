/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~((~x)&y))&(~(x&(~y)));
}
/* 
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max  ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(((x<<1)+1)^0xff);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // i = 10101010101010101010101010101010
    int i = 0xAA + ( 0xAA<<8 );
    i = i + ( i<<16 );
    return !((i&x)^i);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // 00000000000000000000000000111001 max
    // 01111111111111111111111111000110 The aim
    // 10000000000000000000000000000000 T_min
    // 10000000000000000000000000111001 T_min|max
    // 01111111111111111111111111000110 ~(T_min|max)

    // 00000000000000000000000000110000 min
    // 11111111111111111111111111010000 The aim

    int T_min = 0x1<<31;
    int max = ~(T_min|max);
    int min = ~min+1;
    max = T_min&(max+x)>>31;
    min = T_min&(min+x)>>31;
    return !(max|min);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    x = ( x != 0 ) ;
    x = ~x+1;
    //x == 111111111111...  / x == 00000...
    return (x&y)|(~x&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    //两种情况：一是符号不同正数为大，二是符号相同看差值符号
    int negX=~x+1;//-x
    int addX=negX+y;//y-x
    int checkSign = addX>>31&1; //y-x的符号
    int leftBit = 1<<31;//最大位为1的32位有符号数
    int xLeft = x&leftBit; //x的符号
    int yLeft = y&leftBit; //y的符号
    int bitXor = xLeft ^ yLeft;//x和y符号相同标志位，相同为0不同为1
    bitXor = (bitXor>>31)&1;//符号相同标志位格式化为0或1
    return ((!bitXor)&(!checkSign))|(bitXor&(xLeft>>31));
    //返回1有两种情况：
    // 符号相同标志位为0（相同）位与 y-x 的符号为0（y-x>=0）结果为1；
    // 符号相同标志位为1（不同）位与x的符号位为1（x<0）
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    //算术右移
    // 0和最小数的补码是本身
    //一般的原码|补码符号位为1
    return ( (x| (~x+1) ) >> 31 ) +1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int b16,b8,b4,b2,b1,b0;
    int sign=x>>31;
    x = (sign&~x)|(~sign&x);
    //如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）

    //不断缩小范围
    b16 = (x >> 16 != 0) << 4;//高十六位是否有1
    x = x>>b16;//如果有（至少需要16位），则将原数右移16位
    b8 = (x >> 8 != 0) << 3;//剩余位高8位是否有1
    x = x>>b8;//如果有（至少需要16+8=24位），则右移8位
    b4 = (x >> 4 != 0) << 2;//同理
    x = x>>b4;
    b2 = (x >> 2 != 0) << 1;
    x = x>>b2;
    b1 = (x >> 1 != 0);
    x = x>>b1;
    b0 = x;
    return b16+b8+b4+b2+b1+b0+1;//+1表示加上符号位
    //正数需要最高位为0
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
/*
 * 首先排除无穷小、0、无穷大和非数值NaN，
 * 此时浮点数指数部分（真正指数+bias）分别存储的的为0，0，,255，255。这些情况，
 * 无穷大和NaN都只需要返回参数（ 2\times\infty=\infty,2\times NaN=NaN ），
 * 无穷小和0只需要将原数乘二再加上符号位就行了（并不会越界）。
 * 剩下的情况，如果指数+1之后为指数为255则返回原符号无穷大，否则返回指数+1之后的原符号数。
 */

    int exp = (uf&0x7f800000)>>23;
    int sign = uf&(1<<31);
    if(exp==0) return uf<<1|sign;
    if(exp==255) return uf;
    exp++;
    if(exp==255) return 0x7f800000|sign;
    return (exp<<23)|(uf&0x807fffff);
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    /*
     * 首先考虑特殊情况：如果原浮点值为0则返回0；
     * 如果真实指数大于31（frac部分是大于等于1的，1<<31位会覆盖符号位），返回规定的溢出值0x80000000u；
     * 如果 exp<0 （1右移x位,x>0，结果为0）则返回0。
     * 剩下的情况：首先把小数部分（23位）转化为整数（和23比较），
     * 然后判断是否溢出：如果和原符号相同则直接返回，
     * 否则如果结果为负（原来为正）则溢出返回越界指定值0x80000000u，
     * 否则原来为负，结果为正，则需要返回其补码（相反数）。
     */
    int s_    = uf>>31;
    int exp_  = ((uf&0x7f800000)>>23)-127;
    int frac_ = (uf&0x007fffff)|0x00800000;
    if(!(uf&0x7fffffff)) return 0;

    if(exp_ > 31) return 0x80000000;
    if(exp_ < 0) return 0;

    if(exp_ > 23) frac_ <<= (exp_-23);
    else frac_ >>= (23-exp_);

    if(!((frac_>>31)^s_)) return frac_;
    else if(frac_>>31) return 0x80000000;
    else return ~frac_+1;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    /*
     * 2.0的位级表示（ 1.0\times2^1 ）：符号位：0，指数：1+127=128，frac=1.0-1=0。 2.0^x=(1.0\times2^1)^x=1.0\times2^x ，所以x就当做真正的指数的。
     * 首先得到偏移之后的指数值e，如果e小于等于0（为0时，结果为0，因为2.0的浮点表示frac部分为0），对应的如果e大于等于255则为无穷大或越界了。
     * 否则返回正常浮点值，frac为0，直接对应指数即可。
     */
    int INF = 0xff<<23;
    int exp = x + 127;
    if(exp <= 0) return 0;
    if(exp >= 255) return INF;
    return exp << 23;
}
