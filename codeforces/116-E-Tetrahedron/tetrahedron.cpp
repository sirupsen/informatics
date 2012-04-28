#include <iostream>
using namespace std;

#define MATRIX_DIMENSION 5

int matrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
int product[MATRIX_DIMENSION][MATRIX_DIMENSION];

void print_product()
{
  for(int i = 0; i < MATRIX_DIMENSION; i++) {
    for(int j = 0; j < MATRIX_DIMENSION; j++) {
      cout << product[i][j] << " ";
    }

    cout << "\n";
  }
}

void multiply_matrix(int times)
{
  for(int i = 0; i < MATRIX_DIMENSION; i++) {
    for(int j = 0; j < MATRIX_DIMENSION; j++) {
      int sum = 0;

      for (int k = 0; k < MATRIX_DIMENSION; k++)
        sum += matrix[i][k] * matrix[k][j];

      product[i][j] = sum;
    }
  }
}

void seed_matrix()
{
  for(int i = 0; i < MATRIX_DIMENSION; i++)
    for(int j = 0; j < MATRIX_DIMENSION; j++)
      if (i != j) matrix[i][j] = 1;
}

int main()
{
  int steps;
  cin >> steps;

  seed_matrix();
  multiply_matrix(3);
  print_product();

  return 1;
}
