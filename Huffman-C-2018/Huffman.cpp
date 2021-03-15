#include "stdafx.h"

#pragma warning(disable : 4996)

void Select(HuffmanTree HT, int n, int &s1, int &s2) {
	int m1, m2;
	m1 = m2 = 10000;
	for (int i = 1; i <= n; i++) {
		if (m1 >= HT[i].weight&&HT[i].parent == 0) {
			s1 = i;
			m1 = HT[i].weight;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (m2 >= HT[i].weight&&HT[i].parent == 0 && s1 != i) {
			s2 = i;
			m2 = HT[i].weight;
		}
	}
}
//初始化Huffman
void Initialization(HuffmanTree &HT, int *w, char *name, int n) {
	if (n <= 1)
		return;
	int i, m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	HTNode *p = HT;
	for (p++, i = 1; i <= n; ++i, p++, ++w, name++) {
		p->weight = *w;
		p->parent = 0;
		p->lchild = p->rchild = 0;
		p->name = *name;
	}
	for (; i <= m; i++, p++) {
		p->weight = 0;
		p->parent = 0;
		p->lchild = p->rchild = 0;
		p->name = '*';
	}
	int s1, s2;
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//编码
void Encoding(HuffmanTree HT, HuffmanCode &HC, int n) {
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	char *cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	int start, f, c, i;
	for (i = 1; i <= n; i++) {
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}
//译码
void Decoding(HuffmanTree HT, char* name, int n ,char &value) {
	int m = 2 * n - 1;
	while (HT[m].lchild != 0 && HT[m].rchild != 0) {
		if (*name == '0')
			m = HT[m].lchild;
		else
			m = HT[m].rchild;
		name++;
	}
	value = HT[m].name;
}

//递归打印直观树
void BuildBuf(HuffmanTree HT, int rx, int ry, int rc, char buf[][100],int m) {
	int l = rx-rc;
	int r = rc + rx;
	if (HT[m].name == NULL||m==0)
		return;
	else {
		buf[ry][rx] = HT[m].name;
		if (HT[m].lchild != 0) {
			buf[ry + 1][rx - 1] = '/';
			if (HT[HT[m].lchild].name == NULL)
				buf[ry + 2][rx - 2] = HT[HT[m].lchild].name;
		}
		if (HT[m].rchild != 0) {
			buf[ry + 1][rx + 1] = '\\';
			if (HT[HT[m].rchild].name == NULL)
				buf[ry + 2][rx + 2] = HT[HT[m].rchild].name;
		}
		if (rc >= 6)
			rc = rc >> 1;
		else if (rc >= 2)
			rc--;
		else
			rc = 2;
		BuildBuf(HT, l - 1, ry + 2, rc, buf,HT[m].lchild);
		BuildBuf(HT, r + 2, ry + 2, rc, buf,HT[m].rchild);
	}
}

//打印Huffman树
void PrintTree(HuffmanTree HT,int n) {
	char buf[30][100];
	int m = 2 * n - 1;
	memset(buf, ' ', sizeof(buf));
	BuildBuf(HT, 50, 0, 14, buf, m);
	int line = 0;
	for (int i = 0; i<100; i++) {
		int j = 99;
		while (buf[i][j] == ' ' && j >= 0)
			j--;
		buf[i][j + 1] = '\0';
		if (j <= -1) break;
		line++;
	}
	for (int i = 0; i<=line; i++) {
		cout << buf[i] << endl;
	}
}
