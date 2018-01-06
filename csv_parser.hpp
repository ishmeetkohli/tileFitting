//
//  csv_parser.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#ifndef csv_parser_hpp
#define csv_parser_hpp

#include <fstream>
#include <vector>
#include "Rect.hpp"
#include "csv.h"

using namespace std;

class CsvParser {

public:
	vector<Rect> parseInputSet(string inputFileName);
};

#endif /* csv_parser_hpp */
