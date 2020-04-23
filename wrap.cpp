//
// Created by User on 22-Apr-20.
//

#include <boost/python.hpp>
#include "Some.h"

using namespace boost::python;

BOOST_PYTHON_MODULE( example )
{
    class_<Some>("Some")
        .def(init<int,std::string>(args("some_id", "name")))
        .def("ID", &Some::ID)
        .def( "Name", &Some::Name, return_value_policy<copy_const_reference>() );
}
