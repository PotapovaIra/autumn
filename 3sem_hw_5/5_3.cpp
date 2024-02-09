
/////////

float fl = 33.78;
int i = fl; //  float --> int, 
//When converting to int, the fractional part of the number is removed. 
// The answer will be 33, not 33.78, this may cause troubles

/////////

int x = 10;
long y =40000;
short z = x + y; //  int and long --> short
//'short' can keep values less than 40000, so it can overflow and cause trouble

/////////

unsigned int m = 10;
int n = -70;
unsigned int k = n+m; //  unsigned int and int --> unsigned int

// -5 converts to very big positive number(as unsigned int is not meant to store negative numbers)