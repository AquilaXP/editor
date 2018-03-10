#pragma once

#include <memory>
#include <string>

#include "DocumentEditor.h"
#include "IShape.h"
#include "IFormat.h"

/*!
    Класс редактора
*/
class Editor
{
    std::unique_ptr<DocumentEditor> doc;
public:
    void new_document()
    {
        doc.reset( new DocumentEditor );
    }
    void import_document( const std::string& path )
    {
        auto f = GetFormat( GetExc( path ) );
        f->save_document( *doc, path );
    }
    void export_document( const std::string& path )
    {
        auto f = GetFormat( GetExc( path ) );
        f->load_document( *doc, path );
    }

    std::string add_shape( ID_Shape id )
    {
        auto shape = CreateShape( id );
        std::string name = shape->GetName();
        doc->add_shape( std::move( shape ) );
        std::cout << "Add shape with name: " << name << std::endl;
        return name;
    }
    void remove_shape( const std::string& name )
    {
        doc->remove_shape( name );
        std::cout << "Remove shape with name: " << name << std::endl;
    }
private:
    std::string GetExc( const std::string& path )
    {
        return path.substr( path.find_last_of( '.' ) + 1 );
    }
};