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
void InsertElem(SqList &L,ElemType i,ElemType &e);
//��ָ��λ��ɾ��Ԫ��
bool DeleteElem(SqList &L,ElemType i);
//������Ա�
void PrintList(SqList &L);
//��ʼ�˵�
void welcome();


int main() {
    SqList L;
    int code = 1;
    while (code!=0){
        int index = 0,e = 0;
        welcome();
        std::cin>>code;
        switch (code) {
            case 1:
                if (InitList(L))
                    std::cout << "��ʼ���ɹ�" << std::endl;
                break;
            case 2:
                ClearList(L);
                break;
            case 3:
                if (IsEmptyList(L)){
                    std::cout << "���Ա�Ϊ�գ�" << std::endl;
                }else{
                    std::cout << "���Ա�Ϊ��" << std::endl;
                }
                break;
            case 4:
                std::cout << "���Ա���Ϊ��" << GetLength(L) << std::endl;
                break;
            case 5:
                std::cout << "������һ��0��9������" << std::endl;
                std::cin >> e;
                GetElemByIndex(L,e);
                break;
            case 6:
                std::cout << "���������ֵ" << std::endl;
                std::cin >> e;
                GetIndexByElem(L,e);
                break;
            case 7:
                std::cout << "������Ҫ�����Ԫ�ص�λ�ú�ֵ";
                std::cin >> index >> e;
                InsertElem(L,index,e);
                break;
            case 8:
                std::cout << "������Ҫɾ��Ԫ�ص�λ��";
                std::cin >> index;
                DeleteElem(L,index);
                break;
            case 9:
                PrintList(L);
                break;
            default:
                std::cout << "������Ϸ������֣�" << std::endl;
                break;
        }
    }

    system("pause");
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
    if (i < 0 || i > L.length)
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

void InsertElem(SqList &L,ElemType i,ElemType &e){
    if (i > 0 && i <= L.length && L.length < INITIALSIZE){
        //��ָ��λ��Ԫ��ǰ����
        for(int j = L.length;j >= i;j++){
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = e;
        ++L.length;//������1
        std::cout << "��ӳɹ�!" << std::endl;
    }else{
        std::cout << "����λ�ò��Ϸ�!" << std::endl;
    }
}

bool DeleteElem(SqList &L,ElemType i){
    if (i > 0 && i <= L.length && L.length != 0){
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