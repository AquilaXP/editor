#pragma once

#include <iostream>
#include <string>

#include "DocumentEditor.h"

/*!
    Обобщеный класс формата
*/
class IFormat
{
public:
    virtual void save_document( const DocumentEditor& doc, const std::string& path ) = 0;
    virtual void load_document( DocumentEditor& doc, const std::string& path ) = 0;
};

class FormatAI : public IFormat
{
public:
    void save_document( const DocumentEditor& doc, const std::string& path ) override
    {
        std::cout << "Export to AI\n";
    }
    void load_document( DocumentEditor& doc, const std::string& path ) override
    {
        std::cout << "Import from AI\n";
    }
};

class FormatDXF : public IFormat
{
public:
    void save_document( const DocumentEditor& doc, const std::string& path ) override
    {
        std::cout << "Export to DXF\n";
    }
    void load_document( DocumentEditor& doc, const std::string& path ) override
    {
        std::cout << "Import from DXF\n";
    }
};

/// Создание класса для работы с форматом
std::unique_ptr<IFormat> GetFormat( const std::string& format )
{
    if( format == "ai" )
        return std::make_unique<FormatAI>();
    else if( format == "dxf" )
        return std::make_unique<FormatDXF>();
    return nullptr;
}