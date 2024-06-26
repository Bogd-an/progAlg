// Завдання 3. Реалізуйте програму, яка просить користувача ввести ціле число, а
// потім використовує рекурсивну функцію для виведення бінарного представлення
// цього числа. Передбачається, що число, яке запровадить користувач, є
// позитивним.
// Підказка : Використовуючи спосіб No1 для конвертації чисел із десяткової
// системи в двійкову, вам потрібно буде виводити біти «знизу вгору» (тобто у
// зворотному порядку), для цього ваш стейтмент виводу має бути після виклику
// рекурсії .

#include <iostream>
using namespace std;

// Рекурсивна функція для виведення бінарного представлення числа
void decimalToBinary(int n) {
    // Базовий випадок: якщо число 0, виводимо 0 та завершуємо рекурсію
    if (n == 0) {
        cout << 0;
        return;
    }
    // Рекурсивно виводимо біт у зворотньому порядку
    decimalToBinary(n / 2);
    // Виводимо останній біт (залишок від ділення на 2)
    cout << n % 2;
}

int main() {
    int num; // Введене користувачем число
    cout << "Int num: ";
    cin >> num;
    cout << "Bin num: ";
    decimalToBinary(num);
    cout << endl;
    return 0;
}

