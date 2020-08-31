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
	//���� umap ����
	unordered_map<string, string> umap{
		{ "Python�̳�","http://c.biancheng.net/python/" },
		{ "Java�̳�","http://c.biancheng.net/java/" },
		{ "Linux�̳�","http://c.biancheng.net/linux/" } };

	cout << "umap �洢�ļ�ֵ�԰�����" << endl;
	//������� umap ���������еļ�ֵ��
	unordered_map<string, string>::iterator iter;
	for (iter = umap.begin(); iter != umap.end(); ++iter) {
		cout << "<" << iter->first << ", " << iter->second << ">" << endl;
	}
	//��ȡָ��ָ����ֵ�Ե�ǰ�������
	iter = umap.find("Java�̳�");
	cout << "umap.find(\"Java�̳�\") = " << "<" << iter->first << ", " << iter->second << ">" << endl;
	return 0;
}