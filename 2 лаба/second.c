/******************************************************************************


                ##   ## ##### ###   ##### ####   ###  #       # 
                # # # # #     #  #  #     #   # #   #  #     #
                #  #  # ##### #   # ##### ####  #   #   #   #
                #     # #     #  #  #     #  #  #   #    # #
                #     # ##### ###   ##### #   #  ###      #


*******************************************************************************/

/*
    Вторая лаба - 29 вариант
    Условие: https://disk.yandex.ru/i/79ayTTUBS-CA4w
*/

#include <stdio.h>
#include <math.h>

//По циклу For
double byFor(float x, float e){
    //переменная считает сумму всего цикла
    double resExternal = 0;
    //переменная считает сумму внутреннего цикла
    double resInternal = 0;
    //переменная последнего элемента
    double lastElement = 0;
    //ставим бесконечный цикл
    for(int i = 1; i > 0; i++) {
        //чтобы при умножение получалось тоже число
        double temp = 1;
        //цикл от i до j
        for(int j = 1; j <= i; j++) {
            // делаем умножение, которое помогает нам жить ;)
            temp *= (powf(-1, j) + j);
            //проверка если цикла подходит к концу, то надо положить значения в переменную
            if(j == i) resInternal += temp;
        }
        //делаем сумму
        resExternal += (powf(x, i) + resInternal);
        //получаем последний элемент
        lastElement = powf(x, i) + resInternal;
        // делаем проверку на точность
        if(fabs(lastElement) < e) break;
    }
    //возвращаем значение
    return resExternal;
}

//По циклу While
double byWhile(float x, float e){
    //переменная считает сумму всего цикла
    double resExternal = 0;
    //переменная считает сумму внутреннего цикла
    double resInternal = 0;
    //переменная последнего элемента
    double lastElement = 0;
    //обьявляем переменную
    int i = 1;
    //ставим бесконечный цикл
    while(i > 0) {
        //чтобы при умножение получалось тоже число
        double temp = 1;
        //цикл от i до j
        for(int j = 1; j <= i; j++) {
            // делаем умножение, которое помогает нам жить ;)
            temp *= (powf(-1, j) + j);
            //проверка если цикла подходит к концу, то надо положить значения в переменную
            if(j == i) resInternal += temp;
        }
        //делаем сумму
        resExternal += (powf(x, i) + resInternal);
        //получаем последний элемент
        lastElement = powf(x, i) + resInternal;
        // делаем проверку на точность
        if(fabs(lastElement) < e) break;
        //инкрементируем
        i++;
    }
    //возвращаем значение
    return resExternal;
}

int main() {
    float x, e;
    printf("Введите число x = ");
    scanf("%f", &x);
    printf("Введите точность e = ");
    scanf("%f", &e);
    printf("\n");
    double ans = byFor(x, e);
    int n = 5;
    printf("%.*lf", n, ans);
    
    return 0;
}