#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int value;
struct Node
{
	value data;
	Node *left;
	Node *right;
};

struct BTree
{
	Node *root;
};

void initBTree(BTree &t)
{
	t.root = NULL;
}

Node *createTNode(value data)
{
	Node *p = new Node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int isEmpty(BTree t)
{
	if(t.root = NULL)
		return 1;
	return 0;
}

int insertTNode(Node* &root, value data)
{
	// TH1: Cay rong
	if(root == NULL)
	{
		root = createTNode(data);
		return 0;
	}
	// TH2: Cay bi trung gia tri nut
	if(root->data == data)
		return 0;
	//TH3: Cay co ton tai nut
	if(data > root->data) // Neu phan tu them lon hon nut goc => qua phai
		return insertTNode(root->right, data);
	else // Neu phan tu them nho hon nut goc => qua trai
		return insertTNode(root->left, data);
	return 1; 
}

void traverseNLR(Node *root)
{
	if(root == NULL) return;
	printf("%d ", root->data);
	traverseNLR(root->left);
	traverseNLR(root->right);
}
void traverseNRL(Node *root)
{
	if(root == NULL) return;
	printf("%d ", root->data);
	traverseNRL(root->right);
	traverseNRL(root->left);
}
void traverseLRN(Node *root)
{
	if(root == NULL) return;
	traverseLRN(root->left);
	traverseLRN(root->right);
	printf("%d ", root->data);
}
void traverseRNL(Node *root)
{
	if(root == NULL) return;
	traverseRNL(root->right);
	printf("%d ", root->data);
	traverseRNL(root->left);
}
void traverseLNR(Node *root)
{
	if(root == NULL) return;
	traverseLNR(root->left);
	printf("%d ", root->data);
	traverseLNR(root->right);
}
void traverseRLN(Node *root)
{
	if(root == NULL) return;
	traverseRLN(root->right);
	traverseRLN(root->left);
	printf("%d ", root->data);
}
void print_Traverse(BTree t)
{
	printf("Duyet NLR: "); traverseNLR(t.root); printf("\n");
	printf("Duyet NRL: "); traverseNRL(t.root); printf("\n");
	printf("Duyet LNR: "); traverseLNR(t.root); printf("\n");
	printf("Duyet LRN: "); traverseLRN(t.root); printf("\n");
	printf("Duyet RNL: "); traverseRNL(t.root); printf("\n");
	printf("Duyet RLN: "); traverseRLN(t.root); printf("\n");
}

int Ktra_SNT(value data)
{
	if(data < 2)
		return 0;
	else
	{
		if(data == 2)
			return 1;
		else
		{
			if(data % 2 == 0)
				return 0;
			else
			{
				for(int i = 2; i < data; i++)
				{
					if(data % i == 0)
						return 0;
				} 
			}
		}
	}
	return 1;
}

void soLuong_SNT(Node *root, int &dem)
{
	if(root == NULL) return;
	else
	{
		if(Ktra_SNT(root->data) == 1)
			dem++;
		soLuong_SNT(root->left, dem);
		soLuong_SNT(root->right, dem);
	}
}

Node *TimKiem(Node *root, value data)
{
	if(root == NULL)
		return NULL;
	else
	{
		if(root->data < data)
			return TimKiem(root->right, data);
		else if(root->data > data)
			return TimKiem(root->left, data);
		else
			return root;
	}
}

void Node_2_con(Node *root)
{
	if(root == NULL) return;
	else
	{
		if(root->left != NULL && root->right != NULL)
		{
			printf("%d ", root->data);
		}
		Node_2_con(root->left);
		Node_2_con(root->right);
	}
}
void Node_1_con(Node *root)
{
	if(root == NULL) return;
	else
	{
		if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
		{
			printf("%d ", root->data);
		}
		Node_1_con(root->left);
		Node_1_con(root->right);
	}
}
void Node_la(Node *root)
{
	if(root == NULL) return;
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			printf("%d ", root->data);
		}
		Node_la(root->left);
		Node_la(root->right);
	}
}

//CACH 1: Khai bao bien 'max' la bien cuc bo
// int max = INT_MIN; (su dung thu vien limits.h)
// void tim_Max(Node *root)
// {
// 	if (root == NULL) return;
// 	else
// 	{
// 		if(root->data > max)
// 		{
// 			max = root->data;
// 		}
// 		tim_Max(root->left);
// 		tim_Max(root->right);
// 	}
// }

//CACH 2: Toi uu hoa
int tim_Max(Node *root)
{
	if(root->right == NULL) //Neu cay rong thi tra ve node goc
		return root->data;
	return tim_Max(root->right); // Neu cay co ton tai phan tu thi duyet den node ngoai cung nhat cua cay con phai roi tra ve gia tri MAX
}
int tim_Min(Node *root)
{
	if(root->left == NULL)
		return root->data;
	return tim_Min(root->left); // Neu cay co ton tai phan tu thi duyet den node ngoai cung nhat cua cay con trai roi tra ve gia tri MIN
}

// Node *timNodeTheMang(Node *&p)
// {// Ham tim node q the mang cho node p, f la node cha cua node q
// 	Node *f = p;
// 	Node *q = p->right;
// 	while(q->left != NULL)
// 	{
// 		f = q; // Lua cha cua q
// 		q = q->left; // q qua ben trai
// 	}
// 	p->data = q->data; // tim duoc node the mang cho p la q
// 	if(f == p) // neu cha cua q la p
// 		f->right = q->right;
// 	else
// 		f->left = q->right;
// 	return q; // tra ve con tro q the mang cho p
// }
// void XoaNode(Node *&root, value data)
// {
// 	if(root == NULL) 
// 		return;
// 	if(root->data > data)
// 		XoaNode(root->left, data);
// 	else if(root->data < data)
// 		XoaNode(root->right, data);
// 	else
// 	{
// 		Node *p = root;
// 		if(root->left == NULL)
// 		{
// 			root = root->right;
// 			delete p;
// 		}
// 		else if(root->right == NULL)
// 		{
// 			root = root->left;
// 			delete p;
// 		}
// 		else
// 		{
// 			Node *q = timNodeTheMang(p);
// 			delete q;
// 		}
// 	}
// }

void XoaNode(Node *&root, value data)
{
	// Ney cay rong => Ket thuc ham
	if(root == NULL) return;
	else
	{
		if(root->data < data) // Neu node them vao lon hon => Duyet qua ben phai
			XoaNode(root->right, data);
		else if(root->data > data) // Neu node them vao nho hon => Duyet qua ben trai
			XoaNode(root->left, data);
		else
		{
			Node *X = root; // Node X la node the mang 
			if(root->left == NULL) // Cay khong co nhanh trai => Duyet sang ben phai
				root = root->right;
			else if(root->right == NULL) // Cay khong co nhanh phai => Duyet sang ben trai
				root = root->left;
			delete X; // Xoa node X la node can xoa
		}
	}
}

void input(BTree &t)
{
	int n;
	printf("Nhap so luong node muon them: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		value x;
		printf("Node thu %d: ", i+1);
		scanf("%d", &x);
		insertTNode(t.root, x);
	}
}

void menu()
{
	printf("===================================== MENU =====================================\n");
	printf("| 1. Nhap du lieu                                                              |\n");
	printf("| 2. Xuat du lieu theo 6 cach (NLR, NRL, LNR, RNL, LRN, RLN)                   |\n");
	printf("| 3. Dem so luong so nguyen to                                                 |\n");
	printf("| 4. Tim kiem node trong cay                                                   |\n");
	printf("| 5. Xuat node co 2 con                                                        |\n");
	printf("| 6. Xuat node co 1 con                                                        |\n");
	printf("| 7. Xuat node la                                                              |\n");
	printf("| 8. Tim node co gia tri MAX                                                   |\n");
	printf("| 9. Tim node co gia tri MIN                                                   |\n");
	printf("| 10. Xoa node                                                                 |\n");
	printf("| 0. Thoat chuong trinh                                                        |\n");
	printf("================================================================================\n");
}

void clearScreen()
{
	printf("\n");
	system("pause");
	system("cls");
}

int main()
{
	BTree t;
	initBTree(t);

	int chon;
	do
	{
		menu();
		printf("Nhap lua chon: ");
		scanf("%d", &chon);
		switch(chon)
		{
			case 1:
			{
				input(t);
				clearScreen();
				break;
			}
			case 2:
			{
				print_Traverse(t);
				clearScreen();
				break;
			}
			case 3:
			{
				int dem = 0;
				soLuong_SNT(t.root, dem);
				printf("So luong so nguyen to trong cay: %d", dem);
				clearScreen();
				break;
			}
			case 4:
			{
				value x;
				printf("Nhap nut tim kiem: ");
				scanf("%d", &x);
				Node *p = TimKiem(t.root, x);
				if(p == NULL)
					printf("\nNode so %d khong ton tai trong cay", x);
				else
					printf("\nNode so %d ton tai trong cay", x);	
				clearScreen();
				break;
			}
			case 5:
			{
				printf("\nNode co 2 con: ");
				Node_2_con(t.root);
				clearScreen();
				break;
			}
			case 6:
			{
				printf("\nNode co 1 con: ");
				Node_1_con(t.root);
				clearScreen();
				break;
			}
			case 7:
			{
				printf("\nNode la: ");
				Node_la(t.root);
				clearScreen();
				break;
			}
			case 8:
			{
				// CACH 1:
				// tim_Max(t.root);
				// printf("Node co gia tri MAX: %d", max);

				// CACH 2:
				printf("Node co gia tri MAX: %d", tim_Max(t.root));
				clearScreen();
				break;
			}
			case 9:
			{
				printf("Node co gia tri MIN: %d", tim_Min(t.root));
				clearScreen();
				break;
			}
			case 10:
			{
				value x;
				printf("Nhap vao node can xoa: ");
				scanf("%d", &x);
				XoaNode(t.root, x);
				clearScreen();
				break;
			}
			case 0:
			{
				clearScreen();
				break;
			}
			default:
			{
				printf("Lua chon khong hop le. Vui long thu lai");
				clearScreen();
				break;
			}
		}
	} while(chon != 0);
	
	return 0;
}