//��������� ����������� ������������ ������
#include "stdio.h" //����� ����� � ������� ����������
#include <malloc.h> //����� ����� � ����������� �����������
#include <string.h>

//����������� ���������
typedef struct
{
    char* name; //���������(������������ ������). ����� ��������������, ����� ��������� �������� ������ � ����
    int sex; //�������� ������
    int age; //�������� ������
} Record;

//����������(declaration) ���������� ������� (��������� ������ � ������������������� ����� ����������)
void PrintRecord(Record&); //���������� ����� ����������
void FPrintRecord(FILE*, Record&);
int FScanRecord(FILE*, Record&);

int main () //�������� �������, ������� ���������� ��� ������� ������������ ����� (����� �����)
{//������ ���� �������� �������
    //���������� ���������� c ����� ������, ��������� "Record"
    Record item;

    //��������� ������ ��� ������� ��������, ��������� ������������� ����� ������ ���������� ������� ������
    item.name = (char*)malloc(strlen("John") * sizeof(char)); 
    //����� ������ ������ "John" �������� �� �� ������ ������ ������� � ������
    //�������� ��������� �� ���������� ������ ���� (void*) � �������� ��� � ���������� ���� (char*)
    
    //����������� ������ � ���������� ������� ������
    strcpy(item.name, "John"); //�� �������� � �������, � �������� ���������, ���� "name" ���������� "item"

    //������������� ����� ����������(���������)
    item.sex = 1; //����������� �������� � ��� ����� �������������� ���� "sex" ���������� "item"
    item.age = 33;
    //����������, ����� ��� ���������� ���� ���������� (��� ������ ����������� - ���������� �� ���������� ���, ��� � ���� ������ ��� ������ ���������� ������)

    FILE* pFile; //���������� ����������, ��� �������� ��������� �� ����
    pFile = fopen ("myfile.txt","a"); //��������� ���� � ������ ������ � ����� ������������� �����
    FPrintRecord(pFile, item); //����� ������� ������ � ����
    fclose(pFile); //�������� �����

    pFile = fopen ("myfile.txt","r"); //��������� ���� � ������ ������
    while (FScanRecord(pFile, item) != EOF) //������ �� �����, ���� ��������
    {
        //������� ������ ������ �� �������
        PrintRecord(item);
    }
    fclose(pFile);

    free(item.name);//����������� ���������� � ����(heap) ������

    scanf("%s\n"); //���� �����, ����� ������� �� �����������

    return 0;
}//���������� ���� �������� �������


//�����������(definition) �������, � ������� �� ���������� �������� ��� � ���� ������� {...}
void PrintRecord(Record& item) //�������� - ��� �������� �������� ��������
{
    //������� ������ �� �������
    printf ("%d %d %s\n",item.age, item.sex, item.name);
}

void FPrintRecord(FILE* pFile, Record& item)
{
    //����� ������ � ���� (������������ �������)
    fprintf (pFile, "%d %d %s\n",item.age, item.sex, item.name);
    //����� �� �������� ����������� ���� ��������, ������ ��� ��� �� ���� �������� �� �������.
}

// ������� ���������� ������������� ��� ������
int FScanRecord(FILE* pFile, Record& item)
{
    //������ ������ �� ����� (�������������� �������)
    return fscanf (pFile, "%d %d %s\n", &item.age, &item.sex, item.name);
    //� ����� �� �������� ����������� ��������� �� ����������, ����� �������� �� �������� ������ ������ �������
    //��� name �� ����������� ���������, ������ ��� ���������� ��� ���������
}