#include"stdafx.h"

//一级菜单
void menu1() {
	int m;
	HTNode *HT;
	char **HC;
	int n,k;
	static int flag = 0;
	cout << "            赫夫曼码的编/译码系统                 " << endl;
	while (1) {
		cout << "*******************菜单****************" << endl;
		cout << "|1.建立Huffman树                      |" << endl;
		cout << "|2.退出运行                           |"  << endl;
		cout << "**************请选择操作**************" << endl;
		cin >> m;
		if (m == 1) {
			if (flag == 1) {
				cout << "******请选择操作*********" << endl;
				cout << "1.以当前树继续传输文件 " << endl;
				cout << "2.创建新的Huffman树    " << endl;
				cin >> k;
				if (k == 1) {
					menu2(HT, HC, n);
				}
				else if (k == 2) {
					hfmTree(HT, HC, n);
					menu2(HT, HC, n);
				}
			}
			if (flag == 0) {
				flag++;
				hfmTree(HT, HC, n);
				menu2(HT, HC, n);
			}
		}
		else
			exit(0);
	}
}

//二级菜单
void menu2(HuffmanTree &HT, HuffmanCode &HC,int num) {
	int m,n;
	char k;
	cout << "*******请选择操作*********" << endl;
	cout << "1.从文件读取要传输的正文" << endl;
	cout << "2.从屏幕输入要传输的正文" << endl;
	cout << "3.返回菜单" << endl;
	cout << "****************************" << endl;
	cin >> m;
	if (m == 1) {
		ToBeTran(HT, HC);
	}
	else if (m == 2) {
		EnterText(HT, HC);
	}
	else if (m == 3) {
		system("pause");
		system("cls");
		cout << "            赫夫曼码的编/译码系统                 " << endl;
		return;
	}
	Textfile(HT, num);
	cout << "*************文本结果已成功保存到文件！****************" << endl;
	cout << "*************是否打印代码文件(y-yes/n-no)**************" << endl;
	cin >> k;
	if (k == 'y'||k=='Y') {
		print();
	}
	cout << "*************是否打印Huffman树(y-yes/n-no)**************" << endl;
	cin >> k;
	if (k == 'y' || k == 'Y') {
		PrintTree(HT, num);
	}
	system("pause");
	system("cls");
	cout << "            赫夫曼码的编/译码系统                 " << endl;
	return;
}