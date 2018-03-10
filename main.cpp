#include "Editor.h"

int main()
{

    Editor editor;
    editor.new_document();
    std::string circle_name = editor.add_shape( S_CIRCILE );
    std::string image_name = editor.add_shape( S_IMAGE );
    std::string square_name = editor.add_shape( S_SQUARE );

    editor.remove_shape( image_name );

    editor.export_document( "1.ai" );
    editor.import_document( "2.dxf" );

    return 0;
}