#include <iostream>
#define MAXSIZE 10

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top;
}SqStack;

//初始化栈
bool InitStack(SqStack& S) {
    S.top = -1;
    return true;
}

//判断栈空与否
bool IsStackEmpty(SqStack& S) {
    if (S.top == -1)
    {
        return true;
    }
    else {
        return false;
    }

}

//进栈操作
bool Push(SqStack& S, ElemType x) {
    if (S.top == MAXSIZE - 1)
    {
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    return true;
}

//出栈操作
bool Pop(SqStack& S, ElemType& x) {
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    S.top--;
}

//获取栈顶元素
bool GetTop(SqStack& S, ElemType& x) {
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

int main() {
    SqStack S;
    if (InitStack(S))
    {
        std::cout << "初始化成功！" << std::endl;
    }
    else {
        std::cout << "初始化失败！" << std::endl;
    }

    int x = 0;
    for (int i = 0; i < 10; i++) {
        std::cin >> x;
        int status = Push(S, x);
        if (status)
        {
            std::cout << "进栈成功！" << std::endl;
        }
        else {
            std::cout << "进栈失败！" << std::endl;
        }
    }

    for (int i = 0; i < 6; i++) {
        int e = 0;
        Pop(S, e);
        std::cout << "出栈元素为：" << e << std::endl;
    }

    int e = 0;
    GetTop(S, e);
    std::cout << "栈顶元素为：" << e << std::endl;

    system("pause");
    return 0;
}