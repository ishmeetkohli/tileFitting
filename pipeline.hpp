//
//  pipeline.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 16/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#ifndef pipeline_hpp
#define pipeline_hpp

#include <stdio.h>
#include <climits>
#include <vector>
#include <fstream>
#include <map>

#include "csv_parser.hpp"
#include "Tree.hpp"
#include "Result.hpp"

struct RectNode{
    int width;
    int height;
    int x;
    int y;
    
    bool used;
    int minAllowance;
    
    RectNode *left, *right;
    RectNode(int width, int height);
    
    void split(int width, int height);
};


class Pipeline {
private:
    RectNode root;
    
public:
    Pipeline(int width, int height);
    
    CsvParser parser;
    map<int, Result> fitRectangles(vector<Rect> rectangles);
    RectNode* findBestFit(RectNode *root, Rect *rect);
    bool fit(string inputFileName, string outputFileName);
    void writeToOutput(map<int, Result> &results, string outputFileName);
    void sort(vector<Rect> &rectangles, int low, int high);
    int partition(vector<Rect> &rectangles, int low, int high);
    void swap(vector<Rect> &rectangles, int i, int j);
};

#endif /* pipeline_hpp */
