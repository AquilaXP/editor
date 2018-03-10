#pragma once

#include <memory>
#include <map>

#include "IShape.h"

/*!
    Документ редактора
*/
class DocumentEditor
{
public:
    void add_shape( std::unique_ptr<IShape> p )
    {
        m_primitives.insert( std::make_pair( p->GetName(), std::move(p) ) );
    }
    void remove_shape( const std::string& name )
    {
        m_primitives.erase( name );
    }
private:
    std::map<std::string, std::unique_ptr<IShape>> m_primitives;
};