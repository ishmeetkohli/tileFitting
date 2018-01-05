//
//  csv_parser.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 16/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#ifndef csv_parser_hpp
#define csv_parser_hpp

#include <stdio.h>
#include <vector>
#include "Rect.hpp"
#include "csv.h"

using namespace std;

class CsvParser {

public:
    
    vector<Rect> parseInputSet(string inputFileName);
};


#endif /* csv_parser_hpp */
