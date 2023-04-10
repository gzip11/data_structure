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
void InsertElem(SqList &L,ElemType i,ElemType &e);
//在指定位置删除元素
bool DeleteElem(SqList &L,ElemType i);
//输出线性表
void PrintList(SqList &L);
//开始菜单
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
                    std::cout << "初始化成功" << std::endl;
                break;
            case 2:
                ClearList(L);
                break;
            case 3:
                if (IsEmptyList(L)){
                    std::cout << "线性表为空！" << std::endl;
                }else{
                    std::cout << "线性表不为空" << std::endl;
                }
                break;
            case 4:
                std::cout << "线性表长度为：" << GetLength(L) << std::endl;
                break;
            case 5:
                std::cout << "请输入一个0到9的数字" << std::endl;
                std::cin >> e;
                GetElemByIndex(L,e);
                break;
            case 6:
                std::cout << "请输入查找值" << std::endl;
                std::cin >> e;
                GetIndexByElem(L,e);
                break;
            case 7:
                std::cout << "请输入要插入的元素的位置和值";
                std::cin >> index >> e;
                InsertElem(L,index,e);
                break;
            case 8:
                std::cout << "请输入要删除元素的位置";
                std::cin >> index;
                DeleteElem(L,index);
                break;
            case 9:
                PrintList(L);
                break;
            default:
                std::cout << "请输入合法的数字！" << std::endl;
                break;
        }
    }

    system("pause");
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
    if (i < 0 || i > L.length)
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

void InsertElem(SqList &L,ElemType i,ElemType &e){
    if (i > 0 && i <= L.length && L.length < INITIALSIZE){
        //在指定位置元素前插入
        for(int j = L.length;j >= i;j++){
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = e;
        ++L.length;//表长增加1
        std::cout << "添加成功!" << std::endl;
    }else{
        std::cout << "插入位置不合法!" << std::endl;
    }
}

bool DeleteElem(SqList &L,ElemType i){
    if (i > 0 && i <= L.length && L.length != 0){
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