//returns: (counts[0] + ,,, counts[n-1])! / counts[0]! , *** counts[n-1]!
#include <stdio.h>
#include <stdlib.h>


int fact(int n){
	int result = 1;
	
	for (int i = 1; i <= n; i++){
	result *= i;
	}
	return result;
}

int num_perms(int n, int * counts){
	int sum = 0;
	
	for (int i = 0; i < n; i++){
		 sum += counts[i];
	}
	int numerator = fact(sum);
	
	int denom = 1;
	for (int i = 0; i < n; i++){
		denom *= fact(counts[i]);
	}
	
	return numerator/denom;
}

int* create_perm_array(int n, int* counts, int* perm_array, int a, int indx, int count){
	
	for (int i = a; i < n; i++){
		if(counts[i] > 1 && count == 0){
			perm_array[i] += i;
			indx++;
			count++;
			counts[i] -= 1;
			create_perm_array(n, counts, perm_array, a, indx, count);
		}
		else if(counts[i] > 1 && count != 0){
			perm_array[count] += i;
			indx++;
			count++;
			counts[i] -= 1;
			create_perm_array(n, counts, perm_array, a, indx, count);
		}
		else if(counts[i] <= 1 && count > 0){
			perm_array[count] = i;
			indx++;
			counts[i] += count;
			count=0;
			create_perm_array(n, counts, perm_array, (a+1), indx, count);
		}
		else {
			perm_array[indx] += i;
			indx++;
		}
	}
	return perm_array;
}

int** compute_perms(int n, int* counts){
	int num_rows = num_perms(n, counts);
	
	int sum = 0;
	
	for (int i = 0; i < n; i++){
		 sum += counts[i];
	}
	
	int num_cols = sum;
	
	int** result = malloc(num_rows * sizeof(int*));
	
	for (int 
	i = 0; i < num_rows; i++){
		result[i] = malloc(num_cols * sizeof(int));
	}
	
	//testing
	for (int i = 0; i < num_rows; i++){
		for (int j = 0; j < num_cols; j++){
			result[i][j]=0;
			printf("%d", result[i][j]);
		}
		printf("\n");
	}
	return result;
}

void test_1(int n, int* counts){
	int sum = 0;
	int a = 0;
	int indx = 0;
	int count = 0;
	
	for (int i = 0; i < n; i++){
		 sum += counts[i];
	}
	
	int* perm_array = malloc(sum * sizeof(int));
	
	perm_array = create_perm_array(n, counts, perm_array, a, indx, count);
	printf("create_perm_array(3, (2,1,1), perm_array, 0, 0, 0) = %d\n", *perm_array);
}

int main(){
	// int x = fact(5);
// 	printf("x = %d\n", x);
//
// 	int result = num_perms(3, (int[]){2,1,3});
// 	printf("num_perms(3, (int[]){2,1,3}) = %d\n", result);
//
// 	compute_perms(3, (int[]){2,1,3});
	
	test_1(3, (int[]){2,1,1});
	
	
	
	//test for 0's
	
}