struct Values{
	int mult;
	float div;
};

bool check_input(int, int);
Values** make_table(int, int);
void set_mult(Values **, int, int);
void set_div(Values **, int, int);
void delete_table(Values **, int);
void run_again(int, int);
void new_matrix(int, int);