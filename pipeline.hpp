//
//  pipeline.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#ifndef pipeline_hpp
#define pipeline_hpp

#include <stdio.h>
#include <climits>
#include <vector>
#include <fstream>
#include <map>

#include "csv_parser.hpp"
#include "rect_node.hpp"
#include "result.hpp"

class Pipeline {
private:
	RectNode root;
	CsvParser parser;
    
public:
    Pipeline(int width, int height);
    
    map<int, Result> fitRectangles(vector<Rect> rectangles);
    RectNode* findBestFit(RectNode *root, Rect *rect);
    bool fit(string inputFileName, string outputFileName);
    void writeToOutput(map<int, Result> &results, string outputFileName);
    void sort(vector<Rect> &rectangles, int low, int high);
    int partition(vector<Rect> &rectangles, int low, int high);
    void swap(vector<Rect> &rectangles, int i, int j);
};

#endif /* pipeline_hpp */
