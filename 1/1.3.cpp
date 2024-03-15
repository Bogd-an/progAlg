// Завдання3. Створити квадратний масив розмірністю n та заповнити його числами за 
// допомогоюгенератора випадковихчисел значеннями в діапазоні [a ... b]. Результат 
// вивестина екран. 
// Всі елементи по діагоналях квадратного масиву прирівняти до 0, використовуючи 
// покажчики. Результат вивести на екран.

// Варіант a  b   m  n 
// 12      85 800 15 9 
// Операція з отриманим масивом
// Поміняти місцями максимальний і третій елементи.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int a = 85;
const int b = 800;
const int n = 9;

// Функція для генерації випадкового числа в діапазоні [a, b]
int generateRandomNumber() {
    return rand() % (b - a + 1) + a;
}

void coutArray(int array[][n]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned int>(time(0)));

    // Створення та заповнення масиву
    int array[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            array[i][j] = generateRandomNumber();
        }
    }

    // Вивід отриманого масиву
    cout << "Отриманий масив:\n";
    coutArray(array);

    // Оголошення та ініціалізація показчика
    int *ptr = &array[0][0];
    for (int i = 0; i < n; ++i) {
        // array[i][i] = 0;  // головна діагональ
        *(ptr + i * n + i) = 0;
        // array[i][n - i - 1] = 0;  // побічна діагональ
        *(ptr + i * n + (n - i - 1)) = 0;
    }

    // Виведення масиву після змін
    cout << "\nМасив після прирівнювання діагоналей до 0:\n";
    coutArray(array);

    // Поміняти місцями максимальний і третій елементи
    int maxElement = array[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (array[i][j] > maxElement) {
                maxElement = array[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Заміна максимального та третього елементів
    int temp = array[0][2];
    array[0][2] = maxElement;
    array[maxRow][maxCol] = temp;

    // Вивід масиву після обміну
    cout << "\nМасив після обміну:\n";
    coutArray(array);

    return 0;
}

// Приклад
// Отриманий масив:
// 685  97  753  592  361  448  115  782  754   
// 195  552  559  769  617  748  742  539  762  
// 354  416  432  374  729  544  416  524  205  
// 578  610  784  545  652  498  781  778  472  
// 446  266  544  320  705  130  168  666  604  
// 569  697  188  726  696  459  583  553  752  
// 297  174  617  651  542  274  505  444  306  
// 575  488  292  725  554  490  161  509  485  
// 363  686  456  289  627  503  788  219  730  

// Масив після прирівнювання діагоналей до 0:   
// 0  97  753  592  361  448  115  782  0       
// 195  0  559  769  617  748  742  0  762      
// 354  416  0  374  729  544  0  524  205      
// 578  610  784  0  652  0  781  778  472      
// 446  266  544  320  0  130  168  666  604    
// 569  697  188  0  696  0  583  553  752      
// 297  174  0  651  542  274  0  444  306  
// 575  0  292  725  554  490  161  0  485  
// 0  686  456  289  627  503  788  219  0  

// Масив після обміну:
// 0  97  788  592  361  448  115  782  0   
// 195  0  559  769  617  748  742  0  762  
// 354  416  0  374  729  544  0  524  205    
// 578  610  784  0  652  0  781  778  472    
// 446  266  544  320  0  130  168  666  604  
// 569  697  188  0  696  0  583  553  752    
// 297  174  0  651  542  274  0  444  306    
// 575  0  292  725  554  490  161  0  485    
// 0  686  456  289  627  503  753  219  0  