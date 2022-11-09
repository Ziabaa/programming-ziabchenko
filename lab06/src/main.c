int main()
{
#define ROWS1 3
#define COLUMNS1 3
#define ROWS2 3
#define COLUMNS2 3
	int first_matrix[ROWS1][COLUMNS1] = { { 2, 3, 5 }, { 4, 0, 1 }, { 2, 2, 4 } };
	int second_matrix[ROWS2][COLUMNS2] = { { 2, 3, 5 }, { 4, 0, 1 }, { 2, 2, 4 } };
	int finaly_matrix[ROWS1][COLUMNS2] = { 0 };
	if (ROWS1 == COLUMNS2) {
		for (int i = 0; i < ROWS1; i++) {
			for (int j = 0; j < COLUMNS2; j++) {
				for (int k = 0; k < ROWS2; k++) {
					finaly_matrix[i][j] += (first_matrix[i][k] * second_matrix[k][j]);
				}
			}
		}
	}

	return 0;
}
