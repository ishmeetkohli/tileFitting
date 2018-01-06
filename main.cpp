//
//  main.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#include <iostream>
#include "pipeline.hpp"

enum flag_enum {
	InputSet,
	ContainerWidth,
	ContainerHeight,
	Output
};

flag_enum hashit(std::string const& inString) {
	if (inString == "-InputSet") return InputSet;
	if (inString == "-ContainerWidth") return ContainerWidth;
	if (inString == "-ContainerHeight") return ContainerHeight;
	if (inString == "-Output") return Output;
}

void usage() {
	cout << "Usage: TileFitting -InputSet <filename> -ContainerWidth <width> -ContainerHeight <height> -Output <filename>";
}

int main(int argc, const char * argv[]) {
	string input = "", output = "";
	int width = -1, height = -1;


	if (argc == 9) {
		for (int i = 1; i < 8; i += 2) {
			flag_enum flag = hashit(argv[i]);
			switch (flag) {
			case InputSet:
				input = argv[i + 1];
				break;

			case ContainerWidth:
				width = atoi(argv[i + 1]);
				break;

			case ContainerHeight:
				height = atoi(argv[i + 1]);
				break;

			case Output:
				output = argv[i + 1];
				break;

			default:
				usage();
				return 1;
			}
		}

		if (width < 0 || height < 0 || input.empty() || output.empty()) {
			usage();
			return 1;
		}

		Pipeline pipeline(width, height);
		try {
			cout << (pipeline.fit(input, output) ? "Success" : "Failure") << '\n';
		}
		catch (exception& e)
		{
			cerr << e.what() << '\n';
		}

	}
	else {
		usage();
		return 1;
	}
	return 0;
}
