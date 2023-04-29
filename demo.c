#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 32

int premium = 0;

void menu(void) {
	printf(
		"Please select one of the following operations:\n"
		"1) Add (x + y)\n"
		"2) Subtract (x - y)\n"
		"3) Divide (x / y)\n"
		"4) Multiply (x * y)\n"
	);
	
	if (premium) {
		printf(
			"5) Exponent (x**y)\n"
			"6) Logarithm (log_x(y))\n"
		);
	}
	else {
		printf(
			"5) (PREMIUM) Exponent (x**y)\n"
			"6) (PREMIUM) Logarithm (log_x(y))\n"
		);
	}
	printf("> ");
}

int main(void) {
	printf("Welcome to the super advanced freemium calculator!\n");
	if (premium) {
		printf("You have the PREMIUM version.");
	}
	else {
		printf("You have the LIMITED version.");
	}
	
	while (1) {
		printf("\n---------------------------\n\n");
		menu();
		
		char input[MAX_LEN] = {0};
		fgets(input, MAX_LEN, stdin);
		
		input[strcspn(input, "\n")] = '\0';
		
		int option = atoi(input);
		
		if (option < 1 || option > 6) {
			printf("Unrecognized option; Try again\n");
			continue;
		}
		
		if (!premium && (option == 5 || option == 6)) {
			printf("Not available in the LIMITED version!\n");
			continue;
		}
		
		printf("Enter integer x: ");
		int x = atoi(fgets(input, MAX_LEN, stdin));
		printf("Enter integer y: ");
		int y = atoi(fgets(input, MAX_LEN, stdin));
		
		switch (option) {
			case 1: // Add
				printf("%d + %d = %d", x, y, x + y);
				break;
			case 2: // Subtract
				printf("%d - %d = %d", x, y, x - y);
				break;
			case 3: // Divide
				printf("%d / %d = %f", x, y, ((float)x)/y);
				break;
			case 4: // Multiply
				printf("%d * %d = %d", x, y, x * y);
				break;
			case 5: // Exponent
				printf("%d ** %d = %f", x, y, pow(x, y));
				break;
			case 6: ; // Logarithm
				double res = log(y) / log(x);
				printf("log_%d(%d) = %f", x, y, res);
				break;
			default:
				printf("Option not recognized; Try again:\n\n");
		}
	}
}
