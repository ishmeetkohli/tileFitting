//
//  Rect.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli on 22/12/17.
//  Copyright © 2017 Ishmeet. All rights reserved.
//

#include "Rect.hpp"

using namespace std;

Rect::Rect(int seqId, int width, int height) {
    this->seqId = seqId;
    this->width = width;
    this->height = height;
    this->area = width * height;
}

bool Rect::isGreaterThan(Rect rect) {
    if (this->height == rect.height){
        return this->area > rect.area;
    }
    
    return this->height > rect.height;
}
