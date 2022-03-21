// myLcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
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
		for (int i = 0; i < s.size(); i++) {
			if(i + 1 < s.size() && m.at(s[i]) < m.at(s[i + 1]))
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
		for (int i = 1; i < strs.size(); ++i) {
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
		
		for (int i = 0; i < digits.size(); i++) {
			int num = digits[i] - '2';
			if (i == 0) {
				for (int j = 0; j < numLetter[num].size(); j++) {
					string s;
					s += numLetter[num][j];//等价与string s(1,numLetter[num][j]);
					ret.push_back(s);
				}
			}		
			else
			{
				for (int j = 0, k = 0; j < ret.size(); j++,k++) {
					string s;
					int h = ret.size() / numLetter[num].size();
					s += numLetter[num][k / h];
					ret[j] += s;
				}
			}
			if (i + 1 < digits.size())
			{
				int size = ret.size();
				int num1 = digits[i + 1] - '2';
				for(int k = 0; k < numLetter[num1].size()-1;k++)
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

public:
	//这是力扣上不带头指针的删去节点
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


int main()
{
	S19 s;
	ListNode* shead = s.creat(2);
	s.removeNthFromEnd(shead,2);
	return 0;
}


