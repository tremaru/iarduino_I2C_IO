//	Библиотека для работы с Trema I2C расширителями выводов: http://iarduino.ru/shop/Expansion-payments/rasshiritel-na-8-vhodov-vyhodov-trema-modul.html
//  Версия: 1.1.3
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/285.html
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/page/rasshiritel-na-8-vhodov-vyhodov-trema-modul/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел.
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef __IARDUINO_I2C_IO_GLOBAL_H__																										//
#define __IARDUINO_I2C_IO_GLOBAL_H__																										//
																																			//
	#include <iarduino_I2C_IO.h>																											//
	iarduino_I2C_IO iarduino_I2C_IO_Global;																									//
																																			//
//	Класс имитирующий переменные для указания номера вывода:																				//
class pinNum{																																//
	public:																																	//
		pinNum				 (int i=0){ num=i;  }																							//	Конструктор класса                          ( объект = a ).
		void	operator =   (int i  ){ num=i;  }																							//	Определяем функцию присвоения номера вывода ( объект = a ).
		void	operator ++  (int    ){ num++;  }																							//	Определяем функцию инкремента номера вывода ( объект++   ).
		void	operator --  (int    ){ num--;  }																							//	Определяем функцию декремента номера вывода ( объект--   ).
		void	operator +=  (int i  ){ num+=i; }																							//	Определяем функцию сложения   номера вывода ( объект+= a ).
		void	operator -=  (int i  ){ num-=i; }																							//	Определяем функцию вычитания  номера вывода ( объект-= a ).
		void	operator *=  (int i  ){ num*=i; }																							//	Определяем функцию умножения  номера вывода ( объект*= a ).
		void	operator /=  (int i  ){ num/=i; }																							//	Определяем функцию деления    номера вывода ( объект/= a ).
		void	operator %=  (int i  ){ num%=i; }																							//	Определяем функцию остатка    номера вывода ( объект%= a ).
		void	operator &=  (int i  ){ num&=i; }																							//	Определяем функцию И   для    номера вывода ( объект-= a ).
		void	operator |=  (int i  ){ num|=i; }																							//	Определяем функцию ИЛИ для    номера вывода ( объект-= a ).
		void	operator ^=  (int i  ){ num^=i; }																							//	Определяем функцию XOR для    номера вывода ( объект-= a ).
		void	operator <<= (int i  ){ num<<=i;}																							//	Определяем функцию сдвига     номера вывода ( объект-= a ).
		void	operator >>= (int i  ){ num>>=i;}																							//	Определяем функцию сдвига     номера вывода ( объект-= a ).
				operator int (){ return num;    }																							//	Определяем функцию получения  номера вывода ( a = объект ).
	private:																																//
		uint8_t	num = 0;																													//	Определяем внутреннюю переменную для хранения адреса модуля на шине I2C который был указан, но не был проверен.
};																																			//
																																			//
	#ifdef RENESAS_CORTEX_M4								//			Для плат Arduino UNO R4				(По состоянию на февраль 2024)	//
		void	pinMode				(pinNum i, PinMode j	){			iarduino_I2C_IO_Global.pinMode		((uint8_t)i,(uint8_t)j);}		//
		bool	digitalRead			(pinNum i				){ return	iarduino_I2C_IO_Global.digitalRead	((uint8_t)i           );}		//
		void	digitalWrite		(pinNum i, PinStatus j	){			iarduino_I2C_IO_Global.digitalWrite	((uint8_t)i,(uint8_t)j);}		//
	#else													//			Для остальных плат													//
		void	pinMode				(pinNum i, uint8_t j	){			iarduino_I2C_IO_Global.pinMode		((uint8_t)i,         j);}		//
		bool	digitalRead			(pinNum i				){ return	iarduino_I2C_IO_Global.digitalRead	((uint8_t)i           );}		//
		void	digitalWrite		(pinNum i, uint8_t j	){			iarduino_I2C_IO_Global.digitalWrite	((uint8_t)i,         j);}		//
	#endif																																	//
																																			//
#endif																																		//
