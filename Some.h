//
// Created by User on 22-Apr-20.
//

#ifndef _BOOST_C___PYTHON_SOME_H
#define _BOOST_C___PYTHON_SOME_H

#include <string>

using std::string;

class Some
{

public:
    Some();
    Some( int some_id, string const& name );
    static const int NOT_AN_IDENTIFIER = -1;

    static int ID() const;
    string const& Name() const;

    void ResetID();
    void ResetID( int some_id );

    void ChangeName( string const& name );

    void SomeChanges( int some_id, string const& name );

private:
    int mID;
    string mName;
};



#endif //_BOOST_C___PYTHON_SOME_H
