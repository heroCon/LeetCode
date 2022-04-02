// myLcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class S9 {
public:
	bool isPalindrome(int x) {
		std::string str = std::to_string(x);
		for (size_t i = 0; i < ((str.size() + 1) / 2); ++i)
		{
			if (str[i] != str[str.size() - 1 - i])
				return false;
		}
		return true;
	}

private:

};
class S9_1 {
public:
	bool isPalindrome(int x) {
		// 特殊情况：
		// 如上所述，当 x < 0 时，x 不是回文数。
		// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
		// 则其第一位数字也应该是 0
		// 只有 0 满足这一属性
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
		// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
		// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
		return x == revertedNumber || x == revertedNumber / 10;
	}
};

class S10 {

public:
	bool isMatch(string s,string p) {
	}
};

class S11 {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		for (int i = 0; (size_t)i < height.size(); i++)
		{
			for (int j = i + 1; (size_t)j < height.size(); j++)
			{
				int mh = height[i] > height[j] ? height[j] : height[i];
				if (mh * (j - i) > max)
					max = mh * (j - i);
			}
		}
		return max;
	}
};

class S11_1 {
public:
	//双指针，指向较小的数的指针移动
	int maxArea(vector<int>& height) {
		int max = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j)
		{
			int mh = height[i] > height[j] ? height[j] : height[i];
			if (mh * (j - i) > max)
				max = mh * (j - i);
			if (height[i] > height[j])
				j--;
			else
				i++;
		}
		return max;
	}
};

class S12 {
public:
	string intToRoman(int num) {
		string str = to_string(num);
		reverse(str.begin(),str.end());
		int a[7] = {1,5,10,50,100,500,1000};
		//string b[7] = {"I","V","X","L","C","D","M"};

		char b[7] = { 'I','V','X','L','C','D','M' };
		string s;
		for (int i = 0; i < (int)str.size(); i++)
		{
			if ((str[i] - '0') < 5)
			{
				if ((str[i] - '0') == 4)
				{
					s.insert(s.begin(), b[2 * i + 1]);
					s.insert(s.begin(), b[2 * i]);
				}
				else
					s.insert(s.begin(), (str[i] - '0'), b[2 * i]);
			}
			else
			{
				if ((str[i] - '0') == 9)
				{
					s.insert(s.begin(), b[2 * i + 2]);
					s.insert(s.begin(), b[2 * i]);
				}
				else
				{
					s.insert(s.begin(), (str[i] - '5'), b[2 * i]);
					s.insert(s.begin(), b[2 * i + 1]);
				}
			}
		}
		return s;
	}
};

//const string thousands[] = { "", "M", "MM", "MMM" };
//const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
//const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
//const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
//
//class Solution {
//public:
//	string intToRoman(int num) {
//		return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
//	}
//};

//const pair<int, string> valueSymbols[] = {
//	{1000, "M"},
//	{900,  "CM"},
//	{500,  "D"},
//	{400,  "CD"},
//	{100,  "C"},
//	{90,   "XC"},
//	{50,   "L"},
//	{40,   "XL"},
//	{10,   "X"},
//	{9,    "IX"},
//	{5,    "V"},
//	{4,    "IV"},
//	{1,    "I"},
//};
//
//class Solution {
//public:
//	string intToRoman(int num) {
//		string roman;
//		for (const auto &[value, symbol] : valueSymbols) {
//			while (num >= value) {
//				num -= value;
//				roman += symbol;
//			}
//			if (num == 0) {
//				break;
//			}
//		}
//		return roman;
//	}
//};


class S13 {
public:
	int romanToInt(string s) {
		int count = 0;
		map<char, int> m = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		for (size_t i = 0; i < s.size(); i++) {
			if(size_t(i + 1) < s.size() && m.at(s[i]) < m.at(s[i + 1]))
				count -= m.at(s[i]);
			else
				count += m.at(s[i]);
		}
		return count;
	}
};


class S14 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		//string prefix;
		//string temp = strs[0];
		//if (strs.size() == 1)
		//	return strs[0];
		//for (int i = 1; i < strs.size(); ++i) {
		//	prefix.clear();
		//	for (int j = 0; j < (temp.size() < strs[i].size() ? temp.size() : strs[i].size());j++) {
		//		if (temp[j] != strs[i][j]) {
		//			temp = prefix;
		//			break;
		//		}
		//		prefix.insert(prefix.size(),1,temp[j]);
		//	}
		//}
		//return prefix.empty() ? "" : prefix;

		//稍微改进了一点
		string prefix = strs[0];
		if (prefix == "")
			return "";
		if (strs.size() == 1)
			return strs[0];
		for (size_t i = 1; i < strs.size(); ++i) {
			if (strs[i] == "")
				return "";
			int min = (prefix.size() < strs[i].size() ? prefix.size() : strs[i].size());
			for (int j = 0; j < min; j++) {
				if (prefix[j] != strs[i][j]) {
					auto it = prefix.begin();
					prefix.erase(prefix.begin() + j, prefix.end());
					break;
				}
				if (j == min - 1 && prefix.size() > strs[i].size())
				{
					prefix.clear();
					prefix = strs[i];
				}
			}
		}
		return prefix.empty() ? "" : prefix;
	}
};

class S15 {
public:
	//参考
	vector<vector<int>> threeSum(vector<int>& nums) {
	}
};

class S16 {
public:
	//参考
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());//泛型算法,需要#include <algorithm>
		int n = nums.size();
		int best = 1e7;

		// 根据差值的绝对值来更新答案
		auto update = [&](int cur) {
			if (abs(cur - target) < abs(best - target)) {
				best = cur;
			}
		};

		// 枚举 a
		for (int i = 0; i < n; ++i) {
			// 保证和上一次枚举的元素不相等
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			// 使用双指针枚举 b 和 c
			int j = i + 1, k = n - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				// 如果和为 target 直接返回答案
				if (sum == target) {
					return target;
				}
				update(sum);
				if (sum > target) {
					// 如果和大于 target，移动 c 对应的指针
					int k0 = k - 1;
					// 移动到下一个不相等的元素
					while (j < k0 && nums[k0] == nums[k]) {
						--k0;
					}
					k = k0;
				}
				else {
					// 如果和小于 target，移动 b 对应的指针
					int j0 = j + 1;
					// 移动到下一个不相等的元素
					while (j0 < k && nums[j0] == nums[j]) {
						++j0;
					}
					j = j0;
				}
			}
		}
		return best;
	}
};



class S17 {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		
		if (digits.empty())
			return ret;

		vector<string> numLetter = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		
		//第一个数：先往vector里依次加字母，判断后面是否有数字
		//	如果有数字，则将vector中的数据复制该数字对应的字母数size() - 1 份
		//第二个数：往vector中的所有string追加字母
		//	如果有数字，则将vector中的数据复制该数字对应的字母数size() - 1 份
		
		for (size_t i = 0; i < digits.size(); i++) {
			int num = digits[i] - '2';
			if (i == 0) {
				for (size_t j = 0; j < numLetter[num].size(); j++) {
					string s;
					s += numLetter[num][j];//等价与string s(1,numLetter[num][j]);
					ret.push_back(s);
				}
			}		
			else
			{
				for (size_t j = 0, k = 0; j < ret.size(); j++,k++) {
					string s;
					int h = ret.size() / numLetter[num].size();
					s += numLetter[num][k / h];
					ret[j] += s;
				}
			}
			if (size_t(i + 1) < digits.size())
			{
				int size = ret.size();
				int num1 = digits[i + 1] - '2';
				for(size_t k = 0; k < numLetter[num1].size()-1;k++)
					for (int j = 0; j < size; j++) {
						string s = ret[j];
						ret.push_back(s);
					}
			}

		}
		return ret;
	}
};

//四数之和
class S18
{
public:
	S18();
	~S18();

private:

};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class S19 {
public:
	//这是带有头指针的链表创建，测试使用
	ListNode *creat(int n) {
		ListNode *head, *node, *end;//定义头指针，普通节点，尾部节点；
		head = (ListNode*)malloc(sizeof(ListNode));//分配地址
		end = head;         //若是空链表则头尾节点一样
		for (int i = 0; i < n; i++) {
			node = (ListNode*)malloc(sizeof(ListNode));
			//scanf("%d", &node->val);
			node->val = i + 1;
			end->next = node;
			end = node;
		}
		end->next = NULL;//结束创建
		return head;
	}
	ListNode *creatNoHead(int n) {
		if (n == 0)
			return nullptr;
		ListNode *head, *node, *end;//定义头指针，普通节点，尾部节点；
		head = (ListNode*)malloc(sizeof(ListNode));//分配地址
		end = head;
		for (int i = 1; i < n; i++) {
			node = (ListNode*)malloc(sizeof(ListNode));
			//scanf("%d", &node->val);
			node->val = i;
			end->next = node;
			end = node;
		}
		end->next = NULL;//结束创建
		return head;
	}

public:
	//这是不带头指针的删去节点
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pEnd = head;
		int i = 0;
		int count = 1;
		ListNode* p = head;
		while (pEnd->next != nullptr) {
			count++;
			pEnd = pEnd->next;
			if (i != n)
				i++;
			else
				p = p->next;
		}
		if (n == count) {
			head = head->next;
			return head;
		}
		ListNode* temp = p->next;
		if (temp->next != nullptr)
			p->next = temp->next;
		else
			p->next = nullptr;
		//free(temp);
		return head;
	}
};

class S20 {
public:
	//采用栈
	bool isValid(string s) {
		if (s.size() % 2 != 0)
			return false;
		map<char, char>kuo = { {'(',')'},{'[',']'},{'{','}'} };
		stack<char> sta;
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(')
				sta.push(s[i]);
			else
			{
				if (sta.empty())
					return false;	//如果栈为空，当前的括号无法匹配
				if (kuo.find(sta.top())->second == s[i])
					sta.pop();
				else
					return false;
			}
		}
		return sta.empty();
	}
	//一对符号时可以不用栈
	/*bool isValid1(string s) {
		if (s.size() % 2 != 0)
			return false;
		map<char, float>kuo = { {'(',-1.1},{'[',-2.2},{'{',-3.3},{')',1.1},{']',2.2},{'}',3.3} };
		float sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum += kuo.find(s[i])->second;
			if (sum > 0)
				return false;
		}
		return true;
	}*/
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//同S19的链表
class S21 {
public:
	ListNode *creatNoHead(int n) {
		if (n == 0)
			return nullptr;
		ListNode *head, *node, *end;//定义头指针，普通节点，尾部节点；
		head = (ListNode*)malloc(sizeof(ListNode));//分配地址
		head->val = 0;
		end = head;
		for (int i = 1; i < n; i++) {
			node = (ListNode*)malloc(sizeof(ListNode));
			//scanf("%d", &node->val);
			node->val = i;
			end->next = node;
			end = node;
		}
		end->next = NULL;//结束创建
		return head;
	}
	ListNode *creatNoHead2(int n) {
		if (n == 0)
			return nullptr;
		ListNode *head, *node, *end;//定义头指针，普通节点，尾部节点；
		head = (ListNode*)malloc(sizeof(ListNode));//分配地址
		head->val = 0;
		end = head;
		for (int i = 1; i < n; i++) {
			node = (ListNode*)malloc(sizeof(ListNode));
			//scanf("%d", &node->val);
			node->val = i * 2;
			end->next = node;
			end = node;
		}
		end->next = NULL;//结束创建
		return head;
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* p;
		if (list1 == nullptr)
			return list2;
		if (list2 == nullptr)
			return list1;
		if (list1->val < list2->val)
		{
			p = list1;
			list1 = list1->next;
		}
		else
		{
			p = list2;
			list2 = list2->next;
		}
		ListNode* head = p;

		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				p->next = list1;
				p = p->next;
				list1 = list1->next;
			}
			else {
				p->next = list2;
				p = p->next;
				list2 = list2->next;
			}
		}
		if (list1 != nullptr)
			p->next = list1;
		if (list2 != nullptr)
			p->next = list2;
		return head;
	}
};

//
class S22 {
public:
	//穷举几乎所有排列组合，然后选出符合条件的
	void perm(string str, int low, int high,vector<string> &vect) {
		if (low == high) {   //当low==high时,此时为一个序列
			int sum = 0;
			for (size_t i = 0; i < str.size(); i++)
			{
				if (str[i] == '(')
					sum += -1;
				else
					sum += 1;
				if (sum > 0)
					break;
			}
			if (sum == 0)
				vect.push_back(str);
		}
		else {
			str.replace(low, 1, "(");
			perm(str, low + 1, high,vect); 
			str.replace(low, 1, ")");
			for (int i = 0,sum = 0; i < low+1; i++)
			{
				if (str[i] == '(')
					sum += -1;
				else
					sum += 1;
				if (sum > 0)
					break;
			}
			perm(str, low + 1, high,vect);
		}
	}
	vector<string> generateParenthesis(int n) {
		string str(n * 2, '(');
		vector<string> vec;
		perm(str, 1, n * 2,vec);
		return vec;
	}
};


class S23 {		//合并k个有序链表
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* p;
		if (list1 == nullptr)
			return list2;
		if (list2 == nullptr)
			return list1;
		if (list1->val < list2->val)
		{
			p = list1;
			list1 = list1->next;
		}
		else
		{
			p = list2;
			list2 = list2->next;
		}
		ListNode* head = p;

		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				p->next = list1;
				p = p->next;
				list1 = list1->next;
			}
			else {
				p->next = list2;
				p = p->next;
				list2 = list2->next;
			}
		}
		if (list1 != nullptr)
			p->next = list1;
		if (list2 != nullptr)
			p->next = list2;
		return head;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		if (lists.size() == 1)
			return lists.at(0);
		ListNode* head = lists.at(0);
		for (size_t i = 1; i < lists.size(); i++) {
			head = mergeTwoLists(head,lists[i]);
		}
		return head;
	}
};

class S24 {		//交换链表中相邻的两个节点
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr)
			return head;
		ListNode* temp = nullptr, *p = head;
		bool flag = true;
		if (p->next != nullptr)
			head = head->next;
		while (p->next != nullptr) {
			if(temp)
				temp->next = p->next;
			temp = p->next;
			p->next = p->next->next;
			temp->next = p;
			
			temp = p;//记录前一个位置
			p = p->next;
			if (p == nullptr)
				break;
		}
		return head;
	}
};

class S25 {
public:
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* p = head;
		while (prev != tail) {
			ListNode* nex = p->next;
			p->next = prev;
			prev = p;
			p = nex;
			//第一轮循环后：p指向头，head是尾，prev是尾
			//第二轮循环后：p指向头，prev是倒数第二个
		}
		return { tail, head };
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* hair = new ListNode(0);
		hair->next = head;
		ListNode* pre = hair;

		while (head) {
			ListNode* tail = pre;
			// 查看剩余部分长度是否大于等于 k
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (!tail) {
					return hair->next;
				}
			}
			ListNode* nex = tail->next;
			// 这里是 C++17 的写法，也可以写成
			// pair<ListNode*, ListNode*> result = myReverse(head, tail);
			// head = result.first;
			// tail = result.second;
			tie(head, tail) = myReverse(head, tail);
			// 把子链表重新接回原链表
			pre->next = head;
			tail->next = nex;
			pre = tail;
			head = tail->next;
		}
		return hair->next;
	}

	pair<ListNode*, ListNode*> myReverse1(ListNode* head, ListNode* tail) {
		ListNode* t = tail->next;
		ListNode* h = head;
		while (t != tail) {
			ListNode* p = h->next;
			h->next = t;
			tail->next = h;
			t = h;
			h = p;
		}
		return {tail,head};
	}
};


class S26 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		auto it = nums.begin();
		int temp = *it;
		it++;
		while (it != nums.end()) {
			if (*it == temp) {
				it = nums.erase(it);
				continue;
			}
			temp = *it;
			it++;
		}
		return nums.size();
	}
	//官方解法，不需要真的删除
	//int removeDuplicates(vector<int>& nums) {
	//	int n = nums.size();
	//	if (n == 0) {
	//		return 0;
	//	}
	//	int fast = 1, slow = 1;
	//	while (fast < n) {
	//		if (nums[fast] != nums[fast - 1]) {
	//			nums[slow] = nums[fast];
	//			++slow;
	//		}
	//		++fast;
	//	}
	//	return slow;
	//}
};

class S27 {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int fast = 0, slow = 0;
		while (fast < n)
		{
			if (nums[fast] != val)
			{
				nums[slow] = nums[fast];
				slow++;
			}
			fast++;
		}
		return slow;
	}
	//方法2
	int removeElement1(vector<int>& nums, int val) {
		int left = 0, right = nums.size();
		while (left < right) {
			if (nums[left] == val) {
				nums[left] = nums[right - 1];
				right--;
			}
			else {
				left++;
			}
		}
		return left;
	}
};

class S28 {
public:
	int strStr(string haystack, string needle) {
		int sLen = haystack.size();
		int pLen = needle.size();

		int i = 0;
		int j = 0;
		while (i < sLen && j < pLen)
		{
			if (haystack[i] == needle[j])
			{
				//①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++    
				i++;
				j++;
			}
			else
			{
				//②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0    
				i = i - j + 1;
				j = 0;
			}
		}
		//匹配成功，返回模式串p在文本串s中的位置，否则返回-1
		if (j == pLen)
			return i - j;
		else
			return -1;
	}
};

class S29 {
public:
	int divide(int dividend, int divisor) {

	}
	//class Solution {
	//public:
	//	int divide(int dividend, int divisor) {
	//		// 考虑被除数为最小值的情况
	//		if (dividend == INT_MIN) {
	//			if (divisor == 1) {
	//				return INT_MIN;
	//			}
	//			if (divisor == -1) {
	//				return INT_MAX;
	//			}
	//		}
	//		// 考虑除数为最小值的情况
	//		if (divisor == INT_MIN) {
	//			return dividend == INT_MIN ? 1 : 0;
	//		}
	//		// 考虑被除数为 0 的情况
	//		if (dividend == 0) {
	//			return 0;
	//		}

	//		// 一般情况，使用二分查找
	//		// 将所有的正数取相反数，这样就只需要考虑一种情况
	//		bool rev = false;
	//		if (dividend > 0) {
	//			dividend = -dividend;
	//			rev = !rev;
	//		}
	//		if (divisor > 0) {
	//			divisor = -divisor;
	//			rev = !rev;
	//		}

	//		// 快速乘
	//		auto quickAdd = [](int y, int z, int x) {
	//			// x 和 y 是负数，z 是正数
	//			// 需要判断 z * y >= x 是否成立
	//			int result = 0, add = y;
	//			while (z) {
	//				if (z & 1) {
	//					// 需要保证 result + add >= x
	//					if (result < x - add) {
	//						return false;
	//					}
	//					result += add;
	//				}
	//				if (z != 1) {
	//					// 需要保证 add + add >= x
	//					if (add < x - add) {
	//						return false;
	//					}
	//					add += add;
	//				}
	//				// 不能使用除法
	//				z >>= 1;
	//			}
	//			return true;
	//		};

	//		int left = 1, right = INT_MAX, ans = 0;
	//		while (left <= right) {
	//			// 注意溢出，并且不能使用除法
	//			int mid = left + ((right - left) >> 1);
	//			bool check = quickAdd(divisor, mid, dividend);
	//			if (check) {
	//				ans = mid;
	//				// 注意溢出
	//				if (mid == INT_MAX) {
	//					break;
	//				}
	//				left = mid + 1;
	//			}
	//			else {
	//				right = mid - 1;
	//			}
	//		}

	//		return rev ? -ans : ans;
	//	}
	//};

};

//未完成
class S30 {
public:
	vector<string> sortStr(vector<string>& words) {
		for(int j = 0; j < words.size(); j++)
			for (int i = 1; i < words.size()-j; i++) {
				int x = words[i - 1].compare(words[i]);
				if (words[i - 1].compare(words[i]) > 0) {
					string temp = words[i];
					words[i] = words[i - 1];
					words[i - 1] = temp;
				}
			}
		return words;
	}
	vector<int> findSubstring(string s, vector<string>& words) {
		words = sortStr(words);
		vector<int> ret;	
		string str;
		for (int i = 0; i < words.size(); i++)
			str += words[i];
		unordered_set<string> setStr;
		setStr.insert(str);
		while (next_permutation(words.begin(), words.end()))
		{
			string str;
			for (int i = 0; i < words.size(); i++)
				str += words[i];
			setStr.insert(str);
		}
		for (int i = 0; i < s.size() - words[0].size(); i++) {
			string str = s.substr(i, words[0].size());

		}
		return ret;
	}
	int strStr(string haystack, string needle) {
		int sLen = haystack.size();
		int pLen = needle.size();
		int i = 0;
		int j = 0;
		while (i < sLen && j < pLen)
		{
			if (haystack[i] == needle[j]){  
				i++;
				j++;
			}
			else{ 
				i = i - j + 1;
				j = 0;
			}
		}
		if (j == pLen)
			return i - j;
		else
			return -1;
	}
};

class S31 {
public:
	void nextPermutation(vector<int>& nums) {
		//调用泛型算法
// 		if(!next_permutation(nums.begin(), nums.end()))
// 			sort(nums.begin(), nums.end());
// 		return;
		//字典排列：
		//一找：从后往前找nums[i-1]<nums[i]
		//二找：从i开始到最后，找大于nums[i-1]的最小值num[min]
		//三交换：交换nums[i]，nums[min]
		//四翻转：从i开始到最后翻转
		for (int i = nums.size() - 1; i > 0; i--) {
			if (nums[i - 1] < nums[i]) {	//1
				int min = i;
				for (int j = i; j < nums.size(); j++) {
					if (nums[j] > nums[i - 1]&&nums[j] <= nums[min]) {
						min = j;	//2
					}
				}
				int t = nums[i - 1];	//3
				nums[i - 1] = nums[min];
				nums[min] = t;
				//sort(nums.begin() + i, nums.end(), greater<int>());
				//4
				for (int start = i, end = nums.size() - 1; start < end; start++, end--) {
					int x = nums[start];
					nums[start] = nums[end];
					nums[end] = x;
				}
				return;
			}				
		}
		sort(nums.begin(), nums.end());	
	}

	//题解
// 	void nextPermutation(vector<int>& nums) {
// 		int i = nums.size() - 2;
// 		while (i >= 0 && nums[i] >= nums[i + 1]) {
// 			i--;
// 		}
// 		if (i >= 0) {
// 			int j = nums.size() - 1;
// 			while (j >= 0 && nums[i] >= nums[j]) {
// 				j--;
// 			}
// 			swap(nums[i], nums[j]);
// 		}
// 		reverse(nums.begin() + i + 1, nums.end());
// 	}
};

int main()
{
	S31 S;
	vector<int> a = { 2,3,1,3,3 };
	S.nextPermutation(a);
	return 0;
}


