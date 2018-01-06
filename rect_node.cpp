//
//  rect_node.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#include "rect_node.hpp"

RectNode::RectNode(int width, int height) {
	this->width = width;
	this->height = height;
	this->x = 0;
	this->y = 0;

	this->used = false;
	this->minAllowance = INT_MAX;
	this->left = nullptr;
	this->right = nullptr;
}

void RectNode::split(int width, int height) {
	this->used = true;

	this->left = new RectNode(this->width, this->height - height);
	this->left->x = this->x;
	this->left->y = this->y + height;

	this->right = new RectNode(this->width - width, height);
	this->right->x = this->x + width;
	this->right->y = this->y;
}