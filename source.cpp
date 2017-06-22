#include <iostream>
#include <string>
#include <vector>

#include "grammar.h"
#include "table.h"
#include "stack.h"

#pragma warning(disable: 4996)


using namespace std;
FILE* file;


string& get_action(string status, string input) {
	int i = std::stoi(status);
	int k = v_to_num(input[0]);

	if(table[i][k].length() != 0)
		return table[i][k];
	else {
		cout << "\nERROR!!";
		fprintf(file, "\nERROR!!");
		exit(0);
	}
}

int main(int argc, char *argv[]) {

	if (argc == 1) {
		cout << "please input some string" << endl;
		return 0;
	}
	string input_string = argv[1];
	cout << argv[1];


	// -------------------------------------------------------------------
	// initializing ------------------------------------------------------
	// -------------------------------------------------------------------

	_stack stack;
	stack.push(new _element("state", "0"));

	string next_char;
	string action;
	file = fopen("result.txt", "w");

	printf("%-4s  %-15s  %-10s  %s\n", "step", "stack", "input","action");
	fprintf(file, "%-4s  %-15s  %-10s  %s\n", "step", "stack", "input", "action");

	for (int step = 0; ; step++) {
	
		printf("%4i  %-15s  %10s  ", step, stack.print()->data(),input_string.data());
		fprintf(file, "%4i  %-15s  %10s  ", step, stack.print()->data(), input_string.data());

		next_char = input_string[0];
		action = get_action(stack.top()->value(), next_char);

		// ---------------------------------------------------------------
		// shift----------------------------------------------------------
		// ---------------------------------------------------------------

		if (action[0] == 's') {
			
			printf("%s\n", action.data());
			fprintf(file, "%s\n", action.data());

			input_string = input_string.substr(1);

			stack.push(new _element("others", next_char));
			stack.push(new _element("state", action.substr(1)));
		}

		// ---------------------------------------------------------------
		// reduce --------------------------------------------------------
		// ---------------------------------------------------------------
			
		else if (action[0] == 'r') {

			_grammar& reduce_rule = grammar[std::stoi(action.substr(1))];
			string LHS = reduce_rule.get_LHS();
			string RHS = reduce_rule.get_RHS();

			int length = RHS.length();
			for (int i = 0; i < length; i++) {
				if (stack.top()->type() == "state") stack.pop();
				if (stack.top()->value() == RHS.substr(length-1-i,1)) stack.pop();
				else {
					printf("ERROR!!!");
					fprintf(file, "ERROR!!!");
				}
			}
			
			printf("%s, ", action.data());
			fprintf(file, "%s, ", action.data());

			// -----------------------------------------------------------
			// goto ------------------------------------------------------
			// -----------------------------------------------------------


			string status = stack.top()->value();
			action = get_action(status, LHS);

			printf("%s\n", action.data());
			fprintf(file, "%s\n", action.data());

			stack.push(new _element("others", LHS));
			stack.push(new _element("state", action.substr(1)));
			
		}

		else if (action[0] == '$') {
			printf("acc\nACCEPT!");
			fprintf(file, "acc\nACCEPT!");
			break;
		}

		else {
			printf("ERROR!");
			fprintf(file, "\nERROR!");
		}
	}
	fclose(file);

	return 0;


}