#include <iostream>

#define INITIALSIZE 10

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
}SqList;

//初始化一个顺序表
bool InitList(SqList &L);
//清空顺序表
void ClearList(SqList &L);
//判断顺序表是否为空
bool IsEmptyList(SqList &L);
//求线性表长度
int GetLength(SqList &L);
//获取指定位置元素
void GetElemByIndex(SqList &L,ElemType i);
//按值查找
int GetIndexByElem(SqList &L,ElemType e);
//在指定位置插入元素
bool InsertElem(SqList &L,ElemType i,ElemType e);
//在指定位置删除元素
bool DeleteElem(SqList &L,ElemType i);
//输出线性表
void PrintList(SqList &L);
//开始菜单
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
        std::cout << "初始化失败！" << std::endl;
        return false;
    }
    L.length = 0;
    return true;
}

void ClearList(SqList &L){
    if (L.length == 0){
        std::cout << "顺序表已经为空！" << std::endl;
    }else{
        L.length = 0;
        std::cout << "顺序表已清空！" << std::endl;
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
    //判断i的值是否合法
    if (i <= 0 || i > L.length)
        std::cout << "输入的位置不合法!" << std::endl;
    else
        std::cout << "位置" << i << "的元素为：" << L.data[i-1] << std::endl;
}

int GetIndexByElem(SqList &L,ElemType e){
    for (int i = 0;i < L.length;i++){
        if (L.data[i] == e){
            std::cout << e << "为第" << i + 1 << "个元素" << std::endl;
            return i+1;
        }
    }
    return 0;
}

bool InsertElem(SqList &L,ElemType i,ElemType e){
    if (L.length >= INITIALSIZE){
        std::cout << "线性表已满！" << std::endl;
        return false;
    }else if (i < 1 && i > L.length+1){
        std::cout << "插入的位置不合法！" << std::endl;
        return false;
    }
    for(int j = L.length;j >= i;i--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1]=e;
    ++L.length;
    std::cout << "添加成功！" << std::endl;
    return true;
}

bool DeleteElem(SqList &L,ElemType i){
    if (i > 0 && i < L.length && L.length != 0){
        for(int j = i;j < L.length;j++){
            L.data[j-1] = L.data[j];
        }
        --L.length;
    }else{
        std::cout << "删除位置不合法!" << std::endl;
    }
}

void PrintList(SqList &L){
    for (int i = 0;i < L.length;i++)
        std::cout << L.data[i] << " ";
    std::cout << std::endl;
}

void welcome(){
    std::cout << "1.初始化顺序表" << std::endl;
    std::cout << "2.清空顺序表" << std::endl;
    std::cout << "3.判断顺序表是否为空" << std::endl;
    std::cout << "4.求顺序表表长" << std::endl;
    std::cout << "5.获取指定位置元素" << std::endl;
    std::cout << "6.按值查找" << std::endl;
    std::cout << "7.在指定位置插入元素" << std::endl;
    std::cout << "8.在指定位置删除元素" << std::endl;
    std::cout << "9.打印输出顺序表" << std::endl;
    std::cout << "0.退出" << std::endl;
}