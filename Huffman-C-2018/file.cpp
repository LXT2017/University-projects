#include"stdafx.h"
#include<fstream>

ifstream inData;
ofstream outData;

//构建新的Huffman树
void hfmTree(HuffmanTree &HT, HuffmanCode &HC, int &n) {
	int i;
	cout << "请输入有多少个字符：";
	cin >> n;
	char name[100];
	int w[100];
	cout << "----------------------请输入n位字符------------------------" << endl;
	getchar();
	gets_s(name);
	while(strlen(name) != n) {
		cout << "输入有误！请重新输入" << endl;
		cout << "----------------------请输入n位字符------------------------" << endl;
		getchar();
		gets_s(name);
		getchar();
	}
	cout << "----------------------请输入n位字符权重------------------------" << endl;
	for (i = 0; i < n; i++) {
		cin >> w[i];
	}
	cin.clear();
	ofstream outData("hfmTree.txt",ios::binary);
	outData<<n;
	outData<< "\n";
	for (i = 0; i < n; i++) {
		outData.put(name[i]);
	}
	outData << "\n";
	for (i = 0; i < n; i++) {
		outData << w[i] << " ";
	}
	outData << "\n";
	outData.close();
	Initialization(HT, w, name, n);
	Encoding(HT, HC, n);
}

//通过文件输入字符并保存编码到文件
void ToBeTran(HuffmanTree &HT,HuffmanCode &HC) {
	inData.open("ToBeTran.txt",ios::binary);
	char key[100];
	int i=1,j,n=1;
	while (inData.get(key[i++])) {
		n++;
	}
	inData.close();
	outData.open("CodeFile.txt",ios::binary);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (key[i] == HT[j].name) {
				outData << HC[j] << "\n";
				break;
			}
		}
	}
	outData.close();
}

//从屏幕输入字符保存编码到文件
void EnterText(HuffmanTree &HT, HuffmanCode &HC) {
	int i,j,len =500;
	char ch;
	char* str = (char*)malloc(sizeof(char*) * (len+1));
	int count = 1;
	cout << "-----------------请输入要输入的文本--------------" << endl;
	getchar();
	do{
		ch = getchar();
		count++;
		if (count >= len)
		{
			str = (char*)realloc(str, sizeof(char*) * (++len));
		}
		str[count - 1] = ch;
	} while (ch != '\n');
	str[count] = '\0';
	outData.open("CodeFile.txt", ios::binary);
	for (i = 1; i <= count; i++) {
		for (j = 1; j <= count; j++) {
			if (str[i] == HT[j].name) {
				outData << HC[j] << "\n";
				break;
			}
		}
	}
	outData.close();
}

//打开编码文件译码并保存结果到文件
void Textfile(HuffmanTree &HT, int &m) {
	inData.open("CodeFile.txt");
	outData.open("Textfile.txt");
	char value;
	HuffmanCode HC;
	int i=1,n=0;
	HC = (HuffmanCode)malloc(255*sizeof(char*));
	while(!inData.eof()){
		if (!(HC[i] = (char*)malloc(sizeof(char)))) {
			cout << "输入错误！" << endl;
			system("pause");
			exit(0);
		}
		inData >> HC[i++];
		n++;
	}
	for (i = 1; i < n; i++) {
		Decoding(HT, HC[i], m ,value);
		outData << value;
	}
	inData.close();
	outData.close();
}

//打印50个代码为一行到屏幕并保存到文件
void print() {
	int i,n=1,count = 0;
	inData.open("CodeFile.txt");
	outData.open("CodePrin.txt");
	char *cd;
	cd = (char*)malloc(sizeof(char) * 50);
	while (!inData.eof()) {
		inData >> cd;
		n = strlen(cd);
		if (count + n > 50) {
			for (i = 0; i < 50 - count; i++) {
				cout << cd[i];
				outData << cd[i];
			}
			outData << '\n';
			cout << endl;
			for (; i < n; i++) {
				cout << cd[i];
				outData << cd[i];
			}
			count = (count+n)%50;
		}
		else {
			cout << cd;
			outData << cd;
			count += n;
		}
	}
	cout << endl;
	inData.close();
	outData.close();
}