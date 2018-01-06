//
//  csv_parser.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#include "csv_parser.hpp"

vector<Rect> CsvParser::parseInputSet(string inputFileName) {
	vector<Rect> rectangles;

	try {
		io::CSVReader<2> in(inputFileName);
		in.read_header(io::ignore_extra_column, "width", "height");
		int width; int height;
		int seqNum = 0;
		while (in.read_row(width, height)) {
			rectangles.push_back(Rect(seqNum++, width, height));
		}
	}
	catch (const io::error::can_not_open_file& e) {
		throw std::runtime_error("Exception opening/reading file");
	}

	return rectangles;
}

