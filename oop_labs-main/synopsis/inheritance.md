# Наследование

## Таблица модификаторов доступа

<table>
<tbody><tr>
<td rowspan="2" width="112">
<p><span>Модификатор наследования</span></p></td>
<td colspan="3">
<p align="center"><span>Модификатор доступа</span></p></td></tr>
<tr>
<td style=" vertical-align:top;" width="112">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt;">public</span></p></td>
<td style=" vertical-align:top;" width="112">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt;">private</span></p></td>
<td style=" vertical-align:top;" width="112">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt;">protected</span></p></td></tr>
<tr>
<td style=" vertical-align:top;">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt;">public</span></p></td>
<td bgcolor="#7cfc00">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#7cfc00;">public</span></p></td>
<td bgcolor="#ff6347">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#ff6347;">private</span></p></td>
<td bgcolor="#4169e1">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#4169e1;">protected</span></p></td></tr>
<tr>
<td style=" vertical-align:top;">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt;">private</span></p></td>
<td bgcolor="#ff6347">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#ff6347;">private</span></p></td>
<td bgcolor="#ff6347">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#ff6347;">private</span></p></td>
<td bgcolor="#ff6347">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#ff6347;">private</span></p></td></tr>
<tr>
<td style=" vertical-align:top;">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt;">protected</span></p></td>
<td bgcolor="#4169e1">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#4169e1;">protected</span></p></td>
<td bgcolor="#ff6347">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#ff6347;">private</span></p></td>
<td bgcolor="#4169e1">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;" align="center"><span style=" font-size:13pt; background-color:#4169e1;">protected</span></p></td></tr></tbody></table>

## Множественное наследование

Можно сделать так, чтобы класс `C` наследовал класс `A` и класс `B`.

```cpp
class C : public A, public B
{
};
```

> NOTE: множественное наследование лучше не использовать.

## Абстрактный класс

Абстрактный класс - класс, который хотя бы имеет один полностью
виртуальный метод и не имеет определений (отсутсвтие реализации).

```cpp
class Abs
{
    virtual void method() = 0;
};
```

Объект этого класс не получится объявить, так как тело метода
отсутствует.

## Интерфейс

Интерфейс - абстрактный класс, в котором все методы виртуальны и нет
ни одного свойства.

Имена таких классов начинаются с быквы `I`.

Интерфейсы нужны для создания стандартных методов, что позволят
обрабатывать все объекты массива, унаследованных от
`IComparable` класса.

Интерфейс - один из патте'рнов проектирования.

## Примеры

- [простое наследование](examples/inheritance/ex1)
