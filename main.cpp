#include <iostream>
#include <clocale>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int ans, size;
bool esc = false;
vector <int> vect;

void set_ans() {
    restart:
    cout << endl;
    cout << "Ваш ответ: ";
    cin >> ans;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ответ неверный :)" << endl;
        goto restart;
    }
    
}

void first (){
    if (size < 1) {
        cout << "У вас еще нет массива в этой программе, но сейчас мы это исправим..." << endl;
        goto create;
    }
    else {
        cout << "У вас уже есть массив, я думаю вы хотите изменить его" << endl;
        goto create;
    }
    
    create:
    cout << "Сначала вы должны выбрать размер для вашего массива (не советую делать слишком большой массив)" << endl;
    
    set_ans();
    size = ans;
    vect.reserve(size);
    
    cout << "Теперь у вас массив с " << size << " элементами " << endl;
    cout << endl;
    cout << "Думаю, будет нехорошо оставлять его путсым, верно ?" << endl;
    for (size_t i = 0; i < size; i++) {
        cout << i+1 << "-й элемент : ";
        set_ans();
        vect[i] = ans;
    }
    cout << endl;
    
    menu:
    cout << "Что делаем дальше?" << endl;
    cout << endl;
    cout << "1. Возвращаемся к главному меню." << endl;
    cout << "------------------------------------------------------------------"<< endl;
    cout << "2. (<-) Мне кажется я не правильно ввел массив, давай перезапишем." << endl;
    cout << "------------------------------------------------------------------"<< endl;
    cout << "3. (х) Выход из программы." << endl;
    cout << "------------------------------------------------------------------"<< endl;
    
    set_ans();
    
    switch(ans) {
        case 1:
            break;
        case 2:
            goto create;
            break;
        case 3:
            esc = true;
            break;
        default:
            cout << "Нет такого варианта ответа :)" << endl;
            goto menu;
    }
}

void second() {
    if (size < 1) {
        cout << "У Вас еще нет массива, Вам следует сначала создать его, перед тем как выводить" << endl;
        cout << endl;
    }
    else {
        for(size_t i = 0; i < size; i++) {
            cout << "Ваш массив : ";
            cout << vect[i] << " ";
        }
        cout << endl;
    }
    
}

void third() {
    int j, sum, sum1 = 0, n, el = 0;
    if (size < 1) {
        cout << "Не думаю что получится отсортировать пустоту :)" << endl;
    }
    else {
        cout << "Ну чтож, надо сортировать..." << endl;
    }
    cout << endl;
       
    for (size_t i = 0; i < size; i++) {
        sum = 0;
        el = abs(vect[i]);
        for (j = 0; el > 0 ; j++) {
            if (j % 2 == 0) {
                sum += el % 10;
                el /= 10;
            }
            else {
            el /= 10;
            }
        }
        el = abs(vect[i]);
        n = j;
        cout << n << " ";
        cout << " (" << sum << ") ";
        cout << vect[i] << "| ";
        
        
        sum1 = 0;
        if (n%2 == 0) {
            n--;
            for (; n > 1; n--) {
                if (n % 2 == 0) {
                    sum1 += el / pow(10, n);
                    el /= (pow(10, n));
                }
                else  {
                    el /= (pow(10,n));
                }
            }
            cout << " <" << sum1 << "> ";
        }
        if (n%2 == 1) {
            n = j - 1;
            for (; n > 1; n--) {
                if (n % 2 == 1) {
                    sum1 += el / pow(10, n);
                    el /= (pow(10, n));
                }
                else {
                    el /= (pow(10,n));
                }
            }
            cout << " <" << sum1 << "> ";
        }
        cout << n << " ";
        cout << " (" << sum1 << ") ";
        cout << vect[i] << "| ";
    }
    cout << endl;
}

    
//        for (size_t i = 0; i < size; i++) {
//            sum = 0;
//            for (j = 0; unsigned(vect[i]) > 0 ; j++) {
//                if (j % 2 == 0) {
//                    sum += unsigned(vect[i]) % 10;
//                    vect[i] /= 10;
//                }
//                else {
//                vect[i] /= 10;
//                }
//            }
//            cout << j << " ";
//            cout << " (" << sum << ") ";
//        }
//        cout << endl;
//}

void fourth() {
    
}

int main() {
    cout << "Приветствую тебя!" << endl;
    start:
    cout << "Для навигации в программе используй цифры с клавиатуры" << endl;
    cout << endl;
    cout << "1. Ввод массива" << endl;
    cout << "------------------------------------------------------------------"<< endl;
    cout << "2. Выввод массива в консоль" << endl;
    cout << "------------------------------------------------------------------"<< endl;
    cout << "3. Сортировка по сумме цифр" << endl;
    cout << "------------------------------------------------------------------"<< endl;
    cout << "4. Сортировка по возрастанию последней цифры" << endl;
    cout << "------------------------------------------------------------------"<< endl;
    cout << "5. (х) Выход из программы" << endl;
    cout << "------------------------------------------------------------------"<< endl;
    
    set_ans();
    
    switch(ans) {
        case 1:
            first();
            if (esc == true) {
                goto esc;
            }
            else {
                goto start;
            }
            break;
        case 2:
            second();
            if (esc == true) {
                goto esc;
            }
            else {
                goto start;
            }
            break;
        case 3:
            third();
            if (esc == true) {
                goto esc;
            }
            else {
                goto start;
            }
            break;
        case 4:
            fourth();
            break;
        case 5:
            goto esc;
        default:
            cout << "Нет такого ответа :)" << endl;
            goto start;
    }
    esc :
    return 0;
}
