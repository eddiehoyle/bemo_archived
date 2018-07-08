//
// Created by Eddie Hoyle on 1/07/18.
//

#ifndef BEMO_VIEW_HH
#define BEMO_VIEW_HH

#include <QTreeWidget>

class Outliner : public QTreeWidget {

public:
    Outliner( QWidget* parent = nullptr );
    ~Outliner() = default;
};

#endif // BEMO_VIEW_HH
