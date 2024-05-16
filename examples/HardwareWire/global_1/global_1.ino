// УПРАВЛЕНИЕ ВЫВОДАМИ МОДУЛЯ СТАНДАРТНЫМИ ФУНКЦИЯМИ:       // Если номер вывода указан типом uint8_t, то функции управляют выводами платы Arduino.
// pinMode(), digitalWrite(), digitalRead()                 // Если номер вывода указан типом pinNum , то функции управляют выводами модуля.
                                                            //
// Расширитель GPIO на 8 Входов/Выходов (Trema-модуль):     // https://iarduino.ru/shop/Expansion-payments/rasshiritel-na-8-vhodov-vyhodov-trema-modul.html
// Информация о подключении модулей к шине I2C:             // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:               // https://wiki.iarduino.ru/page/rasshiritel-na-8-vhodov-vyhodov-trema-modul/
                                                            //
#include <Wire.h>                                           // Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_IO_Global.
#include <iarduino_I2C_IO_Global.h>                         // Подключаем библиотеку, разрешая использовать обычные функции для управления выводами модуля.
                                                            // При этом, адрес 1 модуля должен быть 0x20, следующего 0x21 и т.д.
                                                            // Тогда выводы 0-7 принадлежат 1 модулю, 8-15 второму и т.д.
                                                            // Номера выводов Arduino указываются типом uint8_t, а модулей типом pinNum.
uint8_t i=2;                                                // Создаём переменную i, с типом uint8_t, указывая ей 2 вывод arduino.
pinNum  j=2;                                                // Создаём переменную j, с типом pinNum , указывая ей 2 вывод модуля.
                                                            //
void setup(){                                               //
     iarduino_I2C_IO_Global.begin(&Wire); // &Wire1 ...     // Инициируем работу с расширителем выводов, указав ссылку на объект для работы с шиной I2C на которой находится расширитель (по умолчанию &Wire).
     pinMode(i,           OUTPUT);                          // Переводим 2 вывод arduino в режим выход.
     pinMode(j,           OUTPUT);                          // Переводим 2 вывод модуля  в режим выход.
     pinMode((uint8_t) 3, OUTPUT);                          // Переводим 3 вывод arduino в режим выход.
     pinMode((pinNum ) 3, OUTPUT);                          // Переводим 3 вывод модуля  в режим выход.
}                                                           //
                                                            //
void loop(){                                                //
     switch((millis()/1000)%8){                             // Значение в switch() меняется каждую секунду в пределах 0-7.
         case 0: digitalWrite(i,           HIGH); break;    // Устанавливаем на 2 выводе arduino, состояние логической  1.
         case 1: digitalWrite(i,           LOW ); break;    // Устанавливаем на 2 выводе arduino, состояние логического 0.
         case 2: digitalWrite(j,           HIGH); break;    // Устанавливаем на 2 выводе модуля , состояние логической  1.
         case 3: digitalWrite(j,           LOW ); break;    // Устанавливаем на 2 выводе модуля , состояние логического 0.
         case 4: digitalWrite((uint8_t) 3, HIGH); break;    // Устанавливаем на 3 выводе arduino, состояние логической  1.
         case 5: digitalWrite((uint8_t) 3, LOW ); break;    // Устанавливаем на 3 выводе arduino, состояние логического 0.
         case 6: digitalWrite((pinNum ) 3, HIGH); break;    // Устанавливаем на 3 выводе модуля , состояние логической  1.
         case 7: digitalWrite((pinNum ) 3, LOW ); break;    // Устанавливаем на 3 выводе модуля , состояние логического 0.
         default:                                 break;    //
     }                                                      //
}                                                           //