// ПРИМЕР КОПИРУЕТ СОСТОЯНИЕ ВЫВОДОВ 4-7 НА ВЫВОДЫ 0-3:     //
                                                            //
// Расширитель GPIO на 8 Входов/Выходов (Trema-модуль):     // https://iarduino.ru/shop/Expansion-payments/rasshiritel-na-8-vhodov-vyhodov-trema-modul.html
// Информация о подключении модулей к шине I2C:             // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:               // https://wiki.iarduino.ru/page/rasshiritel-na-8-vhodov-vyhodov-trema-modul/
                                                            //
#include <Wire.h>                                           // Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_IO.
#include <iarduino_I2C_IO.h>                                // Подключаем библиотеку iarduino_I2C_IO для работы с модулем
iarduino_I2C_IO extIO(0x20);                                // Создаём объект extIO для работы с модулем, адрес которого указан в качестве параметра.
                                                            //
void setup(){                                               //
  extIO.begin(&Wire); // &Wire1, &Wire2 ...                 // Инициируем работу с расширителем выводов, указав ссылку на объект для работы с шиной I2C на которой находится расширитель (по умолчанию &Wire).
  extIO.pinMode(0, OUTPUT);                                 // Переводим 0 вывод модуля  в режим выход
  extIO.pinMode(1, OUTPUT);                                 // Переводим 1 вывод модуля  в режим выход
  extIO.pinMode(2, OUTPUT);                                 // Переводим 2 вывод модуля  в режим выход
  extIO.pinMode(3, OUTPUT);                                 // Переводим 3 вывод модуля  в режим выход
  extIO.pinMode(4, INPUT);                                  // Переводим 4 вывод модуля  в режим вход
  extIO.pinMode(5, INPUT);                                  // Переводим 5 вывод модуля  в режим вход
  extIO.pinMode(6, INPUT);                                  // Переводим 6 вывод модуля  в режим вход
  extIO.pinMode(7, INPUT);                                  // Переводим 7 вывод модуля  в режим вход
}                                                           //
                                                            //
void loop(){                                                //
  extIO.digitalWrite(0, extIO.digitalRead(4));              // Копируем состояние с 4 вывода на 0 вывод модуля
  extIO.digitalWrite(1, extIO.digitalRead(5));              // Копируем состояние с 5 вывода на 1 вывод модуля
  extIO.digitalWrite(2, extIO.digitalRead(6));              // Копируем состояние с 6 вывода на 2 вывод модуля
  extIO.digitalWrite(3, extIO.digitalRead(7));              // Копируем состояние с 7 вывода на 3 вывод модуля
}                                                           //