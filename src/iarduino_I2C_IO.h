//	Библиотека для работы с Trema I2C расширителями выводов: http://iarduino.ru/shop/Expansion-payments/rasshiritel-na-8-vhodov-vyhodov-trema-modul.html
//  Версия: 1.1.3
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/285.html
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/page/rasshiritel-na-8-vhodov-vyhodov-trema-modul/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_I2C_IO_h														//
#define iarduino_I2C_IO_h														//
																				//
#if defined(ARDUINO) && (ARDUINO >= 100)										//
#include	<Arduino.h>															//
#else																			//
#include	<WProgram.h>														//
#endif																			//
																				//
#include	"iarduino_I2C_IO_I2C.h"												//	Подключаем библиотеку выбора реализации шины I2C.
																				//
#if defined(TwoWire_h) || defined(__ARDUINO_WIRE_IMPLEMENTATION__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega2560__) || defined(ESP8266) || defined(ESP32) || defined(ARDUINO_ARCH_RP2040) || defined(RENESAS_CORTEX_M4) // Если подключена библиотека Wire или платы её поддерживают...
#include	<Wire.h>															//	Разрешаем использовать библиотеку Wire в данной библиотеке.
#endif																			//
#if defined( iarduino_I2C_Software_h )											//	Если библиотека iarduino_I2C_Software подключена в скетче...
#include	<iarduino_I2C_Software.h>											//	Разрешаем использовать библиотеку iarduino_I2C_Software в данной библиотеке.
#endif																			//
																				//
#define		EXP_REG_INPUT	0													//	Адрес регистра порта входа						Запись в этот регистр игнорируется. Он отображает фактическое состояние логических уровней на входах, независимо от того как сконфигурированы выводы (вход/выхо) в регистре конфигурации выводов.
#define		EXP_REG_OUTPUT	1													//	Адрес регистра порта выхода						Устанавливает логический уровень на выходе, если он был сконфигурирован как выход в регистре конфигурации выводов. Если вывод сконфигурирован как вход, то данные этого регистра на него не влияют. Чтение значений из этого регистра вернёт установленное, а не фактическое состояние входа.
#define		EXP_REG_INVERT	2													//	Адрес регистра инверсии входов					Установленные биты регистра заставляют читать инверсное состояние входов.
#define		EXP_REG_CONFIG	3													//	Адрес регистра конфигурации выводов				Устанавливает направление работы выводов. 1-вход с высоким импендансом (по умолчанию), 0-выход.
																				//
class iarduino_I2C_IO{															//
	public:																		//
	/**	Конструктор класса **/													//
		iarduino_I2C_IO					(uint8_t k=0xFF  ){selI2C = new iarduino_I2C_Select; if(k>=0x20 && k<=0x27){EXP_uint_ADDRESS_OBJ=k;}}
	/**	пользовательские функции **/											//
		#if defined(TwoWire_h) || defined(__ARDUINO_WIRE_IMPLEMENTATION__)		//
		void	begin					(TwoWire* i=&Wire){selI2C->begin(i);}	//	Определяем функцию инициализации модуля								(Параметр:  объект для работы с аппаратной шиной I2C).
		#endif																	//
		#if defined(iarduino_I2C_Software_h)									//
		void	begin					(SoftTwoWire* i  ){selI2C->begin(i);}	//	Определяем функцию инициализации модуля								(Параметр:  объект для работы с программной шиной I2C).
		#endif																	//
		void	pinMode					(uint8_t, uint8_t);						//	Установка	режима работы вывода				(№ вывода, режим работы)
		bool	digitalRead				(uint8_t         );						//	Чтение		логического состояния на входе		(№ вывода              )
		void	digitalWrite			(uint8_t, bool   );						//	Установка	логического состояния на выходе		(№ вывода, состояние   )
		void	SetModeRegister			(uint8_t         );						//	Установка	режима работы всех выводов модуля	(байт режимов работы   )
		void	SetOutputRegister		(uint8_t         );						//	Установка	состояний на всех выходах модуля	(№ вывода, состояние   )
		uint8_t	GetInputRegister		(void            );						//	Чтение		состояний со всех входов модуля		(без параметров        )
	private:																	//
	/**	внутренние переменные **/												//
		iarduino_I2C_VirtualSelect*      selI2C;								//	Объявляем	указатель на объект полиморфного класса iarduino_I2C_VirtualSelect, но в конструкторе текущего класса этому указателю будет присвоена ссылка на производный класс iarduino_I2C_Select.
		uint8_t	EXP_uint_ADDRESS_OBJ  =	 0xFF;									//	адрес		модуля на шине I2C					(указанный при создании объекта)
		uint8_t	EXP_uint_ADDRESS      =	 0x20;									//	адрес		модуля на шине I2C					(реальный)
		uint8_t	EXP_uint_BIT          =	 0;										//	позиция		бита в модуле						(7-0)
		uint8_t	EXP_uint_COMMAND      =	 0;										//	команда		состоящая из адреса регистра		(0-3)
		uint8_t	EXP_uint_DATA         =	 0;										//	данные		для передачи по шине I2C
	/**	внутренние функции **/													//
		bool	EXP_func_FIND			(uint8_t,	uint8_t);					//	Поиск		переметров для передачи				(№ вывода,	адрес регистра)
};																				//
																				//
#endif																			//