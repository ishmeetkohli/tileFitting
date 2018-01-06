//
//  pipeline.cpp
//  TileFitting
//
//  Created by Ishmeet Singh Kohli
//

#include "pipeline.hpp"

Pipeline::Pipeline(int width, int height) :root(width, height) {}

map<int, Result> Pipeline::fitRectangles(vector<Rect> rectangles) {
	map<int, Result> results;

	for (int i = 0; i < rectangles.size(); i++) {
		RectNode *node = findBestFit(&this->root, &rectangles[i]);
		if (node == nullptr) {
			return {};
		}
		else {
			node->split(rectangles[i].width, rectangles[i].height);
			results.emplace(rectangles[i].seqId, Result(rectangles[i].width, rectangles[i].height, node->y, node->x));
		}
	}
	return results;
}

RectNode* Pipeline::findBestFit(RectNode *root, Rect *rect) {
	if (root->used)
	{
		RectNode *leftBest = findBestFit(root->left, rect);
		RectNode *rightBest = findBestFit(root->right, rect);

		if (leftBest == nullptr && rightBest == nullptr) {
			return nullptr;
		}

		if (leftBest == nullptr) {
			return rightBest;
		}

		if (rightBest == nullptr) {
			return leftBest;
		}

		return rightBest;
	}
	else if (root->width >= rect->width && root->height >= rect->height)
	{
		root->minAllowance = min(root->width - rect->width, root->height - rect->height);
		return root;

	}
	else {
		return nullptr;
	}

}

bool Pipeline::fit(string inputFileName, string outputFileName) {
	vector<Rect> rectangles = this->parser.parseInputSet(inputFileName);
	sort(rectangles, 0, rectangles.size() - 1);
	map<int, Result> results = fitRectangles(rectangles);

	if (results.empty())
	{
		return false;
	}

	writeToOutput(results, outputFileName);
	return true;
}

void Pipeline::writeToOutput(map<int, Result> &results, string outputFileName) {
	ofstream myfile;
	try {
		myfile.open(outputFileName);
		myfile << "width,height,top,left\n";

		for (int i = 0; i < results.size(); i++)
		{
			Result result = results.find(i)->second;
			myfile << result.width << ',';
			myfile << result.height << ',';
			myfile << result.top << ',';
			myfile << result.left << '\n';
		}

		myfile.close();
	}
	catch (std::ofstream::failure &writeErr) {
		throw std::runtime_error("Exception writing to the file");
	}

}

void Pipeline::sort(vector<Rect> &rectangles, int low, int high) {
	if (low < high)
	{
		int index = partition(rectangles, low, high);
		sort(rectangles, low, index - 1);  // Before index
		sort(rectangles, index + 1, high); // After index
	}
}

int Pipeline::partition(vector<Rect> &rectangles, int low, int high)
{
	// pivot (Element to be placed at right position)
	Rect pivot = rectangles[high];
	int i = low - 1;  // Index of greater element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is greater than pivot
		if (rectangles.at(j).isGreaterThan(pivot))
		{
			i++;    // increment index of greater element
			swap(rectangles, i, j);
		}
	}
	swap(rectangles, i + 1, high);
	return (i + 1);
}

void Pipeline::swap(vector<Rect> &rectangles, int i, int j)
{
	Rect temp = rectangles[i];
	rectangles[i] = rectangles[j];
	rectangles[j] = temp;
}