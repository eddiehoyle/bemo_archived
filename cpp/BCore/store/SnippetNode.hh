#ifndef BEMO_SNIPPET_HH
#define BEMO_SNIPPET_HH

#include <BCore/API.hh>
#include <BCore/Registry.hh>
#include <BCore/object/Node.hh>

//#include <pybind11/embed.h>

//namespace py = pybind11;

namespace bemo {

class SnippetNode : public Node< NodeType::Snippet > {
public:
    int execute() override {
        const std::string snippet = "sdf";
//        try {
//            py::exec( snippet );
//        } catch ( py::error_already_set& e ) {
//            BMO_ERROR << e.what();
//        }
        return -1;
    }
};


}

#endif // BEMO_SNIPPET_HH
