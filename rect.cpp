//
//  rect.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#include "rect.hpp"

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
