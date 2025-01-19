#pragma once
#include <stdlib.h>

typedef int8_t POS_T;

struct move_pos
{
    POS_T x, y;             // Начальная позиция
    POS_T x2, y2;           // Позиция куда перемещаем шашку
    POS_T xb = -1, yb = -1; // позиция битой шашки( приусловии что такая была, инициализируется со значением -1)

	// инициализирует начальные и конечные позиции. Позиции битой шашки остаются со значениями по умолчанию.
    move_pos(const POS_T x, const POS_T y, const POS_T x2, const POS_T y2) : x(x), y(y), x2(x2), y2(y2)
    {
    }
	// конструктор позволяет инициализировать все члены структуры, включая позиции битой шашки
    move_pos(const POS_T x, const POS_T y, const POS_T x2, const POS_T y2, const POS_T xb, const POS_T yb)
        : x(x), y(y), x2(x2), y2(y2), xb(xb), yb(yb)
    {
    }
	// Оператор == сравнивает два объекта move_pos и возвращает true, если все позиции (начальная и конечная) совпадают
    bool operator==(const move_pos &other) const
    {
        return (x == other.x && y == other.y && x2 == other.x2 && y2 == other.y2);
    }
    bool operator!=(const move_pos &other) const
    {
        return !(*this == other);
    }
};
