#include <iostream>

#define INITIALSIZE 10

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
}SqList;

//��ʼ��һ��˳���
bool InitList(SqList &L);
//���˳���
void ClearList(SqList &L);
//�ж�˳����Ƿ�Ϊ��
bool IsEmptyList(SqList &L);
//�����Ա���
int GetLength(SqList &L);
//��ȡָ��λ��Ԫ��
void GetElemByIndex(SqList &L,ElemType i);
//��ֵ����
int GetIndexByElem(SqList &L,ElemType e);
//��ָ��λ�ò���Ԫ��
bool InsertElem(SqList &L,ElemType i,ElemType e);
//��ָ��λ��ɾ��Ԫ��
bool DeleteElem(SqList &L,ElemType i);
//������Ա�
void PrintList(SqList &L);
//��ʼ�˵�
void welcome();


int main() {
    SqList L;
    InitList(L);
    IsEmptyList(L);
    InsertElem(L,1,1);
    InsertElem(L,2,2);
    InsertElem(L,3,3);
    GetLength(L);
    GetElemByIndex(L,1);
    GetIndexByElem(L,3);
    PrintList(L);
    DeleteElem(L,2);
    PrintList(L);
    return 0;
}

bool InitList(SqList &L){
    L.data = new ElemType[INITIALSIZE];
    if (!L.data){
        std::cout << "��ʼ��ʧ�ܣ�" << std::endl;
        return false;
    }
    L.length = 0;
    return true;
}

void ClearList(SqList &L){
    if (L.length == 0){
        std::cout << "˳����Ѿ�Ϊ�գ�" << std::endl;
    }else{
        L.length = 0;
        std::cout << "˳�������գ�" << std::endl;
    }
}

bool IsEmptyList(SqList &L){
    if (L.length == 0)
        return true;
    else
        return false;
}

int GetLength(SqList &L){
    return L.length;
}

void GetElemByIndex(SqList &L,ElemType i){
    //�ж�i��ֵ�Ƿ�Ϸ�
    if (i <= 0 || i > L.length)
        std::cout << "�����λ�ò��Ϸ�!" << std::endl;
    else
        std::cout << "λ��" << i << "��Ԫ��Ϊ��" << L.data[i-1] << std::endl;
}

int GetIndexByElem(SqList &L,ElemType e){
    for (int i = 0;i < L.length;i++){
        if (L.data[i] == e){
            std::cout << e << "Ϊ��" << i + 1 << "��Ԫ��" << std::endl;
            return i+1;
        }
    }
    return 0;
}

bool InsertElem(SqList &L,ElemType i,ElemType e){
    if (L.length >= INITIALSIZE){
        std::cout << "���Ա�������" << std::endl;
        return false;
    }else if (i < 1 && i > L.length+1){
        std::cout << "�����λ�ò��Ϸ���" << std::endl;
        return false;
    }
    for(int j = L.length;j >= i;i--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1]=e;
    ++L.length;
    std::cout << "��ӳɹ���" << std::endl;
    return true;
}

bool DeleteElem(SqList &L,ElemType i){
    if (i > 0 && i < L.length && L.length != 0){
        for(int j = i;j < L.length;j++){
            L.data[j-1] = L.data[j];
        }
        --L.length;
    }else{
        std::cout << "ɾ��λ�ò��Ϸ�!" << std::endl;
    }
}

void PrintList(SqList &L){
    for (int i = 0;i < L.length;i++)
        std::cout << L.data[i] << " ";
    std::cout << std::endl;
}

void welcome(){
    std::cout << "1.��ʼ��˳���" << std::endl;
    std::cout << "2.���˳���" << std::endl;
    std::cout << "3.�ж�˳����Ƿ�Ϊ��" << std::endl;
    std::cout << "4.��˳����" << std::endl;
    std::cout << "5.��ȡָ��λ��Ԫ��" << std::endl;
    std::cout << "6.��ֵ����" << std::endl;
    std::cout << "7.��ָ��λ�ò���Ԫ��" << std::endl;
    std::cout << "8.��ָ��λ��ɾ��Ԫ��" << std::endl;
    std::cout << "9.��ӡ���˳���" << std::endl;
    std::cout << "0.�˳�" << std::endl;
}