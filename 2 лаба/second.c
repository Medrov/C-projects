/******************************************************************************


                ##   ## ##### ###   ##### ####   ###  #       # 
                # # # # #     #  #  #     #   # #   #  #     #
                #  #  # ##### #   # ##### ####  #   #   #   #
                #     # #     #  #  #     #  #  #   #    # #
                #     # ##### ###   ##### #   #  ###      #


*******************************************************************************/

/*
    ������ ���� - 29 �������
    �������: https://disk.yandex.ru/i/79ayTTUBS-CA4w
*/

#include <stdio.h>
#include <math.h>

//�� ����� For
double byFor(float x, float e){
    //���������� ������� ����� ����� �����
    double resExternal = 0;
    //���������� ������� ����� ����������� �����
    double resInternal = 0;
    //���������� ���������� ��������
    double lastElement = 0;
    //������ ����������� ����
    for(int i = 1; i > 0; i++) {
        //����� ��� ��������� ���������� ���� �����
        double temp = 1;
        //���� �� i �� j
        for(int j = 1; j <= i; j++) {
            // ������ ���������, ������� �������� ��� ���� ;)
            temp *= (powf(-1, j) + j);
            //�������� ���� ����� �������� � �����, �� ���� �������� �������� � ����������
            if(j == i) resInternal += temp;
        }
        //������ �����
        resExternal += (powf(x, i) + resInternal);
        //�������� ��������� �������
        lastElement = powf(x, i) + resInternal;
        // ������ �������� �� ��������
        if(fabs(lastElement) < e) break;
    }
    //���������� ��������
    return resExternal;
}

//�� ����� While
double byWhile(float x, float e){
    //���������� ������� ����� ����� �����
    double resExternal = 0;
    //���������� ������� ����� ����������� �����
    double resInternal = 0;
    //���������� ���������� ��������
    double lastElement = 0;
    //��������� ����������
    int i = 1;
    //������ ����������� ����
    while(i > 0) {
        //����� ��� ��������� ���������� ���� �����
        double temp = 1;
        //���� �� i �� j
        for(int j = 1; j <= i; j++) {
            // ������ ���������, ������� �������� ��� ���� ;)
            temp *= (powf(-1, j) + j);
            //�������� ���� ����� �������� � �����, �� ���� �������� �������� � ����������
            if(j == i) resInternal += temp;
        }
        //������ �����
        resExternal += (powf(x, i) + resInternal);
        //�������� ��������� �������
        lastElement = powf(x, i) + resInternal;
        // ������ �������� �� ��������
        if(fabs(lastElement) < e) break;
        //��������������
        i++;
    }
    //���������� ��������
    return resExternal;
}

int main() {
    float x, e;
    printf("������� ����� x = ");
    scanf("%f", &x);
    printf("������� �������� e = ");
    scanf("%f", &e);
    printf("\n");
    double ans = byFor(x, e);
    int n = 5;
    printf("%.*lf", n, ans);
    
    return 0;
}