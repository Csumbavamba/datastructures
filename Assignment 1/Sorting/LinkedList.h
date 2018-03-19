#pragma once
class LinkedList
{
private:
	int list[10];
public:
	LinkedList();
	~LinkedList();

	// Basic functions
	int GetData(int position);
	void SetData(int data, int position);
	
	void SwapData(int position1, int position2);
	bool IsListAscending(); // is it sorted

	// Bubble sorting
	void BubbleSort();

	// Selection sorting
	void SelectionSort();

	// Insertion sorting
	void InsertionSort();
	
	// Display
	void DisplayData();

	// For testing
	void GenerateRandomArray();
	void SlowDisplay();
	void TestHarness();
};

