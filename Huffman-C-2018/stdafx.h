// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream>
#include <cstring>
using namespace std;

//Huffman树结点
typedef struct {
	int weight;
	int parent, lchild, rchild;
	char name;
}HTNode, *HuffmanTree;
typedef char **HuffmanCode;


//Huffman树编码译码模块
void Select(HuffmanTree HT, int n, int &s1, int &s2);
void Initialization(HuffmanTree &HT, int *w, char *name, int n);
void Encoding(HuffmanTree HT, HuffmanCode &HC, int n);
void Decoding(HuffmanTree HT, char* name, int n , char &value);
void PrintTree(HuffmanTree HT, int n);

//文件操作模块
void hfmTree(HuffmanTree &HT, HuffmanCode &HC, int &n);
void ToBeTran(HuffmanTree &HT, HuffmanCode &HC);
void Textfile(HuffmanTree &HT, int &m);
void BuildBuf(HuffmanTree HT, int rx, int ry, int rc, char buf[][100], int n);
void EnterText(HuffmanTree &HT, HuffmanCode &HC);
void print();

//用户界面模块
void menu1();
void menu2(HuffmanTree &HT, HuffmanCode &HC,int n);

// TODO: 在此处引用程序需要的其他头文件
