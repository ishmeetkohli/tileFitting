//
//  Rect.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 22/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include <stdio.h>
#include <algorithm>

struct Rect {
    int seqId;
    int width;
    int height;
    int area;
    
    Rect(int seqId, int width, int height);
    bool isGreaterThan(Rect rect);
};


#endif /* Rect_hpp */
