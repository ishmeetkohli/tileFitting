//
//  main.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 16/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#include <iostream>
#include "pipeline.hpp"

int main(int argc, const char * argv[]) {
    int containerWidth = 6;
    int containerHeight = 6;
    Pipeline pipeline(containerWidth, containerHeight);
    string inputFileName = "/Users/Ishmeet/workspace/code/TileFitting/TileFitting/TileFitting/data/sample_InputSet1_6x6.csv";
    string outputFileName = "/Users/Ishmeet/workspace/code/TileFitting/TileFitting/TileFitting/data/result.csv";
    cout << (pipeline.fit(inputFileName, outputFileName) ? "Success" : "Failure") << '\n';
    return 0;
}
