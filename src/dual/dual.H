/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2024 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::dual

Description

SourceFiles
    dualI.H
    dual.C
    dualIO.C

\*---------------------------------------------------------------------------*/

#ifndef dual_H
#define dual_H

#include "scalar.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class Istream;
class Ostream;

// Forward declaration of friend functions and operators
class dual;
Istream& operator>>(Istream&, dual&);
Ostream& operator<<(Ostream&, const dual&);


/*---------------------------------------------------------------------------*\
                          Class dual Declaration
\*---------------------------------------------------------------------------*/

class dual
:
    public baseClassName
{
    // Private Data

        //- Description of data_
        dataType data_;


    // Private Member Functions


public:

    // Static Data Members

        //- Static data staticData
        static const dataType staticData;


    // Constructors

        //- Construct null
        dual();

        //- Construct from components
        dual(const dataType& data);

        //- Construct from Istream
        dual(Istream&);

        //- Copy constructor
        dual(const dual&);

        //- Disallow default bitwise copy construction
        dual(const dual&) = delete;


    // Selectors

        //- Select null constructed
        static autoPtr<dual> New();


    //- Destructor
    ~dual();


    // Member Functions

        // Access

        // Check

        // Edit

        // Write


    // Member Operators

        void operator=(const dual&);

        //- Disallow default bitwise assignment
        void operator=(const dual&) = delete;


    // Friend Functions

    // Friend Operators

    // IOstream Operators

        friend Istream& operator>>(Istream&, dual&);
        friend Ostream& operator<<(Ostream&, const dual&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dualI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
