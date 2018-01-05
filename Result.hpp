//
//  Result.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 28/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#ifndef Result_hpp
#define Result_hpp

#include <stdio.h>

struct Result
{
    int width;
    int height;
    int top;
    int left;

    Result(int width, int height, int top, int left);
    
};

#endif /* Result_hpp */
