//  
//  rect.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#ifndef rect_hpp
#define rect_hpp

#include <algorithm>

struct Rect {
	int seqId;
	int width;
	int height;
	int area;

	Rect(int seqId, int width, int height);
	bool isGreaterThan(Rect rect);
};


#endif /* rect_hpp */
