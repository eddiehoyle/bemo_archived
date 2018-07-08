//
// Created by Eddie Hoyle on 1/07/18.
//

#include "Window.hh"
#include "ScriptEditor.hh"
#include "Outliner.hh"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTreeWidgetItem>

#include <iostream>
#include <BCore/API.hh>
#include <BCore/Graph.hh>
#include <BCore/util/Log.hh>


Window::Window()
    : m_editor( nullptr ),
      m_outliner( nullptr ),
      m_py() {

    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout( widget );

    m_outliner = new Outliner();
    m_editor = new ScriptEditor();

    QPushButton* addNodeButton = new QPushButton( "add" );
    QPushButton* runScriptButton = new QPushButton( "run" );

    layout->addWidget( m_outliner );
    layout->addWidget( addNodeButton );
    layout->addWidget( m_editor );
    layout->addWidget( runScriptButton );

    setCentralWidget( widget );

    connect( addNodeButton, SIGNAL(clicked()), this, SLOT(addNode()));
    connect( runScriptButton, SIGNAL(clicked()), this, SLOT(execScript()));

    m_editor->setText(R"(import pybemo
mgr = pybemo.GraphManager()
graph = mgr.get_graph()
print "Python : There are %s Bemo(s) in graph." % (graph.get_count())
)");
}

void Window::addNode() {
    bemo::GraphManager* mgr = bemo::BMO_GraphManager;
    BMO_ERROR << "C++ : Got GraphManager=" << (void*)mgr;

    bemo::GraphPtr graph = mgr->get_graph();
    bemo::NodePtr node = bemo::create_node( "Penny" + std::to_string( graph->get_count() ) );
    graph->add( node );

    // Create new item (top level item)
    QTreeWidgetItem* item = new QTreeWidgetItem( m_outliner );
    m_outliner->addTopLevelItem(item);
    item->setText(0,QString( node->get_name().c_str() ));
}

void Window::execScript() {
    QString text = m_editor->toPlainText();
    try {
        py::exec( text.toStdString() );
    } catch ( py::error_already_set& e ) {
        std::cerr << e.what() << std::endl;
    }
}
