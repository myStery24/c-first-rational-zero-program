/*
 * Algebra Group Assignment Part B
 *
 * Using C, write a program to find the first rational zero of a polynomial ax^3 + bx^2 + cx + d.
 * The output should be as shown in Figure Q3.
 *
 * Use the following information for the program:
 * 1) a is fixed to 1
 * 2) Once the first rational zero is found, the integer will be displayed and program will be stopped.
 * 3) If no rational zero is found, a message "No rational zero found!" will be displayed.
 *
 * Note: Test your program with at least 3 cubic polynomials and show samples of output in your report.
 *
 * Author: ZH.LEE, QY.TAN
 * Given date: 11/14/2020
 * Last edited: 11/21/2020 07:37 PM
 */

#include <stdio.h>
#include <math.h>

int a = 1, b, c, d; // global variables

/* a menu asking user to enter value for b, c and d
 * function call in line 90
 */
void menu() {
	printf("Insert value of b, c and d: ");
	printf("\nb: "); // input value for b
	scanf("%d", &b);
	printf("c: "); // input value for c
	scanf("%d", &c);
	printf("d: "); // input value for d, d is constant term
	scanf("%d", &d);
}

// find the first rational zero
int firstzero(int array[], int j){
	int remainder;
	for(int i = 0; i < j ; i++) {
		remainder = (1 * pow(array[i], 3)) + (b * pow(array[i], 2)) + (c * array[i]) + d;
    // if remainder equals to zero, it is a factor
		if(remainder == 0) {
			printf("\n\nThe first rational zero = %d", array[i]);
      return 0;
		}
	}
  printf("\n\nNo rational zero found!");
  return remainder;
}

// find all the rational zeros
void testp(int p){
	int constantTerm = p; // p is the constant term which is the value of d entered by user
	int negative_p;
	int j = 0;
	int possiblezero[100]; //to store all possible p/q

  // if p is negative value
	if(constantTerm < 0) {
    /* correct it to positive number,
     * modulus p or abs(p)
     * because it will affect the value of negative_p(line 70)
     */
    constantTerm = -constantTerm;
	}

	for(int i = 1; i <= constantTerm; i++) {
    //to find factor
		if(constantTerm % i == 0){
      negative_p = -i; // to get the negative(-) value of p/q
			printf("\n%d\n%d", i, negative_p);
			possiblezero[j] = i;
			possiblezero[j + 1] = negative_p;
			j = j + 2;
		}
	}
	/* //to see the whether the value p/q are stored in the array
	printf("\n\narray list = \n");
	for(int i = 0; i < j; i++){
		printf(" %d, ", possiblezero[i]);
	}
	*/
	firstzero(possiblezero, j);
}

// main
int main() {

  menu();

	printf("\nThe polynomial is %dx^3 + %dx^2 + %dx + %d", a, b, c, d); // a is fixed to 1, display in this format: ax^3 + bx^2 + cx + d
	printf("\n-------------------------\n\n"); // border line

  printf("p = %d\n", d); // display constant term
  printf("q = %d", a); // leading coefficient is fixed to 1

  printf("\n\nPossible rational zeros are: \n---\n");
  /* function call to display the possible rational zeros
   * and get the first rational zeros
   * then stop
   */
  testp(d);

  return 0;
}
