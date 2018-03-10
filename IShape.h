#pragma once

#include <string>

/// Генератор уникальных имен
std::string GetNewName()
{
    static int x = 0;
    std::string unique_name = "name_" + std::to_string( x );
    x++;
    return unique_name;
}

/*!
    Базовый класс примитивов
*/
class IShape
{
public:
    void SetName( const std::string& name )
    {
        m_name = name;
    }
    const std::string& GetName() const
    {
        return m_name;
    }
    virtual IShape* clone( const std::string& name )
    {
        return nullptr;
    }
    virtual std::string GetTypeShape() const = 0;
protected:
    std::string m_name;
};

/*!
    Примитив круг
*/
class Circile : public IShape
{
public:
    std::string GetTypeShape() const override
    {
        return "Circle";
    }
};

/*!
    Примитив квадрат
*/
class Square : public IShape
{
public:
    std::string GetTypeShape() const override
    {
        return "Square";
    }
};

/*!
    Примитив изображение
*/
class Image : public IShape
{
public:
    std::string GetTypeShape() const override
    {
        return "Image";
    }
};

/// Индификаторый всех возможных фигур, которые можно создать
enum ID_Shape
{
    S_CIRCILE = 1,
    S_SQUARE = 2,
    S_IMAGE = 3
};

std::unique_ptr<IShape> CreateShape( ID_Shape id )
{
    std::unique_ptr<IShape> p;
    switch( id )
    {
        case S_CIRCILE:
            p.reset( new Circile );
            break;
        case S_SQUARE:
            p.reset( new Square );
            break;
        case S_IMAGE:
            p.reset( new Image );
            break;
        default:
            break;
    }
    p->SetName( GetNewName() );
    return p;
}