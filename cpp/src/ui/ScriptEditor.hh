//
// Created by Eddie Hoyle on 1/07/18.
//

#ifndef BEMO_SCRIPTEDITOR_HH
#define BEMO_SCRIPTEDITOR_HH

#include <QTextEdit>

class ScriptEditor : public QTextEdit {

public:
    ScriptEditor( QWidget* parent = nullptr );
    ~ScriptEditor() = default;

};


#endif // BEMO_SCRIPTEDITOR_HH
