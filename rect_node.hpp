//
//  rect_node.hpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#ifndef rect_node
#define rect_node

#include <algorithm>

struct RectNode {
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

#endif /* Rect_hpp */
