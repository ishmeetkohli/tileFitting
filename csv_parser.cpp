//
//  csv_parser.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 16/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#include "csv_parser.hpp"

vector<Rect> CsvParser::parseInputSet(string inputFileName) {
    vector<Rect> rectangles;
    
    io::CSVReader<2> in(inputFileName);
    in.read_header(io::ignore_extra_column, "width", "height");
    int width; int height;
    int seqNum = 0;
    while(in.read_row(width, height)){
        rectangles.push_back(Rect(seqNum++,width,height));
    }
    
    return rectangles;
}

