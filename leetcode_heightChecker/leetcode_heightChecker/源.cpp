//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	int heightChecker(vector<int>& heights) {
//		int arr[101] = {};
//		for each (int height in heights) {
//			arr[height]++;
//		}
//
//		int count = 0;
//		for (int i = 1, j = 0; i < 101; ++i) {
//			while (arr[i]-- > 0)
//			{
//				if (heights[j++] != i) {
//					count++;
//				}
//			}
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<int> arr = { 1,1,4,2,1,3 };
//	Solution solu;
//	solu.heightChecker(arr);
//	return 0;
//}

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
	//创建 umap 容器
	unordered_map<string, string> umap{
		{ "Python教程","http://c.biancheng.net/python/" },
		{ "Java教程","http://c.biancheng.net/java/" },
		{ "Linux教程","http://c.biancheng.net/linux/" } };

	cout << "umap 存储的键值对包括：" << endl;
	//遍历输出 umap 容器中所有的键值对
	unordered_map<string, string>::iterator iter;
	for (iter = umap.begin(); iter != umap.end(); ++iter) {
		cout << "<" << iter->first << ", " << iter->second << ">" << endl;
	}
	//获取指向指定键值对的前向迭代器
	iter = umap.find("Java教程");
	cout << "umap.find(\"Java教程\") = " << "<" << iter->first << ", " << iter->second << ">" << endl;
	return 0;
}