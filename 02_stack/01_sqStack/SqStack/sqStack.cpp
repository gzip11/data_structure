#include <iostream>
#define MAXSIZE 10

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top;
}SqStack;

//��ʼ��ջ
bool InitStack(SqStack& S) {
    S.top = -1;
    return true;
}

//�ж�ջ�����
bool IsStackEmpty(SqStack& S) {
    if (S.top == -1)
    {
        return true;
    }
    else {
        return false;
    }

}

//��ջ����
bool Push(SqStack& S, ElemType x) {
    if (S.top == MAXSIZE - 1)
    {
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    return true;
}

//��ջ����
bool Pop(SqStack& S, ElemType& x) {
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    S.top--;
}

//��ȡջ��Ԫ��
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
        std::cout << "��ʼ���ɹ���" << std::endl;
    }
    else {
        std::cout << "��ʼ��ʧ�ܣ�" << std::endl;
    }

    int x = 0;
    for (int i = 0; i < 10; i++) {
        std::cin >> x;
        int status = Push(S, x);
        if (status)
        {
            std::cout << "��ջ�ɹ���" << std::endl;
        }
        else {
            std::cout << "��ջʧ�ܣ�" << std::endl;
        }
    }

    for (int i = 0; i < 6; i++) {
        int e = 0;
        Pop(S, e);
        std::cout << "��ջԪ��Ϊ��" << e << std::endl;
    }

    int e = 0;
    GetTop(S, e);
    std::cout << "ջ��Ԫ��Ϊ��" << e << std::endl;

    system("pause");
    return 0;
}