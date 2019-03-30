#include <stdio.h>
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class TreeNode {
public:
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

struct Node
{
	int data;
	struct Node *next;
};

struct LinkedList {
	int val;
	LinkedList *next;
	LinkedList() : val(0), next(NULL) {}
	LinkedList(int x) : val(x), next(NULL) {}
};

struct SNode
{
	SNode() {}
	SNode *mpNext = nullptr;
	SNode *mpPrev = nullptr;
};

struct SGraphData
{
	SGraphData() {}
	int mSubGraphCount = 0;
	int mLoopCount = 0;

	void IncrementLoopCount() { mLoopCount++; }
	void DecrementLoopCount() { mLoopCount--; }

	void IncrementGraphCount() { mSubGraphCount++; }
	void DecrementGraphCount() { mSubGraphCount--; }
};

void PostLoadNode(SGraphData * const pGraphData, SNode * const pNode)
{
	std::vector<SNode*> closedList;					//closed list to keep track of the nodes visited from the subgraph
	SNode *pNodeCopy = pNode;

	//Increment the sub-graph count if previous pointer is null
	if (pNode->mpPrev == nullptr)
		pGraphData->IncrementGraphCount();
	
	while (pNodeCopy->mpNext != nullptr)
	{
		//if next is source, loop found
		if (pNodeCopy->mpNext == pNode)
		{
			pGraphData->IncrementLoopCount();
			return;
		}
		closedList.emplace_back(pNodeCopy);
		pNodeCopy = pNodeCopy->mpNext;

		//check if something is already on closed list, retun if true
		for (auto i : closedList)
		{
			//if current is already in closed list, we are looping and break
			if (i == pNodeCopy)
			{
				return;
			}
		}
	}
}

void DeleteNode(Node* nodeToDelete, Node* root)
{
	//use a prev pointer which will help in linking the correct object when something is deleted
	Node *pPtr = root;
	Node *pPrevPtr = root;

	//do will run at least once
	//to avoid first time erros, we use while instead of do while
	while (pPtr != nullptr)
	{
		if (pPtr == nodeToDelete)
		{
			if (pPtr == pPrevPtr)
			{
				pPtr = pPtr->next;
				delete(pPrevPtr);
			}
			else
			{
				pPrevPtr->next = pPtr->next;
				//deleting objects may still faile the nullptr check based on the implementation
				pPtr = nullptr;
				delete(pPtr);
			}			
		}
		//sanity check, pPtr might be deleted previously
		if (pPtr != nullptr)		
		{
			pPrevPtr = pPtr;
			pPtr = pPtr->next;
		}
	} 
}

TreeNode* insert(TreeNode* root, int data)
{
	if (root == NULL) {
		return new TreeNode(data);
	}
	else {
		TreeNode* cur;
		if (data <= root->data) {
			cur = insert(root->left, data);
			root->left = cur;
		}
		else {
			cur = insert(root->right, data);
			root->right = cur;
		}
		return root;
	}
}

Node* InsertTail(Node *head, int data)
{
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->data = data;

	curr = head;
	if (head != NULL)
	{
		while (curr->next != NULL)
			curr = curr->next;

		curr->next = newNode;
	}
	else
	{
		head = newNode;
		newNode->next = NULL;
	}
	return head;
}

Node* InsertHead(Node *head, int data)
{
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->data = data;

	curr = newNode;
	if (head != NULL)
		curr->next = head;

	return curr;
}

Node* InsertAtPosition(Node *head, int data, int position)
{
	int currentPosition = 0;
	Node* curr = new Node();
	Node* prev = new Node();
	Node* newNode = new Node();
	newNode->data = data;	

	curr = head;
	prev = curr;
	if (head != NULL)
	{
		while (curr->next != NULL && currentPosition != position)
		{
			prev = curr;
			curr = curr->next;
			currentPosition++;
		}
		if (position == 0)
		{
			head = newNode;
			head->next = prev;
		}
		else
		{
			newNode->next = curr;
			prev->next = newNode;
		}
	}
	else
	{
		head = newNode;
		newNode->next = NULL;
	}
	return head;
}

int lengthOfLongestSubstring(string s)
	{
		if (s.length() < 1)
			return 0;
		std::vector<int> indexVector;
		indexVector.push_back(0);
		int result = 1;
		int output = 1;
		bool ifExists = false;
		for (int i = 1; i < s.length(); i++)
		{
			ifExists = false;
			for (int j = 0; j < indexVector.size(); j++)
			{
				if (s[i] == s[indexVector[j]])
				{


					for (int k = j; k >= 0; k--)
					{
						indexVector.erase(indexVector.begin());

					}


					indexVector.push_back(i);

					ifExists = true;
					break;
				}
			}
			if (!ifExists)
			{
				indexVector.push_back(i);

			}

			if (indexVector.size() > result)
				result = indexVector.size();
		}
		return result;
	}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> merged;
		int i = 0;
		int j = 0;
		double median = 0.0;

		if (nums1.size() == 0 && nums2.size() == 0)
			return median;
		else if (nums1.size() == 0)
			merged = nums2;
		else if (nums2.size() == 0)
			merged = nums1;
		else
		{
			while (merged.size() != nums1.size() + nums2.size())
			{
				if (nums1[i] > nums2[j])
				{
					merged.push_back(nums2[j]);
					j++;
					if (j == nums2.size())
					{
						for (int k = i; k < nums1.size(); k++)
							merged.push_back(nums1[k]);

						break;
					}
				}
				else
				{
					merged.push_back(nums1[i]);
					i++;
					if (i == nums1.size())
					{
						for (int k = j; k < nums2.size(); k++)
							merged.push_back(nums2[k]);

						break;
					}
				}
			}
		}
		if (merged.size() % 2 == 0)
			median = (double)(merged[merged.size() / 2] + merged[merged.size() / 2 - 1]) / 2;
		else
			median = merged[(merged.size() - 1) / 2];

		return median;
	}

int KindergardenAdventures()
{
	int o_ID = 0;
	int n;
	int tempTime;
	int failed = 0;
	int pass = 0;
	vector<int> time;
	vector<int> fail;
	cout << "Enter number of students";
	cin >> n;

	for (int i = 0; i < n;i++)
	{
		cout << "Enter time for student-" << i;
		cin >> tempTime;
		time.push_back(tempTime);
	}

	o_ID = 1;

	for (int i = 0; i < n; i++)
	{ 
		tempTime = i;
		fail.push_back(0);
		for (int j = 0; j < n; j++)
		{
			if (time[tempTime++] > j)
			{
				fail[i]++;
			}
			if (tempTime >= n)
				tempTime = 0;
		}			
	}

	for (int i = 1; i < n; i++)
	{
		if (fail[i] < fail[o_ID-1])
			o_ID = i + 1;
	}

	return o_ID;
}

bool IsPalindrome(string s)
{
	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

int ExpandAroundCenter(string s, int i_left, int i_right)
{
	int o_l = i_left;
	int o_r = i_right;
	while (o_l >= 0 && o_r < s.length() - 1 && s[o_l] == s[o_r])
	{
		o_l--;
		o_r++;
	}
	return o_r - o_l - 1;
}

string longestPalindrome(string s) {
	/*string o_palindrome = "";
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = s.length(); j >= 1; j--)
		{
			if (j < o_palindrome.length())
			{
				break;
			}
			temp = s.substr(i, j);
			if (IsPalindrome(s.substr(i, j)))
			{		
				if (s.substr(i, j).length() > o_palindrome.length())
				{
					o_palindrome = s.substr(i, j);
					break;
				}
			}
		}
	}*/

	int start = 0;
	int end = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int len1 = ExpandAroundCenter(s, i,i);
		int len2 = ExpandAroundCenter(s, i, i + 1);
		int len = 0;
		if (len1 > len2)
			len = len1;
		else
			len = len2;

		if (len > end - start)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	return s.substr(start, end - start + 1);

	//return o_palindrome;
}

int TreeHeight(TreeNode* root) 
{
	if (root == nullptr)
		return -1;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

void MergeIntervals(vector<Interval>& i_intervals)
{
	int i = 0;

	while (i < i_intervals.size()-1)
	{
		if (i_intervals[i + 1].start <= i_intervals[i].end)
		{
			if (i_intervals[i+1].end > i_intervals[i].end)
				i_intervals[i].end = i_intervals[i + 1].end;

			i_intervals.erase(i_intervals.begin() + i + 1);
		}
		else
			i++;
	}
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
{
	//vector<Interval> result;
	for (int i = 0; i < intervals.size(); i++)
	{
		if (newInterval.start < intervals[i].start)
		{
			vector<Interval>::iterator ite = intervals.begin();
			intervals.insert(ite + i, newInterval);
			break;
		}
	}

	MergeIntervals(intervals);
	return intervals;
}

int MyAtoi(string str) 
{
	int result = 0;
	double range = 0;
	if (str.length() < 1)
		return result;
	
	int sign = 1;
	int i = 0;
	int digits = 0;
	while (str[i] == ' ')
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			range = range * 10 + str[i] - '0';
			digits++;

			if (range > 2147483647)
			{
				if (sign == 1)
					return 2147483647;
				else
					return sign * 2147483648;
			}
		}			
		else return result*sign;
	}
	return sign*result;
}

Node* MergeKLists(vector<Node*>& lists) 
{
	
	for (int i = 0; i < lists.size()-1; i++)
	{
		Node* temp = lists[i];
		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = lists[i + 1];
	}

	return lists[0];
}

vector<vector<char>> Minesweeper(vector<vector<char>> grid) 
{
	vector<vector<char>> result;
	vector<char> r;
	int num = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		r.clear();
		for (int j = 0; j < grid[i].size(); j++)
		{
			num = 0;
			if (grid[i][j] == 'X')
				r.push_back('X');			
			else
			{
				if (j - 1 >= 0)
				{
					if (grid[i][j - 1] == 'X')
						num++;
				}
				if (j + 1 < grid[i].size())
				{
					if (grid[i][j + 1] == 'X')
						num++;
				}
				if (i - 1 >= 0)
				{
					if (grid[i - 1][j] == 'X')
						num++;

					if (j - 1 >= 0)
					{
						if (grid[i - 1][j - 1] == 'X')
							num++;
					}
					if (j + 1 < grid[i].size())
					{
						if (grid[i - 1][j + 1] == 'X')
							num++;
					}
				}
				if (i + 1 < grid[i].size())
				{
					if (grid[i + 1][j] == 'X')
						num++;

					if (j - 1 >= 0)
					{
						if (grid[i + 1][j - 1] == 'X')
							num++;
					}
					if (j + 1 < grid[i].size())
					{
						if (grid[i + 1][j + 1] == 'X')
							num++;
					}
				}
				r.push_back(num);
			}
		}
		result.push_back(r);

	}
	return result;
}

LinkedList* AddTwoNumbers(LinkedList* i_first, LinkedList* i_second)
{
	LinkedList *result;
	result = nullptr;
	int carry = 0;
	while (i_first != nullptr && i_second != nullptr)
	{
		LinkedList *current = new LinkedList();
		int temp = i_first->val + i_second->val + carry;
		if (temp > 9)
		{		
			temp %= 10;
			current->val = temp;// +carry;
			carry = 1;
		}
		else
		{
			current->val = temp;// +carry;
			carry = 0;
		}

		if (result == nullptr)
		{
			result = new LinkedList(current->val);
		}
		else
		{
			LinkedList* temp = new LinkedList();
			temp = result;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = current;
		}
		i_first = i_first->next;
		i_second = i_second->next;
	}

	if (i_first != nullptr)
	{
		while (i_first != nullptr)
		{
			LinkedList *current = new LinkedList();
			int temp = i_first->val + carry;
			if (temp > 9)
			{
				temp %= 10;
				current->val = temp;
				carry = 1;
			}
			else
			{
				current->val = i_first->val + carry;
				carry = 0;
			}

			LinkedList* tempList = new LinkedList();
			tempList = result;
			while (tempList->next != nullptr)
			{
				tempList = tempList->next;
			}
			tempList->next = current;
			i_first = i_first->next;
		}
	}
	else if (i_second != nullptr)
	{
		while (i_second != nullptr)
		{
			LinkedList *current = new LinkedList();
			int temp = i_second->val + carry;
			if (temp > 9)
			{
				temp %= 10;
				current->val = temp;
				carry = 1;
			}
			else
			{
				current->val = i_second->val + carry;
				carry = 0;
			}

			LinkedList* tempList = new LinkedList();
			tempList = result;
			while (tempList->next != nullptr)
			{
				tempList = tempList->next;
			}
			tempList->next = current;
			i_second = i_second->next;
		}
	}

	if (carry != 0)
	{
		LinkedList* temp = new LinkedList();
		temp = result;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new LinkedList(carry);
	}





	/*if (i_first != nullptr)
	{
		LinkedList* temp = new LinkedList();
		temp = result;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = i_first;
		if (carry != 0)
		{
			if (temp->next->val + carry > 9)
			{
				while(i_first != nullptr)
				{
				}
				temp->next->val = 0;
				temp->next->next = new LinkedList(1);
			}
			else
			{
				temp->next->val += carry;
			}
		}
	}
	else if (i_second != nullptr)
	{
		LinkedList* temp = new LinkedList();
		temp = result;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = i_second;
		if (carry != 0)
		{
			if (temp->next->val + carry > 9)
			{
				temp->next->val = 0;
				temp->next->next = new LinkedList(1);
			}
			else
			{
				temp->next->val += carry;
			}
		}
	}
	else if (carry != 0)
	{
		LinkedList* temp = new LinkedList();
		temp = result;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new LinkedList(carry);		
	}*/
	return result;
}

LinkedList* Reverse(LinkedList* i_list)
{
	LinkedList *current = new LinkedList();
	LinkedList *prev = new LinkedList();
	LinkedList *next = new LinkedList();
	current = i_list;
	prev = nullptr;
	next = nullptr;	
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

string ZigZagPattern(string s, int numRows)
{	
	std::vector<string> rowStrings(numRows);
	for (int i = 0; i < numRows; i++)
	{
		rowStrings[i] = s;
		for (int j = 0; j < rowStrings[i].length(); j++)
		{
			rowStrings[i][j] = ' ';
		}
	}
	//string output = s;
	int sign = 1;
	int index2 = 0;
	int individualIndex = 0;
	int currentRow = 0;
	while (index2 < s.length())
	{	
		/*if (individualIndex == 0)
		{
			rowStrings[currentRow] = new char();
		}*/
		rowStrings[currentRow][individualIndex] = s[index2];
		index2++;		
		currentRow = currentRow + sign;
		if (currentRow == numRows || currentRow < 0)
		{
			sign *= -1;	
			currentRow += sign;
			currentRow += sign;
			individualIndex++;
		}		
	}
	string output = s;
	//int index = 0;
	//int x = 0;
	//int y = 0;
	//if (numRows == 1)
	//	return s;
	//else if (s.length() <= numRows)
	//	return s;

	//for (int i = 0; i < numRows; i++)
	//{
	//	if (i >= numRows / 2)
	//	{
	//		x = numRows - i - 1;
	//	}
	//	else
	//	{
	//		x = i;
	//	}
	//	y = 0;
	//	for (int j = i; j < s.length(); )
	//	{			
	//		output[index] = s[j];
	//		index++;
	//		y++;
	//		if (numRows > 3 && i == 1 && y % 2 == 0)
	//		{
	//			j += 2;
	//			if (j < s.length())
	//			{
	//				output[index] = s[j];
	//				index++;
	//				y++;
	//			}
	//		}
	//		else if (numRows > 3 && i == numRows - 2 && y % 2 != 0)
	//		{
	//			j += 2;
	//			if (j < s.length())
	//			{
	//				output[index] = s[j];
	//				index++;
	//				y++;
	//			}
	//		}
	//		j += numRows - x - 1 + numRows - x - 2 + 1;// +i + i;		
	//	}
	//}


	output = "";
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < rowStrings[i].length(); j++)
		{
			if (rowStrings[i][j] !=' ')
				output += rowStrings[i][j];
		}
		
	}

	return output;
}

int Reverse(int x)
{

	int result = 0;

	while (x != 0)
	{
		int t = x % 10;
		x /= 10;
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && t > 7))
			return 0;
		else if (result < INT_MIN / 10 || (result == INT_MIN / 10 && t < -8))
			return 0;
		result = result * 10 + t;
	}
	return result;

}

bool HorizontalMatching(int i_tilesCompleted, char** o_result, char** i_currentTile)
{
	bool res = false;

	return res;
}

bool VerticalMatching(int i_tilesCompleted, char** o_result, char* i_currentTile)
{
	bool res = false;

	return res;
}

bool RotateAndMatch(int i_tilesCompleted, int i_rotation, char **o_result, char **i_currentTile)
{
	bool res = false;
	
	//No Rotation
	if (i_rotation == 0)
	{
			
	}
	//anti-clockwise
	if (i_rotation < 0)
	{

	}
	//clockwise
	else
	{

	}

	return res;
}

void link(char **tiles)
{
	int tileeCompleted = 0;
	char **o_result = tiles;
	int i = 0;
	char* currentTile[] = { "", "", };
	while (*tiles)
	{			
		if (*tiles == "")
		{
			if (!tileeCompleted == 0)
			{
				int rotation = 0;
				while (!RotateAndMatch(tileeCompleted, rotation, o_result, currentTile))
				{
					if (rotation >= 0)
					{
						rotation += 90;
						if (rotation == 360)
							rotation = -90;
					}
					else
					{
						rotation -= 90;
					}
				}
			}

			i = 0;
			printf(*tiles);
			*tiles++;
			tileeCompleted++;
		}		
	
		currentTile[i] = *tiles;		
		i++;
		*tiles++;
	}	
}

char const *get_previous_word(char const *pTargetWord, char const * const *ppUnsortedDictionary, size_t const unsortedDictionaryLength)
{
	char* o_previousWord =  nullptr;	
	string currentWord;
	currentWord = "";
	int difference = 0;
	int min = 100;
	int currentIndex;
	int currentLength;
	int minLength =0;

	for (size_t i = 0; i < unsortedDictionaryLength; i++)
	{
		currentIndex = 0;
		currentLength = 0;
		while (ppUnsortedDictionary[i][currentIndex] != NULL)
		{
			if (ppUnsortedDictionary[i][currentIndex] != ' ')
			{
				currentWord += (ppUnsortedDictionary[i][currentIndex]);
				if (pTargetWord[currentLength] && difference >= 0)
				{
					difference += pTargetWord[currentLength] - (ppUnsortedDictionary[i][currentIndex]);
					currentLength++;
				}				
			}
			else
			{				
				if (difference < min && difference > 0)
				{
					min = difference;
					minLength = currentWord.size();
					o_previousWord = const_cast<char*>(ppUnsortedDictionary[i]) + currentIndex - currentWord.size();					
				}
				currentWord = "";
				difference = 0;		
				currentLength = 0;
			}
			currentIndex++;
		}

		//For the last word in the sentence
		if (difference < min && difference > 0)
		{
			min = difference;
			minLength = currentWord.size();
			o_previousWord = const_cast<char*>(ppUnsortedDictionary[i]) + currentIndex - currentWord.size();			
		}
		currentWord = "";
		difference = 0;
	}
	return o_previousWord;
}

int maxArea(vector<int>& height) {
	int o_max = 0;

	int end = height.size() - 1;
	int start = 0;
	while (start < end)
	{
		int x = end - start;
		int y = height[start] > height[end] ? height[end] : height[start];
		o_max = (x*y) > o_max ? (x*y) : o_max;
		height[start] > height[end] ? end-- : start++;
	}

	return o_max;
}

bool isMatch(string s, string p) 
{
	if (s.length() < 1)
		return false;

	bool o_result = true;
	int expIndex = 0;
	int strIndex = 0;
	while (expIndex < p.length())// && strIndex < s.length())
	{
		if (strIndex == s.length())
		{
			//o_result = false;
			break;
		}
		else if (p[expIndex] == '.')
		{
			expIndex++;
			strIndex++;
		}
		else if (p[expIndex] == '*')
		{
			expIndex++;
			strIndex++;
		}
		else if (p[expIndex] != s[strIndex])
		{
			expIndex++;
			if (expIndex >= p.length())
			{
				o_result = false;
				return o_result;
			}
			if (p[expIndex] == '*')
				expIndex++;
			else
			{
				o_result = false;
				break;
			}
		}
		else if (p[expIndex] == s[strIndex])
		{
			strIndex++;
			if (expIndex + 1 < p.length())
			{
				if (p[expIndex + 1] == '*')
				{
					while (p[expIndex] == s[strIndex])
					{
						strIndex++;
					}
					expIndex++;
				}				
			}
			expIndex++;
		}
	}
	if (strIndex != s.length())
	{
		if (expIndex != p.length())
		{
			if (p[expIndex] != '*')
				o_result = false;
		}
		else
			o_result = false;
	}
	return o_result;
}


vector<int> IDsOfPackages(int truckSpace, vector<int> packagesSpace)
{
	// WRITE YOUR CODE HERE
	std::vector<int> o_package;
	o_package.reserve(2);

	if (truckSpace <= 30)
	{
		//not enough truck space, return empty list
		return o_package;
	}
	int size = packagesSpace.size();


	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (truckSpace - (packagesSpace[i] + packagesSpace[j]) == 30)
			{
				//30 truck space left, return elements
				o_package.emplace_back(i);
				o_package.emplace_back(j);
				return o_package;
			}
		}
	}
	//no two packages found
	return o_package;
}

int main()
	{
#pragma region
	/*Problem 1:
	You are working on a C program that defines and uses these types.


		typedef unsigned int U32;

	typedef struct HatPart
	{
		U32 iPartCode;
		U32 iCost;
		U32 iColor;
	}
	HatPart;

	typedef struct Hat
	{
		char hatName[64]; //null-terminated ascii string, might be empty
		U32 iHatSize;
		U32 iHatModel;
		char manufacturerName[64]; //null-terminated ascii string, might be empty
		U32 iNumParts; //the number of parts in this hat, min = 0, max = 16
		HatPart parts[16];
	}
	Hat;

	Note that the Hat struct is inefficient in terms of memory usage. If the hatName is "bowler", then 57 bytes are wasted in the fixed-size string buffer.
	If a Hat only has 3 parts, then 13 entire HatPart substructs are wasted. However, for architectural reasons, the Hat struct must remain unchanged.

	We would like to be able to store Hats in less memory when they are not being used. So, we'd like you to write two functions.
	// returns the packed buffer, and the output size
	void *PackHat(const Hat *pHat, int *piOutSize);

	// returns false on failure
	bool UnpackHat(const void *pPackedBuffer, int iPackedBufferSize,

	PackHat takes a Hat struct and returns a buffer, allocated via malloc(), with all the data from the Hat struct packed as tightly as possible.
	That is, if a string is 6 bytes long, it only occupies 7 bytes in the packed buffer (6 bytes for string characters, one byte for the null terminator).
	If the hat only has 4 parts, then the parts will only take up 48 bytes in the packed buffer (4 parts times 3 U32s times 4 bytes).

	UnpackHat takes a buffer packed by PackHat and reverses the process into an existing Hat struct.
	Notes:
	There are many clever approaches that could be used to pack or compress data far more effectively and ambitiously than simple byte packing. Please do not attempt any of them. You should use 4 bytes of buffer space for every U32, even if its value is 0 and more efficient approaches could be used. Do not attempt to re-create zipping.
	Do not worry about the fact that we�re using 32 bits to store iNumParts even though the maximum legal value is only 16.
	UnpackHat returns a bool, and can fail. It should check the legality of the data it is unpacking, and fail if,
	for any reason, the data cannot be unpacked into a legal Hat struct, or if the size of the data passed in is not precisely correct.

	Here are three sample inputs, and the precise byte size the packed buffer should be.
	// expected size: 84 bytes
	Hat hat1 =
	{
		"Bowler",
		 17,
		 1000000,
		 "United Hats of San Francisco",
		3,
	{
		 {
			  20,30,40,
		 },
		 {
			 50,60,70,
		 },
		 {
			 80,90,100,
		 },
	}
	};


	Problem 2:

	Write a function "void link(char **tiles)" that accepts a list of 'tiles' in the provided format below.
	It should link the tiles together sequentially in the order they are given,
	and print out the current count and arrangement of tiles at each step exactly as shown in the example output below,
	including the note about how far the tile had to be rotated.

	A tile is a 2-by-2 square split into quadrants, where each quadrant has a number from 0 to 9.
	After the first tile, a tile can be legally placed if at least two of its quadrants match quadrants on adjacent tiles horizontally or vertically.
	A tile cannot be legally placed in a location if it would have fewer than two matching quadrants or has any quadrants that do not match horizontally or vertically.
	Tiles can be rotated, and tiles can be placed in offset positions as demonstrated with tile 9 in the third example.
	The inputs are always designed so there is only one place a tile will fit.

	*/

	char *tiles1[] = {
	"11",     // 1
	"23",
	"",
	"44",     // 2
	"11",
	"",
	"16",     // 3
	"36",
	"",
	"51",     // 4
	"71",
	"",
	"46",     // 5
	"26",
	"",
	"14",     // 6
	"68",
	0 };

	//link(tiles1);

#pragma endregion

#pragma region Question1: Longest substring without repeating characters
		/*
		Given a string, find the length of the longest substring without repeating characters.
		Examples:
		Given "abcabcbb", the answer is "abc", which the length is 3.
		Given "bbbbb", the answer is "b", with the length of 1.
		Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
		*/
	

		//string s = "pwwkew";
		//int i = lengthOfLongestSubstring(s);

#pragma endregion

#pragma region Question2: Median of two sorted array
		/*
		There are two sorted arrays nums1 and nums2 of size m and n respectively.
		Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

		Example 1:
		nums1 = [1, 3]
		nums2 = [2]
		The median is 2.0

		Example 2:
		nums1 = [1, 2]
		nums2 = [3, 4]
		The median is (2 + 3)/2 = 2.5
		*/
		//vector<int> a = { 1, 8, 16, 40 };
		//vector<int> b = { 2, 3, 5, 9, 11, 17 };
		//double median = findMedianSortedArrays(a, b);
#pragma endregion

#pragma region Question3: Insert node at TAIL of linked list
		/*
		You are given the pointer to the head node of a linked list and an integer to add to the list.
		Create a new node with the given integer. 
		Insert this node at the TAIL of the linked list and return the head node of the linked list formed after inserting this new node.
		The given head pointer may be null, meaning that the initial list is empty.
		*/

		Node* p = new Node();
		p->data = 1;
		p->next = nullptr;

		Node* p2 = new Node();
		p2->data = 2;
		p2->next = p;

		Node* p3 = new Node();
		p3->data = 3;
		p3->next = p2;

		//Node* res = InsertTail(p3, 4);
#pragma endregion
		
#pragma region Question4: Insert node at HEAD of a linked list
		/*
		You are given the pointer to the head node of a linked list and an integer to add to the list.
		Create a new node with the given integer.
		Insert this node at the HEAD of the linked list and return the head node of the linked list formed after inserting this new node.
		The given head pointer may be null, meaning that the initial list is empty.
		*/
		//res = InsertHead(p3, 4);
#pragma endregion

#pragma region Question5: Insert node at specific position in a linked list
		/*
		You�re given the pointer to the head node of a linked list, an integer to add to the list and the position at which the integer must be inserted. 
		Create a new node with the given integer, insert this node at the desired position and return the head node. 
		A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. 
		The head pointer given may be null meaning that the initial list is empty.
		*/
		//res = InsertAtPosition(p3, 12, 2);
#pragma endregion

#pragma region Question6: Kindergarden Adventures (Fix Time Complexity)
		/*
		Meera teaches a class of  students, and every day in her classroom is an adventure. Today is drawing day!
		The students are sitting around a round table, and they are numbered from  to  in the clockwise direction. 
		This means that the students are numbered , and students  and  are sitting next to each other.
		After letting the students draw for a certain period of time, Meera starts collecting their work to ensure she has time to review all the
		drawings before the end of the day.
		However, some of her students aren't finished drawing! Each student  needs  extra minutes to complete their drawing.
		Meera collects the drawings sequentially in the clockwise direction, starting with student ID , and it takes her exactly minute to review each drawing.
		This means that student  gets  extra minutes to complete their drawing, student  gets  extra minute, student  gets  extra minutes, and so on.
		Note that Meera will still spend minute for each student even if the drawing isn't ready.
		Given the values of , help Meera choose the best possible  to start collecting drawings from, such that the number of students
		able to complete their drawings is maximal. Then print  on a new line. If there are multiple such IDs, select the smallest one.

		Input Format
		The first line contains a single positive integer, , denoting the number of students in the class.
		The second line contains  space-separated integers describing the respective amounts of time that each student needs to finish their drawings (i.e., ).
		
		Output Format
		Print an integer denoting the ID number, , where Meera should start collecting the drawings such that a maximal number of students can complete their drawings.
		If there are multiple such IDs, select the smallest one.

		Sample Input
		3
		1 0 0
		Output
		2
		*/
		//int result = KindergardenAdventures();
#pragma endregion

#pragma region Question7: Longest Palindrome
		/*
		Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

		Example:
		Input: "babad"
		Output: "bab"
		Note: "aba" is also a valid answer.

		Example:
		Input: "cbbd"
		Output: "bb"
		*/
		string palindrome = longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
#pragma endregion

#pragma region Question8: Height of Binary Tree
		/*
		The height of a binary tree is the number of edges between the tree's root and its furthest leaf. This means that a tree containing a single node has a height of.
		Complete the getHeight function provided in your editor so that it returns the height of a binary tree. This function has a parameter root , 
		which is a pointer to the root node of a binary tree.
		Note -The Height of binary tree with single node is taken as zero.

		Input Format
		You do not need to read any input from stdin. Our grader will pass the root node of a binary tree to your getHeight function.

		Output Format
		Your function should return a single integer denoting the height of the binary tree.
		*/
		TreeNode *n = new TreeNode(1);
		n->left = new TreeNode(2);
		n->right = new TreeNode(3);

		n->left->left = new TreeNode(4);
		n->left->right = new TreeNode(6);

		n->right->left = new TreeNode(7);
		n->right->right = new TreeNode(5);

		n->right->right->right = new TreeNode(8);

		//int h = TreeHeight(n);

#pragma endregion

#pragma region Question9: Insert Interval
		/*
		Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
		You may assume that the intervals were initially sorted according to their start times.

		Example 1:
		Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

		Example 2:
		Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

		This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
		*/

		Interval i;
		i.start = 1;
		i.end = 2;

		vector<Interval> intervals;
		intervals.push_back(i);

		i.start = 3;
		i.end = 5;
		intervals.push_back(i);
		i.start = 6;
		i.end = 7;
		intervals.push_back(i);
		i.start = 8;
		i.end = 10;
		intervals.push_back(i);
		i.start = 12;
		i.end = 16;
		intervals.push_back(i);
		i.start = 25;
		i.end = 28;
		intervals.push_back(i);
		
		i.start = 4;
		i.end = 9;
		insert(intervals, i);

#pragma endregion

#pragma region Question10: Atoi
		/*
		Implement atoi to convert a string to an integer.
		*/

		//string input = "      -11919730356x";
		//int r = MyAtoi(input);
#pragma endregion

#pragma region Question11: Minesweeper
		/*
		Given a minesweeping problem where you have to find out how many mines are adjacent to a given cell in a grid.
		Cells with mines are denoted by 'X' in the grid.
		*/
		vector<vector<char>> input;
		vector <char> temp;
		
		temp.push_back('?');
		temp.push_back('?');
		temp.push_back('?');

		input.push_back(temp);
		temp.clear();

		temp.push_back('?');
		temp.push_back('X');
		temp.push_back('?');
		input.push_back(temp);
		temp.clear();

		temp.push_back('?');
		temp.push_back('?');
		temp.push_back('X');
		input.push_back(temp);
		temp.clear();

		Minesweeper(input);


#pragma endregion

#pragma region Question12: Add two numbers as linked list
		/*
		You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. 
		Add the two numbers and return it as a linked list.
		You may assume the two numbers do not contain any leading zero, except the number 0 itself.

		Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		Output: 7 -> 0 -> 8
		Explanation: 342 + 465 = 807.
		*/

		LinkedList *first_1 = new LinkedList(3);
		LinkedList *first_2 = new LinkedList(7);
		//LinkedList *first_3 = new LinkedList(9);
		first_1->next = first_2;
		//first_2->next = first_3;
		/*LinkedList *first_3 = new LinkedList(3);		
		LinkedList *first_4 = new LinkedList(1);
		LinkedList *first_5 = new LinkedList(6);		
		first_2->next = first_3;
		first_3->next = first_4;
		first_4->next = first_5;*/

		LinkedList *second_1 = new LinkedList(9);
		LinkedList *second_2 = new LinkedList(2);
		second_1->next = second_2;
		/*LinkedList *second_3 = new LinkedList(4);
		
		second_2->next = second_3;*/

		LinkedList *result = new LinkedList();		
		//first_1 = Reverse(first_1);
		//second_1 = Reverse(second_1);
		//result = AddTwoNumbers(first_1, second_1);


#pragma endregion

#pragma region Question13: ZigZag String Pattern (Improve Time complexity)
		/*
		The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
		P   A   H   N
		A P L S I I G
		Y   I   R
		And then read line by line: "PAHNAPLSIIGYIR"

		Example:
		Input: s = "PAYPALISHIRING", numRows = 4
		Output: "PINALSIGYAHRPI"
		Explanation:
		P     I    N
		A   L S  I G
		Y A   H R
		P     I
		*/

		//string s = ZigZagPattern("PAYPALISHIRING",6);
#pragma endregion

#pragma region Question13:Reverse integer
		/*
		Given a 32-bit signed integer, reverse digits of an integer.

		Example 1:
		Input: -123
		Output: -321
		*/

		//int s = Reverse(123);
#pragma endregion

#pragma region Question14:Get Previous word
	/*
		Finds the word that comes just before targetWord in alphabetical order in an unsorted dictionary. 
		For example, get_previous_word("interview", ppDictionary, dictionaryLength) might return "interventions".
	*/
		char const * target = "intere";
		//char const * const * unsortedDictionary = { new char*("interaasad intere interd dictionary"), new char* ("asdads") };
		char ** unsortedDictionary;
		unsortedDictionary = new char*[5];
		unsortedDictionary[0] = "intervcfds interfsdge sdfagdsfd";
		unsortedDictionary[1] = "intererterteaasad intersve interd dicsdfasdfry";
		unsortedDictionary[2] = "interaertetasad interterere dictionary";
		unsortedDictionary[3] = "inteerterraasad inteertetere insdafterd dictionary";
		unsortedDictionary[4] = "r5teter internb bfe erte dictionary";		
		//const char* p43 = get_previous_word(target, unsortedDictionary, 5);
		//printf(p43);

#pragma endregion

#pragma region Question15:Get Previous word
/*
	Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn 
	such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
	such that the container contains the most water.

	Note: You may not slant the container and n is at least 2.
	Ex:
	The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

#pragma endregion

		string s = "aaa";
		string exp = "a*a";
		bool res = isMatch(s, exp);
		std::vector<int> a = { 20,70,90,30,60,110 };
		std::vector<int> b;
		b.reserve(2);
		b[0] = 1;
		b[1] = 1;
		
		int l = 110;
		vector<int> resl = IDsOfPackages(110, a);
		return 0;

		
	}

