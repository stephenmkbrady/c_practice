#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//

//keep returning y and decrementingy x until x == 1, y and x can swap roles
//2 2
//2+(2)
//2 4
//4 + (4)
//3 2
//2 + (2 + (2))
unsigned int multiply(unsigned int x, unsigned int y){

	if(y == 1) {
		return x;
	}
	else if (y > 1){
		return x + multiply(x, y-1);
	}

	return 0; //if y == 0
}

/**
 * Factorial will take num and compute it's factorial
 * 5! = 5 x 4 x 3 x 2 x 1
 * */
unsigned int factorial(unsigned int num ) {
	if(num == 1){
		return(num);
	}
	else if (num > 1){
		return(num * factorial(num-1));
	}
	return 0;
}
int main(int argc, char **argv){
	if(argc == 2){
//	printf("\n%s x %s = %d\n", argv[1], argv[2], multiply(atoi(argv[1]),atoi(argv[2])));
	printf("factorial: %s! = %d", argv[1], factorial(atoi(argv[1])));
	return 0;
	}
	else{
		printf("usage: ./3.o 2 2\n argc: %d\n", argc);
	}
}
